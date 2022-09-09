#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 11 + 5;
const int MAXM = 11 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

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

ll fac[MAXD], inv[MAXD];

const int mxd = 11, mxm = 11;
int f[MAXD][MAXD][MAXM];

int p[MAXD], vis[MAXD];
void dfs(int len,int cmx,int cd,int cm)
{
	for(int i=1; i<=mxd+1; ++i) if(!vis[i])
	{
		int nmx = max(cmx, i), nd = cd, nm = cm;
		if(len > 1 && p[len-1] > i) ++nm;
		for(int j=1; j<len && nd<=mxd; ++j)
			if(p[j] > i) ++nd;
		
		if(nd <= mxd && nm <= mxm)
		{
			p[len] = i;
			vis[i] = 1;
			if(nmx > len) dfs(len+1, nmx, nd, nm);
			else if(len > 1) ++f[len][nd][nm];
			vis[i] = 0;
		}
	}
}

const int mxn = mxd * 2;
int g[MAXD][MAXD * 2][MAXD][MAXM];

void solve(void)
{
	int n,d,m;
	scanf("%d%d%d",&n,&d,&m);
	
	static int downp[MAXD][MAXD];
	for(int i=0; i<=d; ++i)
	{
		downp[i][0] = 1;
		for(int j=1; j<=d; ++j)
			downp[i][j] = (ll)downp[i][j-1] * (n-i-j+1) %mod;
	}
	
	int ans = 0;
	for(int i=1; i<=d; ++i)
		for(int j=i; j<=d*2 && j<=n; ++j) if(g[i][j][d][m])
		{
			assert(j-i <= d);
			ans = (ans + (ll)g[i][j][d][m] * downp[j-i][i] %mod * inv[i]) %mod;
		}
	printf("%d\n",ans);
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXD; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXD-1] = pw(fac[MAXD-1], mod-2);
	for(int i=MAXD-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	dfs(1, 0, 0, 0);
	
	g[0][0][0][0] = 1;
	for(int i=0; i<mxd; ++i)
	{
		for(int x=0; x<mxn; ++x)
		for(int y=0; y<mxd; ++y)
		for(int z=0; z<mxm; ++z) if(g[i][x][y][z])
			for(int xx=2; x+xx<=mxn && xx<=mxd+1; ++xx)
			for(int yy=xx-1; y+yy<=mxd; ++yy)
			for(int zz=1; z+zz<=mxm; ++zz)
				add_mod(g[i+1][x+xx][y+yy][z+zz], (ll)g[i][x][y][z] * f[xx][yy][zz] %mod);
	}
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}