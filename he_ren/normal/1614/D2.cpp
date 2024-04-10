#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int maxa = 2e7;
const int MAXA = maxa + 5;
const int MAXP = 1.3e6 + 5;

int pri[MAXP], pcnt = 0;
bool isnp[MAXA];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i;
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=n; ++j)
		{
			isnp[i*pri[j]]=1;
			if(!(i%pri[j])) break;
		}
	}
}

int a[MAXN];

int tot[MAXA];
ll f[MAXA];

int main(void)
{
	sieve(MAXA);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		++tot[a[i]];
	
	for(int i=1; i<=pcnt; ++i)
	{
		int x = pri[i];
		for(int j=maxa/x; j>=1; --j)
			tot[j] += tot[j*x];
	}
	
	ll ans = 0;
	for(int i=maxa; i>=1; --i) if(tot[i])
	{
		f[i] = (ll)tot[i] * i;
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=maxa; ++j)
		{
			int k = i*pri[j];
			f[i] = max(f[i], f[k] + (ll)(tot[i] - tot[k]) * i);
		}
		ans = max(ans, f[i]);
	}
	
	printf("%lld",ans);
	return 0;
}