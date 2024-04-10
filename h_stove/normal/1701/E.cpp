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
const int N=5e3+5,inf=1e9;
int f[N][N],lst[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,L,R,ans=inf;
		cin>>n>>m;
		string s,t;
		cin>>s>>t;s=' '+s;t=' '+t;
		for (i=0;i<=n+1;i++) for (j=0;j<=m+1;j++) f[i][j]=0;
		for (i=n;i;i--) for (j=m;j;j--) if (s[i]==t[j]) f[i][j]=f[i+1][j+1]+1; else f[i][j]=0;
		ans=n;
		for (j=1,L=1;j<=m;j++)
		{
			while (L<=n&&t[j]!=s[L]) ++L;
			if (L>n) break;
			for (i=L;i<=n;i++)
			{
				ans=min(ans,n-f[i][j]+(i-j)+(i!=j));
			}
			++L;
		}
		if (j<=m) cout<<"-1\n"; else assert(ans!=inf),cout<<ans<<'\n';
	}
}