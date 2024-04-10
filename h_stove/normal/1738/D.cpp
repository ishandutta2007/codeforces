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
		int n,m=0,i,j,l=0;
		cin>>n;
		vector<int> b(n+1);
		vector e(n+2,vector(0,0));
		for (i=1; i<=n; i++)
		{
			cin>>b[i],m+=b[i]>i;
			e[b[i]].push_back(i);
		}
		for (i=0; i<=n+1; i++) sort(all(e[i]),[&](const int &x,const int &y) { return e[x].size()<e[y].size(); });
		vector<int> a;
		function<void(int)> dfs=[&](int u)
		{
			if (u&&u<=n) a.push_back(u);
			for (int v:e[u]) dfs(v);
		};
		for (int x:{0,n+1}) dfs(x);
		cout<<m<<'\n'<<a<<'\n';
		// for (i=2; i<=n+1; i++) cout<<a[i]<<" \n"[i==n+1];
	}
}