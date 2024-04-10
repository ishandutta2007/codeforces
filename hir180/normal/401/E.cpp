//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
vector<ll>di[150005];
ll n,m,l,r,mod;
ll calc(ll lb,ll ub,ll mul)
{
	ub=ub/mul; lb=(lb+mul-1)/mul;
	ll sum=(ub-lb+1LL)*(m+1);
	sum-=(ub*(ub+1)-(lb-1)*lb)/2*mul;
	sum=(sum%mod+mod)%mod;
	return sum;
}
int main()
{
	scanf("%lld %lld %lld %lld %lld",&n,&m,&l,&r,&mod);
	ll lb=l,ub=r;
	for(int i=2;i<=150000;i++)
	{
		if(!di[i].empty()) continue;
		for(int j=i;j<=150000;j+=i)
		{
			di[j].pb(i);
		}
	}
	ll ret=0LL;
	for(ll i=1;i<=min(n,r);i++)
	{
		while(lb>1 && l*l-i*i<=(lb-1)*(lb-1)) lb--;
		while(r*r-i*i<ub*ub) ub--;
		if(lb<=ub && lb<=m)
		{
			ll res=0;
			int mask=(1<<(di[i].size()));
			for(int j=0;j<mask;j++)
			{
				ll mul=1;
				int flag=1;
				for(int k=0;k<di[i].size();k++)
				{
					if(((j>>k)&1))
					{
						mul*=di[i][k];
						flag*=(-1);
					}
				}
				res+=flag*calc(lb,min(ub,m),mul);
			}
			ret=(ret+res*(n-i+1))%mod; ret=(ret+mod)%mod;
		}
	}
	if(l<=1&&1<=r) ret=(ret*2LL+n*(m+1)+m*(n+1))%mod;
	else ret=(ret*2LL)%mod;
	cout << ret << endl;
}