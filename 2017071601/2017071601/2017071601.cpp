/*
1015德才论
最后cout提交超时
printf提交正确通过
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int name;
	int de;
	int cai;
};
bool cmp(node a, node b) {
	if (a.de + a.cai != b.de + b.cai) {
		return a.de + a.cai > b.de + b.cai;
	}//总分不同则按总分降序排序，总分相同则看德分
	else {
		if (a.de != b.de) {
			return a.de > b.de;
		}//德分不同则按德分降序排序
		else {
			if (a.name>b.name)
				return 0;//德分相同则按准考证号升序排序
			else
				return 1;
		}
	}
}
int main() {
	int n;
	int l, h, count = 0;
	int i;
	node temp;
	vector<node> v1, v2, v3, v4;
	while (scanf_s("%d %d %d", &n, &l, &h) != EOF) {
		for (i = 0; i < n; i++) {
			cin >> temp.name >> temp.de >> temp.cai;
			if (temp.de >= l&&temp.cai >= l) {
				count++;
				if (temp.de >= h&&temp.cai >= h)
					v1.push_back(temp);
				else if (temp.de >= h&&temp.cai< h)
					v2.push_back(temp);
				else if (temp.de < h&&temp.cai < h&&temp.de >= temp.cai)
					v3.push_back(temp);
				else
					v4.push_back(temp);
			}
		}
		cout << count << endl;
		sort(v1.begin(), v1.end(), cmp);
		sort(v2.begin(), v2.end(), cmp);
		sort(v3.begin(), v3.end(), cmp);
		sort(v4.begin(), v4.end(), cmp);
		for (i = 0; i < (int)v1.size(); i++)
			//特别注意使用cout输出会超时
			//cout << v1[i].name << ' ' << v1[i].de << ' ' << v1[i].cai << endl;
			printf("%d %d %d\n", v1[i].name, v1[i].de, v1[i].cai);
		for (i = 0; i <(int)v2.size(); i++)
			printf("%d %d %d\n", v2[i].name, v2[i].de, v2[i].cai);
		for (i = 0; i <(int)v3.size(); i++)
			printf("%d %d %d\n", v3[i].name, v3[i].de, v3[i].cai);
		for (i = 0; i <(int)v4.size(); i++)
			printf("%d %d %d\n", v4[i].name, v4[i].de, v4[i].cai);
		return 0;
	}
}