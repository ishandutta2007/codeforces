#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXD = 5e3 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int a[MAXN];
int f[MAXN][MAXD];
ll g[MAXN];

int main(void)
{
	int n,d,Q;
	scanf("%d%d%d",&n,&d,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) f[i][0] = 1;
	for(int k=1; k<=d; ++k)
		for(int i=1; i<=n; ++i)
			f[i][k] = (f[i-1][k-1] + f[i+1][k-1]) %mod;
	
	for(int i=1; i<=n; ++i)
		for(int k=0; k<=d; ++k)
			g[i] = (g[i] + (ll)f[i][k] * f[i][d-k]) %mod;
	
	ll ans = 0;
	for(int i=1; i<=n; ++i) ans = (ans + g[i] * a[i]) %mod;
	while(Q--)
	{
		int pos,x;
		scanf("%d%d",&pos,&x);
		ans = (ans + mod - g[pos] * a[pos] %mod) %mod;
		a[pos] = x;
		ans = (ans + g[pos] * a[pos]) %mod;
		printf("%lld\n",ans);
	}
	return 0;
}