#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e5 + 5;
const int lb = 30;
const int LB = lb + 2;
const int MAXP = MAXN * LB;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll pw2[MAXN];

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int d;
int son[MAXP][2], siz[MAXP], pcnt = 1;
void insert(int x)
{
	int u = 1; ++siz[u];
	for(int i=lb; i>=0; --i)
	{
		int &v = son[u][bdig(x, i)];
		if(v == 0) v = ++pcnt;
		u = v; ++siz[u];
	}
}

int getres0(int,int,int);
int getres1(int u,int v,int dep)
{
	if(u == 0 || v == 0) return 0;
	if(dep == -1) return (ll)(pw2[siz[u]] - 1 + mod) * (pw2[siz[v]] - 1 + mod) %mod;
	if(bdig(d, dep) == 0)
	{
		return (getres1(son[u][0], son[v][0], dep-1)
			+ getres1(son[u][1], son[v][1], dep-1)) %mod;
	}
	
	ll res = (ll)getres0(son[u][0], son[v][1], dep-1)
		* getres0(son[u][1], son[v][0], dep-1) %mod;
	res = (res - pw2[siz[u]] - pw2[siz[v]] + 1) %mod;
	if(res < 0) res += mod;
	return res;
}
int getres0(int u,int v,int dep)
{
	return ((ll)getres1(u,v,dep) + pw2[siz[u]] + pw2[siz[v]] - 1 + mod) %mod;
}

int ans = 0;
void dfs_ans(int u,int dep)
{
	if(u == 0) return;
	if(dep == -1)
	{
		ans = ((ll)ans + pw2[siz[u]] - 1 + mod) %mod;
		return;
	}
	if(bdig(d, dep) == 0)
	{
		dfs_ans(son[u][0], dep-1);
		dfs_ans(son[u][1], dep-1);
	}
	else
	{
		ans = ((ll)ans + getres0(son[u][0], son[u][1], dep-1) - 1 + mod) %mod;
	}
}

int a[MAXN];

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	
	int n;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) insert(a[i]);
	
	dfs_ans(1,30);
	printf("%d",ans);
	return 0;
}