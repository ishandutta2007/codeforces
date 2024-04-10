#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXA = 2e7 + 5;
const int MAXP = 1.3e6 + 5;

bool isnp[MAXA];
int pri[MAXP], pcnt = 0, f[MAXA];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	f[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i, f[i] = 2;
		for(int j=1; j<=pcnt && (ll)i*pri[j] <= n; ++j)
		{
			int x = i * pri[j];
			isnp[x] = 1;
			if(i%pri[j]) f[x] = f[i] << 1;
			else{ f[x] = f[i]; break;}
		}
	}
}

void solve(void)
{
	int c,d,x;
	scanf("%d%d%d",&c,&d,&x);
	
	ll ans = 0;
	for(int i=1; i*i<=x; ++i) if(x%i == 0)
	{
		int y = x / i + d;
		if(y%c == 0) ans += f[y/c];
		if(i*i != x)
		{
			y = i + d;
			if(y%c == 0) ans += f[y/c];
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	sieve(MAXA-1);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}