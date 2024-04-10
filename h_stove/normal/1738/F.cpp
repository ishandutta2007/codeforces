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
int ask(int u)
{
	cout<<"? "<<u<<'\n';
	cin>>u;
	assert(u!=-1);
	return u;
}
void answer(vector<int> a)
{
	a.erase(a.begin());
	cout<<"! "<<a<<'\n';
}
struct union_set
{
	vector<int> f;
	int n;
	union_set() {}
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) { return f[u]==u?u:f[u]=getf(f[u]); }
	void merge(int u,int v)
	{
		u=getf(u); v=getf(v);
		f[u]=v;
	}
	bool connected(int u,int v) { return getf(u)==getf(v); }
};
int main()
{
	ios::sync_with_stdio(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
		int n,m=0,i,j;
		cin>>n;
		vector<int> d(n+1);
		for (i=1; i<=n; i++) cin>>d[i];
		vector<pair<int,int>> a(n);
		vector<int> r(n+1);
		for (i=0; i<n; i++) a[i]={d[i+1],i+1};
		sort(all(a)); reverse(all(a));
		union_set s(n);
		for (auto [d,u]:a) if (!r[u])
		{
			r[u]=++m;
			vector<int> b(d);
			for (i=0; i<d; i++)
			{
				int v=ask(u);
				if (r[v]) { s.merge(r[v],m); break; }
				else r[v]=m;
			}
		}
		for (int &x:r) x=s.getf(x);
		answer(r);
	}
}