#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using ll = long long;
const int MOD=998244353;
const int MC=500;

int Q, c[MC][MC];
ll D, u, v;
std::vector<ll> pr;
ll solve(std::vector<int>& a)
{
	ll f=1;
	int l=0;
	for(int x:a)
		f=f*c[l+=x][x]%MOD;
	return f;
}
std::vector<int> a,b;

int main(void)
{
	for(int i=0;i<MC;++i)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}
	scanf("%lld", &D);
	for(int i=2;(ll)i*i<=D;++i)
	{
		if(D%i==0)
			pr.push_back(i);
		while (D%i==0) D/=i;
	}
	if(D>1)
		pr.push_back(D);
	scanf("%d", &Q);
	for(int i=0;i<Q;++i)
	{
		scanf("%lld%lld", &u, &v);
		for(ll j:pr)
		{
			int x=0,y=0;
			while(u%j==0)u/=j, ++x;
			while(v%j==0)v/=j, ++y;
			if(x>y) a.push_back(x-y);
			else b.push_back(y-x);
		}
		printf("%lld\n", solve(a)*solve(b)%MOD);
		a.clear(), b.clear();
	}
	return 0;
}