#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
struct Q
{
	int x,y;
	ll operator-(const Q &o) const {return abs(x-o.x)+abs(y-o.y);}
};
vector<pair<Q,Q>> r;
void con(Q a,Q b)
{
	if (a.x==b.x&&a.y==b.y) return;
	if (a.x==b.x||a.y==b.y) {r.push_back({a,b});return;}
	r.push_back({a,{a.x,b.y}});
	r.push_back({b,{a.x,b.y}});
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	vector<Q> a(3);
	int b[3]={0,1,2},i,j;
	for (auto &[x,y]:a) cin>>x>>y;
	vector<int> d(3);
	for (i=0;i<3;i++) d[i]=a[i].x;
	sort(all(d));
	int x=d[1];
	for (i=0;i<3;i++) d[i]=a[i].y;
	sort(all(d));
	int y=d[1];
	for (i=0;i<3;i++) con(a[i],{x,y});
	cout<<r.size()<<'\n';
	for (auto v:r)
	{
		auto [x,y]=v;
		cout<<x.x<<' '<<x.y<<' '<<y.x<<' '<<y.y<<'\n';
	}
}