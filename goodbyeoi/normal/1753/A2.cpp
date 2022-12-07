#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vpi vector<pii>
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,a[M],vis[M];

void solve()
{
	n=read();vpi ans;int cnt=0,top=0,f=0;
	for (int i=1;i<=n;i++)a[i]=read(),cnt+=a[i],vis[i]=0;
	if (cnt%2!=0)return puts("-1"),void();
	vi v;
	for (int i=1;i<=n;i++)
		if (a[i]!=0)v.pb(i);
	for (int i=0;i<(int)(v.size());i+=2)
	{
		if (a[v[i]]!=a[v[i+1]])ans.pb(mp(v[i],v[i+1]-1)),ans.pb(mp(v[i+1],v[i+1]));
		else if (v[i]==v[i+1]-1)ans.pb(mp(v[i],v[i+1]));
		else ans.pb(mp(v[i],v[i+1]-2)),ans.pb(mp(v[i+1]-1,v[i+1]));
	}
	for (auto x:ans)for (int j=x.x;j<=x.y;j++)vis[j]=1;
	for (int i=1;i<=n;i++)
	{
		if (vis[i])continue;
		int j=i;
		while(j<=n&&!vis[j])j++;
		ans.pb(mp(i,j-1));
		i=j;
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for (auto x:ans)cout<<x.x<<' '<<x.y<<'\n'; 
}

signed main()
{
	WT solve();
	return 0;
}