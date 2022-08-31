#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define maxn 100005
#define ll long long
using namespace std;
int n;
int a[maxn];
int bg[maxn], eq[maxn]; // k
int cnt[maxn]; 
vector <int> pl[maxn];
int d[maxn];
int lb(int a)
{
	return a & (-a);
}
void add(int pl)
{
	while(pl < maxn)
		d[pl]++, pl += lb(pl);
}
int q(int pl)
{
	int ans = 0;
	while(pl)
		ans += d[pl], pl -= lb(pl);
	return ans;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		cnt[a[i]]++, 
		pl[a[i]].push_back(i), 
		eq[i] = cnt[a[i]], 
		add(a[i]), 
		bg[i] = i - q(a[i]);
	for(int i = 1; i < maxn; i++)
		cnt[i] += cnt[i - 1];
	ll ans = 0;		
	int npl = 0;
	for(int i = 1; i <= 100000; i++)
	{
		if(!pl[i].size()) continue;
		int ed = 0;
		if(pl[i][0] < npl)
		{
			int l = 0, r = pl[i].size() - 1;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if(pl[i][mid + 1] < npl) l = mid + 1;
				else r = mid;
			}
			ed = pl[i][l];
 		}
 		else
 			ed = pl[i][pl[i].size() - 1];
 		if(ed > npl) ans += (bg[ed] + eq[ed]) - bg[npl];
 		else ans += (bg[ed] + eq[ed] - bg[npl]) + (n - cnt[i - 1]);
 		npl = ed;
	}
	printf("%I64d\n", ans);
	return 0;
} 
/*
3
0
2
1
0
1
2
*/