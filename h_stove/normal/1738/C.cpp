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
		int n=0,m=0,q,i,j;
		cin>>q;
		while (q--)
		{
			int x;
			cin>>x;
			if (abs(x)&1) ++n; else ++m;
		}
		vector f(n+1,vector(m+1,vector(2,-1)));
		function<int(int,int,int,int)> dfs=[&](int n,int m,int p,int op) -> int
		{
			if (m<0) return 1;
			if (n==0) return p==0;
			if (f[n][m][p]!=-1) return f[n][m][p];
			f[n][m][p]=!dfs(n-1,m,p^op,op^1)||!dfs(n,m-1,p^1,op^1);
			// dbg(n,m,p,op,f[n][m][p]);
			return f[n][m][p];
		};
		cout<<(dfs(n,m,0,0)?"Alice":"Bob")<<'\n';
	}
}