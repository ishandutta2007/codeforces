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

const int inf=1e18;
const int M=3e5+10;
int n,m,p,q,dis[M],vis[M];
vi a[M];
vpi e[M];
string s,c[M];

inline int F(int x,int y){return (x-1)*m+y;}
inline int F(pii x){return F(x.x,x.y);}

void dij()
{
	for (int i=1;i<=n*m;i++)dis[i]=inf;
	priority_queue<pii>q;
	q.push(mp(0,0));
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if (vis[u.y])continue;vis[u.y]=1;
		for (auto v:e[u.y])
			if (dis[v.x]>-u.x+v.y)
				dis[v.x]=-u.x+v.y,q.push(mp(-dis[v.x],v.x));
	}
}

signed main()
{
	n=read(),m=read(),p=read(),q=read();
	for (int i=1;i<=n;i++)a[i].resize(m+2);
	for (int i=1;i<=n;i++)
	{
		cin>>s;c[i]=s;
		for (int j=0;j<m;j++)
		{
			a[i][j+1]=s[j]=='#';
			if (s[j]=='.')e[0].pb(mp(F(i,j+1),0));
		}
	}
	cerr<<"qwq\n";
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (c[i][j-1]=='U')
			{
				pii p1=mp(i,j),p2=mp(i+1,j);
				if (i!=1&&!a[i-1][j])e[F(i-1,j)].pb(mp(F(p2),q));
				if (j!=1&&!a[i][j-1])e[F(i,j-1)].pb(mp(F(p2),p));
				if (j!=m&&!a[i][j+1])e[F(i,j+1)].pb(mp(F(p2),p));
				if (i+1!=n&&!a[i+2][j])e[F(i+2,j)].pb(mp(F(p1),q));
				if (j!=1&&!a[i+1][j-1])e[F(i+1,j-1)].pb(mp(F(p1),p));
				if (j!=m&&!a[i+1][j+1])e[F(i+1,j+1)].pb(mp(F(p1),p));
			}
			if (c[i][j-1]=='L')
			{
				pii p1=mp(i,j),p2=mp(i,j+1);
				if (j!=1&&!a[i][j-1])e[F(i,j-1)].pb(mp(F(p2),q));
				if (i!=1&&!a[i-1][j])e[F(i-1,j)].pb(mp(F(p2),p));
				if (i!=n&&!a[i+1][j])e[F(i+1,j)].pb(mp(F(p2),p));
				if (j+1!=m&&!a[i][j+2])e[F(i,j+2)].pb(mp(F(p1),q));
				if (i!=1&&!a[i-1][j+1])e[F(i-1,j+1)].pb(mp(F(p1),p));
				if (i!=n&&!a[i+1][j+1])e[F(i+1,j+1)].pb(mp(F(p1),p));
			}
		}
	cerr<<"qwq\n";
	dij();
//	for (int i=0;i<=n*m;i++)for (auto x:e[i])cout<<i<<' '<<x.x<<' '<<x.y<<'\n';
//	cerr<<dis[3]<<' '<<dis[8]<<'\n';
	int res=inf;
	for (int i=1;i<=n;i++)for (int j=1;j<m;j++)
		ckmin(res,dis[F(i,j)]+dis[F(i,j+1)]);
	for (int i=1;i<n;i++)for (int j=1;j<=m;j++)
		ckmin(res,dis[F(i,j)]+dis[F(i+1,j)]);
	if (res==inf)puts("-1");
	else cout<<res<<'\n';
	return 0;
}