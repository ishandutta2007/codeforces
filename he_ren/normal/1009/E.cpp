#include<cstdio>
const int MAXN = 1e6 + 5;
const int mod = 998244353;
typedef long long ll;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int a[MAXN];
int sum[MAXN],f[MAXN],g[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1],
		add_mod(sum[i],a[i]);
	for(int i=1; i<=n; ++i)
		g[i] = ((ll)(g[i-1]<<1)+sum[i-1]) %mod;
	
	int now=0;
	for(int i=1; i<=n; ++i)
	{
		f[i] = ((ll)now+g[i]+sum[i]) %mod;
		add_mod(now,f[i]);
	}
	printf("%d",f[n]);
	return 0;
}