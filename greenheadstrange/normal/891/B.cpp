#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 25
using namespace std;
int n;
struct th
{
	int a, pl;
	bool operator < (const th &x)const
	{
		return a < x.a;
	}
}p[maxn];
int id[maxn], num[maxn];
int main() 
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		p[i].pl = i, scanf("%d", &p[i].a);
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++)
		num[i] = p[i].a, 
		id[p[i].pl] = i;
	for(int i = 1; i <= n; i++)
	{
		int nid = id[i] + 1;
		if(nid > n) nid = 1;
		printf("%d ", num[nid]);
	}
	 
	return 0;
}