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
		int n,m,i,j;
		ll r=0;
		string s,t;
		cin>>n>>s>>t;
		vector<int> a(n),b(n);
		for (i=0;i<n;i++) a[i]=s[i]-'0';
		for (i=0;i<n;i++) b[i]=t[i]-'0';
		for (i=n-1;i;i--) a[i]^=a[i-1],b[i]^=b[i-1];
		vector<int> c,d;
		if (s[0]!=t[0]||s[n-1]!=t[n-1]||accumulate(all(a),0)!=accumulate(all(b),0)) goto no;
		for (i=0;i<n;i++) if (a[i]) c.push_back(i);
		for (i=0;i<n;i++) if (b[i]) d.push_back(i);
		for (i=0;i<c.size();i++) r+=abs(c[i]-d[i]);
		cout<<r<<'\n';continue;
		no:cout<<"-1\n";
	}
}