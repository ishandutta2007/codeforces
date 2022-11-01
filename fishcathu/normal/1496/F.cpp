#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=401;
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
int head[N],nex[N*3],to[N*3],cnt;
int n,dis[N][N],q[N],ans[N][N],f[N];
bitset<N>b;
const int p=998244353;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void bfs(int x)
{
	for(int i=1;i<=n;++i)b[i]=0;
	q[1]=x;
	b[x]=1;
	for(int l=1,r=1;l<=r;)
	{
		int y=q[l++];
		for(int i=head[y];i;i=nex[i])
		{
			int t=to[i];
			if(b[t])continue;
			b[t]=1;
			dis[x][t]=dis[x][y]+1;
			q[++r]=t;
		}
	}
}
int getans(int u,int v)
{
	memset(f+1,0,n<<2);
	f[u]=1; 
	q[1]=u;
	int r=1;
	for(int l=1;l<=r;)
	{
		int x=q[l++];
		for(int i=head[x];i;i=nex[i])
		{
			int t=to[i];
			if(dis[u][t]==dis[u][x]+1&&dis[v][t]==dis[v][x]-1)
			{
				if(f[t]++)return 0;
				q[++r]=t;
			}
		}
	}
	for(int l=1;l<=r;)
	{
		int x=q[l++];
		for(int i=head[x];i;i=nex[i])
		{
			int t=to[i];
			if(dis[u][t]==dis[u][x]+1&&dis[v][t]==dis[v][x]+1)
			{
				if(!f[t]++)q[++r]=t;
			}
		}
	}
	int res=1;
	for(int i=1;i<=n;++i)res=res*1ll*f[i]%p;
	return res;
}
int main()
{
	n=read();
	for(int m=read();m--;)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i)bfs(i);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<i;++j)write(ans[j][i],' ');
		for(int j=i;j<=n;++j)write(ans[i][j]=getans(i,j),' ');
		putchar('\n');
	}
}