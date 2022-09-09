#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 1e5 + 5;

int p[MAXD], pcnt = 0;
bool isnp[MAXD];
inline void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) p[++pcnt] = i;
		for(int j=1; j<=pcnt && (ll)i * p[j] <= n; ++j)
		{
			isnp[i*p[j]] = 1;
			if(!(i%p[j])) break;
		}
	}
}

inline int calc(int x){ return *lower_bound(p+1,p+pcnt+1,x);}

void solve(void)
{
	int d;
	scanf("%d",&d);
	
	int x = calc(d+1), y = calc(x+d);
	printf("%lld\n",(ll)x*y);
}

int main(void)
{
	sieve(MAXD-1);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}