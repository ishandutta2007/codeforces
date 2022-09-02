//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
ll bik[100005];
int n,m;
ll a;
vector<ll>mo,bi;
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d%d%lld",&n,&m,&a);
	for(int i=1;i<=n;i++)
	{
		ll s; scanf("%lld",&s);
		mo.pb(s);
	}
	for(int i=1;i<=m;i++)
	{
		ll s; scanf("%lld",&s);
		bi.pb(s);
	}
	sort(mo.begin(),mo.end(),greater<ll>());
	sort(bi.begin(),bi.end());
	for(int i=1;i<=m;i++) bik[i]=bik[i-1]+bi[i-1];
	int lb=0,ub=min(n,m)+1;
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		ll gen=0LL;
		for(int i=0;i<mid;i++)
		{
			if(mo[i]<bi[mid-1-i])
			{
				gen+=(bi[mid-1-i]-mo[i]);
			}
		}
		if(gen<=a) lb=mid;
		else ub=mid;
	}
	if(lb==0)
	{
		puts("0 0"); return 0;
	}
	else
	{
		lb=min(lb,min(m,n));
		printf("%d %lld\n",lb,max(0LL,bik[lb]-a));
	}
}