#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;
const int mod = 1e9 + 7;

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

char s[MAXN][MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	int cnt = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j] == '0') ++cnt;
	
	int ans = pw(2, n * m - cnt);
	if(!cnt) add_mod(ans, mod-1);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}