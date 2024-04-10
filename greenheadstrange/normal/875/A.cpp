#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 200005
using namespace std;
int ans[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = n - 100; i <= n; i++)
	{
		int nm[10];
		int ns = i;
		for(int j = 0; j < 10; j++)
			nm[j] = ns % 10, ns /= 10;
		ns = i;
		for(int j = 0; j < 10; j++)
			ns += nm[j];
		if(ns == n) 
			ans[cnt++] = i;
	}
	printf("%d\n", cnt);
	for(int j = 0; j < cnt; j++)
		printf("%d\n", ans[j]);
		
	return 0;
 }