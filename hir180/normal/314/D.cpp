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
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
P za[1000005]; int n;
ll premin[100005],sufmin[100005];
ll premax[100005],sufmax[100005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		za[i]=mp(x-y,x+y);
	}
	sort(za,za+n);
	for(int i=0;i<n;i++)
	{
		if(i) premin[i]=min(premin[i-1],za[i].s);
		else premin[i]=za[i].s;

		if(i) premax[i]=max(premax[i-1],za[i].s);
		else premax[i]=za[i].s;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(i!=n-1) sufmin[i]=min(sufmin[i+1],za[i].s);
		else sufmin[i]=za[i].s;

		if(i!=n-1) sufmax[i]=max(sufmax[i+1],za[i].s);
		else sufmax[i]=za[i].s;
	}
	ll lb=-1;
	ll ub=2000000005;
	//(lb,ub]
	while(ub-lb>1)
	{
		ll mid=(lb+ub)>>1;
		int nxt=0;
		int beg=0;
		bool ok=false;
		while(nxt<n)
		{
			while(nxt<n && za[nxt].f<=za[beg].f+mid)  nxt++;
			//[beg,nxt)
			ll up=-INF,down=INF;
			if(beg==0 && nxt==n)
			{
				ok=true; break;
			}
			if(beg)
			{
				up=max(up,premax[beg-1]);
				down=min(down,premin[beg-1]);
			}
			if(nxt!=n)
			{
				up=max(up,sufmax[nxt]);
				down=min(down,sufmin[nxt]);
			}
			if(1LL*up-1LL*down<=mid)
			{
				ok=true; break;
			}
			beg++;
		}
		if(ok) ub=mid;
		else lb=mid;
	}
	printf("%.6f",(double)ub/2.0);
}