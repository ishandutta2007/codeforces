//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=5e5+5;
struct Q
{
	int l,r,p;
	bool operator<(const Q &o) const {return r<o.r;}
};
int a[N],b[N];
Q c[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>b[i];
			c[i]={i/(b[i]+1)+1,b[i]?i/b[i]:n,i};
			// cerr<<c[i].l<<' '<<c[i].r<<'\n';
		}
		sort(c+1,c+n+1);
		iota(a+1,a+n+1,1);
		set<int> s(a+1,a+n+1);
		for (i=1;i<=n;i++)
		{
			auto it=s.lower_bound(c[i].l);
			assert(it!=s.end());
			a[c[i].p]=*it;
			s.erase(it);
		}
		for (i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
	}
}