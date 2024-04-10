#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 14 + 5;
const int ALL = (1<<14) + 5;
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

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int num1[ALL];

int n;
int a[MAXN], prob[MAXN][MAXN];
int g[MAXN][ALL];

inline int calc(int mask1,int mask2)
{
	int res = 1;
	for(int i=1; i<=n; ++i) if(bdig(mask1, i-1))
		res = (ll)res * g[i][mask2] %mod;
	return res;
}

int main(void)
{
	for(int i=1; i<ALL; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(i != j)
			prob[i][j] = (ll)a[i] * pw(a[i] + a[j], mod - 2) %mod;
	
	int all = (1<<n) - 1;
	
	for(int i=1; i<=n; ++i)
		for(int mask=0; mask<=all; ++mask)
		{
			g[i][mask] = 1;
			for(int j=1; j<=n; ++j) if(bdig(mask, j-1))
				g[i][mask] = (ll)g[i][mask] * prob[i][j] %mod;
		}
	
	int ans = 0;
	static int f[MAXN][ALL];
	for(int mask=0; mask<=all; ++mask)
	{
		for(int i=1; i<=n; ++i) f[i][mask] = 1;
		for(int mask2=mask; mask2; mask2=(mask2-1)&mask) if(mask2 != mask && mask2)
		{
			int k = calc(mask ^ mask2, mask2), tmp = mask & mask2;
			for(int u=1; u<=n; ++u) if(bdig(tmp, u-1))
				add_mod(f[u][mask], mod - (ll)f[u][mask2] * k %mod);
		}
	}
	
	for(int i=1; i<=n; ++i)
		add_mod(ans, f[i][all]);
	
	printf("%d",ans);
	return 0;
}