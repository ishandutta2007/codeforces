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
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
ll l,x,y;
vector<ll>val;
int main()
{
	scanf("%d %lld %lld %lld",&n,&l,&x,&y);
	for(int i=0;i<n;i++)
	{
		ll a;scanf("%lld",&a);
		val.pb(a);
	}
	bool ex = 0,ey = 0;
	for(int i=0;i<n;i++)
	{
		if(binary_search(val.begin(),val.end(),val[i]+x))
		{
			ex = true;
		}
		if(binary_search(val.begin(),val.end(),val[i]+y))
		{
			ey = true;
		}
	}
	if(ex && ey)
	{
		puts("0"); return 0;
	}
	ll a[4];
	bool ok = false;
	ll res = -1;
	for(int i=0;i<n && !ok;i++)
	{
		a[0] = val[i]-x;
		a[1] = val[i]-y;
		a[2] = val[i]+x;
		a[3] = val[i]+y;
		for(int j=0;j<4 && !ok;j++)
		{
			if(!(0 <= a[j] && a[j] <= l)) continue;
			if(j%2 == 0)
			{
				if(binary_search(val.begin(),val.end(),a[j]-y) || ey)
				{
					ok = true; res = a[j];
				}
				if(binary_search(val.begin(),val.end(),a[j]+y) || ey)
				{
					ok = true; res = a[j];
				}
			}
			else
			{
				if(binary_search(val.begin(),val.end(),a[j]-x) || ex)
				{
					ok = true; res = a[j];
				}
				if(binary_search(val.begin(),val.end(),a[j]+x) || ex)
				{
					ok = true; res = a[j];
				}
			}
		}
	}
	if(ok)
	{
		printf("1\n%lld\n",res); return 0;
	}
	else
	{
		printf("2\n%lld %lld\n",x,y); return 0;
	}
}