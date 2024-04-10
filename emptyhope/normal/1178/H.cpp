#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define maxn 100005
#define inf 0x3f3f3f3f
int n,m,s,t,maxflow,mincost;
int dis[maxn],pre[maxn],lste[maxn],flow[maxn];
bool inq[maxn];
struct edge{
	int to,nxt,w,cost;
}e[maxn<<1];
int tot=1,head[maxn];
inline void adde(int u,int v,int w,int c){
	e[++tot]=(edge){v,head[u],w,c};
	head[u]=tot;
}
inline void add(int u,int v,int w,int c){
//	cout<<u<<' '<<v<< ' '<<w<<' '<<c<<endl; 
    adde(u,v,w,c);
    adde(v,u,0,-c);
}
bool spfa(int s,int t)
{
	queue<int>q;
	memset(dis,63,sizeof dis);
	memset(flow,63,sizeof flow);
	memset(inq,0,sizeof inq);
	dis[s]=0,pre[t]=-1;q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(e[i].w>0&&dis[v]>dis[u]+e[i].cost){
				dis[v]=dis[u]+e[i].cost;
				pre[v]=u,lste[v]=i;
				flow[v]=min(flow[u],e[i].w);
				if(!inq[v])inq[v]=1,q.push(v);
			}
		}
	}return pre[t]!=-1;
}
void mcmf(int s,int t)
{
	while(spfa(s,t))
	{
		int u=t;
		maxflow+=flow[t],mincost+=flow[t]*dis[t];
		while(u!=s)
		{
			int E=lste[u];
			e[E].w-=flow[t],e[E^1].w+=flow[t];
			u=pre[u];
		}
	}
}

int p1[5555],p2[5555];
int k[5555],b[5555],val[5555];
bool cmp1(int x,int y){
	if(b[x]==b[y])return k[x]>k[y];
	return b[x]<b[y];
}
bool check(int t)
{
	For(i,1,2*n)p1[i]=p2[i]=i;
	sort(p1+1,p1+2*n+1,cmp1);
	sort(p2+n+1,p2+n+n+1,[&](int x,int y){return k[x]*t+b[x]<k[y]*t+b[y];});
	int mx=0;
	For(i,1,2*n){
		mx=max(mx,k[p1[i]]*t+b[p1[i]]);
		if(p1[i]<=n) val[p1[i]]=mx;
	}
	sort(val+1,val+n+1);
	Rep(i,n,1)if(val[i]<k[p2[i+n]]*t+b[p2[i+n]]) return 0;
	return 1; 
}

#define out(x) ((x)+(n<<1)) 
bool cmp2(int x,int y){
	if(b[x]==b[y])return x>y;
	return b[x]<b[y];
}
int sum[maxn];
int work(int T)
{
	s=0,t=4*n+1; int cnt=4*n+1;
	// in[i]=i,out[i]=i+n*2
	For(i,1,2*n) add(i,out(i),inf,0);
	For(i,1,n) add(s,i,1,0);
	For(i,n+1,2*n) add(out(i),t,1,0);
	
	For(i,1,2*n)p1[i]=i;
	sort(p1+1,p1+2*n+1,cmp2);
	sum[1]=p1[1];
	For(i,2,n*2){
		sum[i]=++cnt;
		add(sum[i],sum[i-1],inf,0);
		add(sum[i],p1[i],inf,0);
	}
	For(i,2,n*2) add(p1[i],sum[i-1],inf,1);
	
	For(i,1,n*2)p2[i]=i;
	sort(p2+1,p2+n*2+1,
		[&](int x,int y){
			if(k[x]*T+b[x]==k[y]*T+b[y]) return x>y;
			return k[x]*T+b[x]<k[y]*T+b[y];
		}
	);
//	For(i,1,n*2)cout<<p1[i]<<' ';puts("");For(i,1,n*2)cout<<p2[i]<<' ';puts(""); 
	sum[1]=out(p2[1]);
	For(i,2,2*n){
		sum[i]=++cnt;
		add(sum[i],sum[i-1],inf,0);
		add(sum[i],out(p2[i]),inf,0);
	}
	For(i,2,2*n) add(out(p2[i]),sum[i-1],inf,1);
	mcmf(s,t);//cout<<maxflow<<' '<<mincost<<endl;
	return mincost;
}

signed main()
{
	n=read();
	For(i,1,n*2)k[i]=read(),b[i]=read(); 
	if(!check(1e9+1))return puts("-1")&0;
	int l=0,r=1e9+1,res=r;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))res=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<res<<' ';
	cout<<work(res);
    return 0;
}