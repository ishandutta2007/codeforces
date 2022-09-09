#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

inline ll rnd(void){ return ((ll)rand()<<45) | ((ll)rand()<<30) | (rand()<<15) | rand();}

bool isnp[MAXN];
int pri[MAXN], pcnt = 0;
ll val[MAXN];
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i])
		{
			pri[++pcnt] = i;
			val[i] = rnd();
		}
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=n; ++j)
		{
			isnp[i*pri[j]] = 1;
			val[i*pri[j]] = val[i] ^ val[pri[j]];
			if(!(i%pri[j])) break;
		}
	}
	for(int i=2; i<=n; ++i) val[i] ^= val[i-1];
}

inline void get_res(int n)
{
	ll s = 0;
	for(int i=1; i<=n; ++i) s ^= val[i];
	if(s == 0)
	{
		printf("%d\n",n);
		for(int i=1; i<=n; ++i) printf("%d ",i);
		exit(0);
	}
	for(int i=1; i<=n; ++i)
		if(val[i] == s)
		{
			printf("%d\n",n-1);
			for(int j=1; j<=n; ++j)
				if(j != i) printf("%d ",j);
			exit(0);
		}
	
	static pair<ll,int> p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = {val[i], i};
	sort(p+1,p+n+1);
	
	for(int i=1; i<=n; ++i)
	{
		ll need = s ^ val[i];
		int pos = lower_bound(p+1,p+n+1, make_pair(need, 0)) - p;
		if(pos<=n && p[pos].first == need)
		{
			printf("%d\n",n-2);
			for(int j=1; j<=n; ++j)
				if(j != i && j != p[pos].second)
					printf("%d ",j);
			exit(0);
		}
	}
}

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	sieve(MAXN - 1);
	
	int n;
	scanf("%d",&n);
	
	get_res(n);
	get_res(n-1);
	return 0;
}