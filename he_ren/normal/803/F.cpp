#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXA = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;

int a[MAXN],t[MAXA],f[MAXA],g[MAXA];
int pw[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	for(int i=1; i<=n; ++i) ++t[a[i]];
	
	pw[0]=1;
	for(int i=1; i<=n; ++i) pw[i] = ((ll)pw[i-1]<<1ll)%mod;
	for(int i=1; i<=a[n]; ++i)
	{
		for(int j=i; j<=a[n]; j+=i)
		{
			f[i]+=t[j];
			if(f[i]>=mod) f[i]-=mod;
		}
		f[i] = pw[f[i]]-1;
		if(f[i]<0) f[i]+=mod;
	}
	
	for(int i=a[n]; i>=1; --i)
	{
		g[i]=f[i];
		for(int j=i*2; j<=a[n]; j+=i)
		{
			g[i]-=g[j];
			if(g[i]<0) g[i]+=mod;
		}
	}
	
	printf("%d",g[1]);
	return 0;
}