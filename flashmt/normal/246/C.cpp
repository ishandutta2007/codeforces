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
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 2000
#define maxN 1
using namespace std;

set < pair<int,long long> > d[55];
set <int> e;

int main()
{
	int n,k,a[55];
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	
	rep(i,n)
	{
		for (set < pair<int,long long> >::iterator it=d[i].begin();it!=d[i].end();it++)
		{
			if (!e.count(it->fi+a[i]))
			{	
				d[i+1].insert(mp(it->fi+a[i],it->second+(1LL<<i)));
				e.insert(it->fi+a[i]);
			}
			d[i+1].insert(*it);
		}
		if (!e.count(a[i]))
		{
			d[i+1].insert(mp(a[i],1LL<<i));
			e.insert(a[i]);
		}
			
		set < pair<int,long long> >::iterator it=d[i+1].end();
		it--;
		while (sz(d[i+1])>k) 
		{
			set < pair<int,long long> >::iterator tmp=it--;
			e.erase(tmp->fi);
			d[i+1].erase(tmp);
		}
	}

	for (set < pair<int,long long> >::iterator it=d[n].begin();it!=d[n].end();it++)
	{
		vector <int> c;
		long long mask=it->se;
		rep(i,n)
			if (mask>>i&1) c.pb(a[i]);
		cout << sz(c) << ' ';
		rep(i,sz(c)) cout << c[i] << ' ';
		puts("");
	}
}