#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;typedef long long ll;
std::vector<int> e[N];int a[N],st[N],top;
struct edge{
	int u,v;ll w;
	inline bool operator < (const edge &o)const{return w<o.w;}
}E[N*20];int pos,rt;
void dfs(int x,int fa){
	st[++top]=x;int i=0;
	while((1<<i)<top){
		int y=st[top-(1<<i)];
		E[++pos]={x,y,a[x]+a[y]+1LL*std::min(a[x],a[y])*i},++i;
	}
	if(fa)E[++pos]={x,rt,a[x]+a[rt]+1LL*std::min(a[x],a[rt])*i};
	for(auto v:e[x])if(v!=fa)dfs(v,x);
	--top;
}
int fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	rt=std::min_element(a+1,a+n+1)-a;dfs(rt,0);
	std::sort(E+1,E+pos+1),std::iota(fa+1,fa+n+1,1);ll ans=0;
	for(int i=1;i<=pos;++i){
		int u=find(E[i].u),v=find(E[i].v);
		if(u!=v)fa[u]=v,ans+=E[i].w;
	}
	printf("%lld\n",ans);
	return 0;
}