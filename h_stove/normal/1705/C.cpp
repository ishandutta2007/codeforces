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
const int N=1e6+5;
struct Q
{
	ll l,r;
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,q,i,j;
		string s;
		cin>>n>>m>>q>>s;
		vector<Q> a(m);
		for (auto &[l,r]:a) cin>>l>>r;
		function<char(ll)> dfs=[&](ll k)
		{
			if (k<=n) return s[k-1];
			k-=n;
			for (auto &[l,r]:a) if (k<=r-l+1)
			{
				return dfs(k+l-1);
			} else k-=r-l+1;
			assert(0);
		};
		while (q--)
		{
			ll k;
			cin>>k;
			cout<<dfs(k)<<'\n';
		}
	}
}