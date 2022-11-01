#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define int ll 
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
int mo=998244353;
int dis[606][606];
int vis[606],n,m,dp[606][606];
vector<int> E[606];
inline void Bfs(int x)
{
	For(i,1,n)	dis[x][i]=-1;
	dis[x][x]=0;
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto v:E[u])
			if(dis[x][v]==-1)	dis[x][v]=dis[x][u]+1,q.push(v);
	}
}
signed main()
{
	n=read();m=read();
	For(i,1,m)
	{
		int u=read(),v=read();
		E[u].pb(v);
		E[v].pb(u);
	}
	For(i,1,n)
		Bfs(i);
		// For(i,1,n)	{For(j,1,n)	cout<<dis[i][j]<<' ';cout<<endl;}
	For(s,1,n)
		For(t,s,n)
		{
			memset(vis,0,sizeof vis);
			int u=t;
			bool flag=1;
			while(u!=s)
			{
				vis[u]=1;
				int cnt=0,pos=0;
				for(auto v:E[u])
				{
					if(dis[s][v]==dis[s][u]-1)
						++cnt,pos=v;
				}
				if(cnt!=1)	{flag=0;break;}
				u=pos;
			}
			if(!flag)	continue;
			vis[u]=1;
			int ans=1;
			For(u,1,n)
				if(!vis[u])
				{
					int cnt=0;
					for(auto v:E[u])
					{
						if(dis[s][v]==dis[s][u]-1)
							if(dis[t][v]+1==dis[t][u])
								++cnt;
					}
					ans=ans*cnt%mo;
				}
			dp[s][t]=dp[t][s]=ans;
		}
	For(i,1,n)	{For(j,1,n)	write_p(dp[i][j]);puts("");}
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/