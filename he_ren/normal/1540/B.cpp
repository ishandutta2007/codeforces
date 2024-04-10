#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int mod = 1e9 + 7;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

const ll inv2 = (mod + 1) / 2;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN], etot = 0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

ll invn;
int f[MAXN][MAXN];

int ans = 0;
inline void upd_ans(vector<int> vec)
{
	for(int i=0; i+1<(int)vec.size(); ++i)
		vec[i] -= vec[i+1];
	
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int lef = i, rig = (int)vec.size() - i - 1;
		ans = (ans + (ll)invn * vec[i] %mod * f[lef][rig]) %mod;
	}
}

int siz[MAXN];
void dfs_siz(int u,int fa)
{
	siz[u] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_siz(v,u);
		siz[u] += siz[v];
	}
}

void dfs_ans(int u,int fa,int rt)
{
	static int sta[MAXN], tp = 0;
	sta[++tp] = siz[u];
	if(u < rt) upd_ans(vector<int>(sta+1, sta+tp+1));
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_ans(v, u, rt);
	}
	
	--tp;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i) f[0][i] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			f[i][j] = (ll)inv2 * (f[i-1][j] + f[i][j-1]) %mod;
	invn = pw(n, mod - 2);
	
	for(int i=1; i<=n; ++i)
		dfs_siz(i, 0), dfs_ans(i, 0, i);
	
	printf("%d",ans);
	return 0;
}