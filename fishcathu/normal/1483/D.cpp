#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<string,int> pii;
const int N=601;
const ll inf=1LL<<60;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
ll max(ll a,ll b){return a>b?a:b;}
ll dis[N][N],mx[N][N];
int vis[N][N];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			dis[i][j]=dis[j][i]=inf;
		}
	}
	while(m--)
	{
		int u=read(),v=read(),w=read();
		dis[u][v]=dis[v][u]=vis[u][v]=vis[v][u]=w;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=j+1;k<=n;++k)
			{
				dis[j][k]=dis[k][j]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	for(int x=read();x--;)
	{
		int u=read(),v=read(),w=read();
		for(int i=1;i<=n;++i)
		{
			mx[u][i]=max(mx[u][i],w-dis[i][v]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(!vis[i][j])continue;
			for(int k=1;k<=n;++k)
			{
				if(dis[k][i]+vis[i][j]<=mx[k][j]||dis[k][j]+vis[j][i]<=mx[k][i])
				{
					++ans;
					break;
				}
			}
		}
	}
	write(ans,'\n'); 
}