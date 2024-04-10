#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005,inf=0x3f3f3f3f;
int a[N],h[N];std::vector<int> e[N],E[N];
void dfs1(int x,int fa){
	h[x]=a[x]?0:1e9,E[x]=e[x];if(fa)e[x].erase(std::find(e[x].begin(),e[x].end(),fa));
	for(auto v:e[x])if(v!=fa)dfs1(v,x),h[x]=std::min(h[x],h[v]+1);
}
void dfs2(int x){
	std::vector<int> pre(SZ(e[x])),suf(SZ(e[x]));
	for(int i=0;i<SZ(e[x]);++i)pre[i]=suf[i]=h[e[x][i]]+1;
	for(int i=1;i<SZ(e[x]);++i)pre[i]=std::min(pre[i],pre[i-1]);
	for(int i=SZ(e[x])-2;i>=0;--i)suf[i]=std::min(suf[i],suf[i+1]);
	for(int i=0;i<SZ(e[x]);++i){
		int v=e[x][i],mn=std::min({i?pre[i-1]:inf,i+1<SZ(e[x])?suf[i+1]:inf,h[x]});
		h[v]=std::min(h[v],mn+1),dfs2(v);
	}
}
int dis[N];std::vector<int> Q[N];int ans[N];
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs1(1,0),dfs2(1);std::vector<int> vec;
	for(int i=1;i<=n;++i)for(auto v:e[i])if(h[v]==h[i])vec.pb(h[i]);
	std::sort(vec.begin(),vec.end()),vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;++i)e[i]=E[i];
	for(auto x:vec){
		memset(dis,63,sizeof(dis));
		for(int i=1;i<=n;++i)for(auto v:e[i])if(h[v]==h[i]&&h[i]==x)dis[i]=h[i],dis[v]=h[v];
		for(int i=1;i<=n;++i)if(dis[i]<inf)Q[dis[i]].pb(i);
		for(int d=0;d<=n;++d){
			while(!Q[d].empty()){
				int v=Q[d].back();Q[d].pop_back();
				if(dis[v]!=d)continue;
				for(auto u:e[v])if(h[u]>=h[v]){
					int tmp=h[u]==h[v]?dis[v]+1:std::max(dis[v],h[u]);
					if(dis[u]>tmp)dis[u]=tmp,Q[tmp].pb(u);
				}
			}
		}
		for(int i=1;i<=n;++i)if(ans[i]==-1&&h[i]>=dis[i])ans[i]=x;
	}
	for(int i=1;i<=n;++i)printf("%d%c",ans[i]==-1?h[i]:2*h[i]-ans[i]," \n"[i==n]);
	return 0;
}