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
int a[N],cnt[N],pre[N],suf[N],f[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k,ans=0;
		cin>>n;
		fill_n(cnt,n,0);
		for (i=0;i<n;i++) cin>>a[i],--a[i];
		int mx=0;
		for (i=0;i<n;i++)
		{
			pre[i]=(i>=mx*2&&(1^i&1));
			++cnt[a[i]];
			mx=max(mx,cnt[a[i]]);
		}
		fill_n(cnt,n,0);mx=0;
		for (i=n-1;i>=0;i--)
		{
			suf[i]=(n-i-1>=mx*2&&(n-i&1));
			++cnt[a[i]];
			mx=max(mx,cnt[a[i]]);
		}
		for (i=0;i<n;i++) if (pre[i]) f[i]=1; else f[i]=-inf;
		fill_n(cnt,n,0);
		for (i=0;i<n;i++)
		{
			int mx=0;
			for (j=i+1;j<n;j++)
			{
				if (a[i]==a[j]&&(j-i&1)&&mx*2<=j-i-1) f[j]=max(f[j],f[i]+1);
				mx=max(mx,++cnt[a[j]]);
			}
			fill_n(cnt,n,0);
		}
		for (i=0;i<n;i++) if (suf[i]) ans=max(ans,f[i]);
		cout<<ans<<'\n';
	}
}