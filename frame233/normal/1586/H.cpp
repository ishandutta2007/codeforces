#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef std::pair<int,int> pi;
int a[N];std::vector<pi> e[N];
struct edge{int u,v,c,t;inline bool operator < (const edge &o)const{return c>o.c;}}b[N];
struct qry{int v,x,id;inline bool operator < (const qry &o)const{return v>o.v;}}c[N];
int anc[N][20],w[N][20],dep[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,anc[x][0]=fa;for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1],w[x][i]=std::max(w[x][i-1],w[anc[x][i-1]][i-1]);
	for(auto [v,w]:e[x])if(v!=fa)::w[v][0]=w,dfs(v,x);
}
int getmx(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	int ans=0;for(int i=19;i>=0;--i)if(dep[anc[x][i]]>=dep[y])ans=std::max(ans,w[x][i]),x=anc[x][i];
	if(x==y)return ans;
	for(int i=19;i>=0;--i)if(anc[x][i]!=anc[y][i])ans=std::max({ans,w[x][i],w[y][i]}),x=anc[x][i],y=anc[y][i];
	return std::max({ans,w[x][0],w[y][0]});
}
int fa[N],nd[N],val[N],res[N],ans[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
	x=find(x),y=find(y),fa[x]=y;
	if(a[nd[x]]==a[nd[y]])val[y]=std::max({val[x],val[y],getmx(nd[x],nd[y])});
	else if(a[nd[x]]>a[nd[y]])val[y]=val[x],nd[y]=nd[x];
}
int main(){
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,u,v,c,t;i<n;++i)read(u,v,c,t),e[u].pb({v,t}),e[v].pb({u,t}),b[i]={u,v,c,t};
	for(int i=1;i<=q;++i)read(c[i].v,c[i].x),c[i].id=i;
	dfs(1,0),std::sort(b+1,b+n),std::sort(c+1,c+q+1);
	for(int i=1;i<=n;++i)fa[i]=i,nd[i]=i;
	for(int i=1,p=1;i<=q;++i){
		while(p<n&&b[p].c>=c[i].v)merge(b[p].u,b[p].v),++p;
		int x=c[i].x;ans[c[i].id]=std::max(val[find(x)],getmx(x,nd[find(x)])),res[c[i].id]=a[nd[find(x)]];
	}
	for(int i=1;i<=q;++i)printf("%d %d\n",res[i],ans[i]);
	return 0;
}