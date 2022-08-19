#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map> 
#define maxn 200005
#define mod 1000000007
#define ll long long
using namespace std;
int pw[maxn];
map <int, int> id[2];
int fa[maxn], sz[maxn];
int flag[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
void lk(int a, int b)
{
	int afa = gfa(a), bfa = gfa(b);
	if(afa == bfa) flag[afa] = 0;
	else
		fa[afa] = bfa, sz[bfa] += sz[afa], flag[bfa] &= flag[afa];
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n * 2; i++)
		fa[i] = i, flag[i] = 1, sz[i] = 1;
	pw[0] = 1;
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2, pw[i] %= mod;
	int idcnt[2] = {1, n + 1};
	for(int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(!id[0][x]) id[0][x] = idcnt[0]++;
		if(!id[1][y]) id[1][y] = idcnt[1]++;
		lk(id[0][x], id[1][y]);
	}	
	ll ans = 1;
	for(int i = 1; i < idcnt[0]; i++)
		if(fa[i] == i)
		{
			if(flag[i]) ans *= (pw[sz[i]] - 1), ans %= mod;
			else ans *= pw[sz[i]], ans %= mod;
		}
	for(int i = n + 1; i < idcnt[1]; i++)
		if(fa[i] == i)
		{
			if(flag[i]) ans *= (pw[sz[i]] - 1), ans %= mod;
			else ans *= pw[sz[i]], ans %= mod;
		}
	printf("%I64d\n", ans);

	return 0;
 }