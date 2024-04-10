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
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int k,n,m;
ll a[100005];
vector<pair<ll,int> >add[100005];
vector<pair<pair<ll,ll>,int> >mul;
ll up[100005],dw[100005];
ll as[100005];
int asid[100005];
int x[100005];
bool cmp(pair<pair<ll,ll>,int> a,pair<pair<ll,ll>,int> b)
{
	long double x = (long double)a.fi.fi * (long double)b.fi.sc;
	long double y = (long double)b.fi.fi * (long double)a.fi.sc;
	return x < y;
}
bool cmp2(int a,int b)
{
	return x[a] < x[b];
}
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int a,b; ll c; scanf("%d%d%lld",&a,&b,&c);
		x[i] = a;
		if(a == 1)
		{
			if(as[b] < c){ as[b] = c; asid[b] = i; }
		}
		else if(a == 2)
		{
			add[b].pb(mp(c,i));
		}
		else
		{
			mul.pb(mp(mp(c,1LL),i));
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(!as[i]) continue;
		if(as[i] < a[i]) continue;
		add[i].pb(mp(as[i]-a[i],asid[i]));
	}
	for(int i=1;i<=k;i++)
	{
		sort(add[i].begin(),add[i].end());
		reverse(add[i].begin(),add[i].end());
		ll cur = a[i];
		for(int j=0;j<add[i].size();j++)
		{
			ll nxt = cur + add[i][j].fi;
			mul.pb(mp(mp(nxt,cur),add[i][j].sc));
			cur = nxt;
		}
	}
	sort(mul.begin(),mul.end(),cmp);
	reverse(mul.begin(),mul.end());
	vector<int>res;
	for(int i=0;i<min(m,(int)mul.size());i++)
	{
		res.pb(mul[i].sc);
	}
	sort(res.begin(),res.end(),cmp2);
	cout << res.size() << endl;
	for(int i=0;i<res.size();i++)
	{
		printf("%d%c",res[i],i==res.size()-1?'\n':' ');
	}
}