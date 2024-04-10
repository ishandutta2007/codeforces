//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		vector<int> a(n),b(n);
		cin>>a>>b;
		vector c(2,vector(0,0));
		for (i=0; i<n; i++) c[a[i]].push_back(b[i]);
		if (c[0].size()>c[1].size()) swap(c[0],c[1]);
		n=c[0].size(),m=c[1].size();
		ll res=accumulate(all(c[0]),0ll)+accumulate(all(c[1]),0ll);
		sort(all(c[0])); sort(all(c[1]));
		reverse(all(c[0])); reverse(all(c[1]));
		ll r1=0,r2=0;
		for (i=0; i<n&&i<m; i++) r1+=c[0][i];
		for (i=0; i+1<n&&i<m; i++) r1+=c[1][i];
		for (i=0; i<n&&i<m; i++) r2+=c[1][i];
		for (i=0; i+1<m&&i<n; i++) r2+=c[0][i];
		// dbg(n,m,r1,r2);
		cout<<res+max(r1,r2)<<'\n';
	}
}