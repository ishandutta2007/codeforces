#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int S,P,n,c[1010],t[1010];
pii s[1010],p[1010];
vector < pii > ans[1010];

int main()
{
	int m;
	cin >> m >> n;
	fr(i,1,m)
	{
		cin >> c[i] >> t[i];
		if (t[i]==1) s[++S]=mp(-c[i],i);
		else p[++P]=mp(-c[i],i);
	}
	
	if (!S)
		fr(i,1,P) ans[min(i,n)].pb(p[i]);
	else
	{
		int l=1;
		if (S) sort(s+1,s+S+1);
		fr(i,1,min(S,n)) ans[i].pb(s[i]);
		if (S>n)
			fr(i,n+1,S) ans[n].pb(s[i]);
		while (S<n) ans[++S].pb(p[l++]);
		while (l<=P) ans[n].pb(p[l++]);
	}
	
	long long price=0;
	fr(i,1,n)
	{
		int discount=0,minPrice=oo;
		long long priceThis=0;
		rep(j,sz(ans[i]))
		{
			priceThis-=ans[i][j].fi;
			minPrice=min(minPrice,-ans[i][j].fi);
			if (t[ans[i][j].se]==1) discount=1;
		}
		price+=priceThis*2-minPrice*discount;
	}
	cout << price/2 << (price%2?".5":".0") << endl;
	fr(i,1,n)
	{
		cout << sz(ans[i]) << ' ';
		rep(j,sz(ans[i])) cout << ans[i][j].se << ' ';
		puts("");
	}
}