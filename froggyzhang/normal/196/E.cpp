#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,h[N],m,k,p[N],c[N];
vector<pair<int,int> > G[N];
ll dis[N],ans;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void Dijkstra(){
	static int vis[N];
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				c[v]=c[u];
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
struct Union_Set{
	int f[N];
	void init(int n){for(int i=1;i<=n;++i)f[i]=i;}
	inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
}S;
int tot;
struct Link{
	int x,y;
	ll w;
	friend bool operator < (const Link &a,const Link &b){
		return a.w<b.w;
	}
}L[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	k=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;++i){
		p[i]=read();
		h[p[i]]=1;
		q.push(make_pair(0LL,p[i]));
		dis[p[i]]=0,c[p[i]]=p[i];
	}
	Dijkstra();
	ans=dis[1];
	for(int u=1;u<=n;++u){
		for(auto [v,w]:G[u]){
			if(v>u){
				L[++tot]={c[u],c[v],dis[u]+dis[v]+w};	
			}
		}	
	}
	S.init(n);
	sort(L+1,L+tot+1);
	for(int i=1;i<=tot;++i){
		int fx=S.getf(L[i].x),fy=S.getf(L[i].y);
		if(fx==fy)continue;
		ans+=L[i].w;
		S.f[fy]=fx;
	}
	printf("%lld\n",ans);
	return 0;
}