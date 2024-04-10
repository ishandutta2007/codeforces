#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int MAXM = 1e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

bool isnp[MAXM];
int pri[MAXM], pcnt = 0, mu[MAXM];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	mu[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i, mu[i] = -1;
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=n; ++j)
		{
			isnp[i*pri[j]] = 1;
			if(i%pri[j]) mu[i*pri[j]] = -mu[i];
			else{ mu[i*pri[j]] = 0; break;}
		}
	}
}

int n,m;
int a[MAXN], b[MAXN];
int f[MAXN][MAXM];

inline int get_res(void)
{
	for(int i=0; i<=m; ++i) f[0][i] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=m; ++j)
		{
			int lef = j - b[i], rig = j - a[i];
			lef = max(lef, 0);
			if(lef > rig) f[i][j] = 0;
			else
			{
				f[i][j] = f[i-1][rig];
				if(lef) add_mod(f[i][j], mod - f[i-1][lef-1]);
			}
			if(j) add_mod(f[i][j], f[i][j-1]);
		}
	return f[n][m];
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	sieve(m);
	ll ans = 0;
	for(int i=1; i<=m; ++i) if(mu[i] != 0)
	{
		static int ta[MAXN], tb[MAXN], tm;
		memcpy(ta, a, (n+1)<<2); memcpy(tb, b, (n+1)<<2);
		tm = m;
		
		m /= i;
		bool ok = 1;
		for(int j=1; j<=n; ++j)
		{
			a[j] = (a[j] + i - 1) / i;
			b[j] /= i;
			if(a[j] > b[j]){ ok = 0; break;}
		}
		if(ok) ans = (ans + mu[i] * get_res()) %mod;
		
		memcpy(a, ta, (n+1)<<2); memcpy(b, tb, (n+1)<<2);
		m = tm;
	}
	if(ans < 0) ans += mod;
	
	printf("%lld",ans);
	return 0;
}