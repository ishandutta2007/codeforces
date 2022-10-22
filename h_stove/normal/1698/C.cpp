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
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n;
		vector<int> a(n);
		for (int &x:a) cin>>x;
		sort(all(a));reverse(all(a));
		set<ll> s(all(a));
		if (n<=4)
		{
			for (i=0;i<n;i++) for (j=i+1;j<n;j++) for (k=j+1;k<n;k++) if (!s.count((ll)a[i]+a[j]+a[k]))
			{
				goto no;
			}
			cout<<"YES\n";
			continue;
		}
		for (i=1;i<n-1;i++) if (a[i]) break;
		if (i==n-1&&s.count(a[0]+a[n-1]))
		{
			cout<<"YES\n";
			continue;
		}
		no:cout<<"NO\n";
	}
}