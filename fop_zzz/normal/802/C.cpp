#pragma comment(linker, "/stack:200000000")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define inf 1000000005
#define int ll 

using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/
const int N=30005;
int n,k,a[N],b[N],cnt=1;
int inq[N*4],vis[N*4],poi[N*40],nxt[N*40],w[N*40],head[N*4],S,T,SS;
ll ans,dis[N*4],v[N*40],tans;
inline void Add(int x,int y,int tw,int tv)
{
//	cout<<x<<' '<<y<<' '<<tw<<endl;
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;w[cnt]=tw;v[cnt]=tv;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;w[cnt]=0;v[cnt]=-tv;
}
inline bool spfa(int t,int s)
{
	queue<int> Q;
    For(i,1,SS)	inq[i]=0,dis[i]=1e17;
    dis[T]=0;Q.push(T);
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();inq[x]=0;
        for(int i=head[x];i;i=nxt[i])
        {
            if(w[i^1]&&(v[i^1]+dis[x]<dis[poi[i]]))
            {
                dis[poi[i]]=dis[x]+v[i^1];
                if(!inq[poi[i]])	inq[poi[i]]=1,Q.push(poi[i]);
            }
        }
    }
    return dis[SS]!=1e17;
}
inline int Dfs(int x,int flow)
{
    vis[x]=1;
    if(x==T)	return flow;
    int used=0;
    for(int i=head[x];i;i=nxt[i])
    {
        if(w[i]&&v[i]+dis[poi[i]]==dis[x]&&!vis[poi[i]])
        {
//        	cout<<x<<"=>"<<poi[i]<<' '<<min(w[i],flow-used)<<endl;
            int tmp=Dfs(poi[i],min(w[i],flow-used));
            used+=tmp;w[i]-=tmp;w[i^1]+=tmp;
            tans+=1LL*tmp*v[i];
            if(used==flow)	return flow;
        }
    }
    return used;
}
inline void ZKW()
{ 
	tans=0;
	while(spfa(T,SS))
	{
		vis[T]=1;
		while(vis[T])
		{
			For(i,1,SS)	vis[i]=0;
			Dfs(SS,inf);
		}
	}
	ans+=tans;
	writeln(ans+ 1LL*n*inf);
}
int las[N],c[N];
signed main()
{
//	freopen("mogic.in","r",stdin);freopen("mogic.out","w",stdout);
	n=read();k=read();
	For(i,1,n)	b[i]=read(),c[i]=b[i];
	int jb=0;
	sort(c+1,c+n+1);
	For(i,1,n)	if(!vis[c[i]])	jb++,vis[c[i]]=1;
	k=min(k,jb);	
	For(i,1,n)	a[i]=read();
	S=3*n+1;T=S+1;SS=T+1;Add(SS,S,k,0);
	For(i,1,n)	las[i]=n+1;
	Dow(i,1,n)
	{
		int nxt=las[b[i]];
		las[b[i]]=i;
		if(nxt!=n+1)Add(i+n,nxt,1,0);
	}
	For(i,1,n)
	{
		Add(S,i,1,a[b[i]]);Add(i+n,T,1,0);
		if(i!=n)	Add(i+2*n,i+2*n+1,inf,0);
		if(i!=n)	Add(i+2*n,i+1,1,a[b[i+1]]);
		Add(i,i+n,1,-inf);
		Add(i+n,i+2*n,1,0);
	}
	ZKW();
}