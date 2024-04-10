#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef std::pair<int,int> pi;typedef long long ll;
std::vector<pi> e[N];
struct node{int u;ll d;inline bool operator < (const node &o)const{return d>o.d;}};
std::priority_queue<node> q;ll dis[N];
void dij(int s){
	memset(dis,63,sizeof(dis)),dis[s]=0,q.push({s,0});
	while(!q.empty()){
		node x=q.top();q.pop();if(dis[x.u]!=x.d)continue;
		for(const auto &it:e[x.u]){
			int v=it.first,w=it.second;
			if(dis[v]>dis[x.u]+w)dis[v]=dis[x.u]+w,q.push({v,dis[v]});
		}
	}
}
int t[N],anc[N][20],dep[N],siz[N];
int lca(int x,int y){
	if(!x||!y)return x|y;
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=19;i>=0;--i)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;--i)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int main(){
	int n,m,s;read(n,m,s);
	for(int i=1,x,y,z;i<=m;++i)read(x,y,z),e[x].pb({y,z}),e[y].pb({x,z});
	dij(s);std::iota(t+1,t+n+1,1),std::sort(t+1,t+n+1,[&](int x,int y){return dis[x]<dis[y];}),dep[s]=1;
	for(int i=2;i<=n;++i){
		int x=t[i];if(dis[x]>1e18)break;
		int fa=0;for(const auto &it:e[x])if(dis[it.first]+it.second==dis[x])fa=lca(fa,it.first);
		dep[x]=dep[fa]+1,anc[x][0]=fa;for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=1;i<=n;++i)siz[i]=1;
	for(int i=n;i>=2;--i)siz[anc[t[i]][0]]+=siz[t[i]];
	int mx=0;for(int i=2;i<=n;++i)if(dis[t[i]]<=1e18)mx=std::max(mx,siz[t[i]]);
	printf("%d\n",mx);
	return 0;
}