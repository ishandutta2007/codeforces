#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxw 31
#define maxn 4000000 
using namespace std;
int ch[maxn][2], size[maxn];
int root = 1;
int cnt = 2;
int num[maxw];
void ins(int x, int t)
{
	for(int i = 0; i < maxw; i++) num[i] = (x & 1), x >>= 1;
	int npl = root;
	size[root] += t;
	for(int i = maxw - 1; i >= 0; i--)
	{
		if(!ch[npl][num[i]]) ch[npl][num[i]] = cnt++; 	
		npl = ch[npl][num[i]];
		size[npl] += t;
	}
}
int xz[maxw];
int query(int x, int l)
{
	for(int i = 0; i < maxw; i++)
		xz[i] = (l & 1), num[i] = (x & 1), 
		l >>= 1, x >>= 1;
	int npl = root;
	int ans = 0;
	for(int i = maxw - 1; i >= 0; i--) 
	{
		if(!npl) break;
		if(xz[i]) ans += size[ch[npl][num[i]]], npl = ch[npl][!num[i]];
		else npl = ch[npl][num[i]];
	}
//	ans += size[npl];
	return ans;
}
int main()
{
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int t, n, l;
		scanf("%d%d", &t, &n);
		if(t == 1) ins(n, 1);
		else if(t == 2) ins(n, -1);
		else scanf("%d", &l), printf("%d\n", query(n, l));
	}
	return 0;
 }