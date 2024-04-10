#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef std::pair<int,int> pi;
std::vector<int> e[N];int f[N],Fa[N];bool flag;std::set<int> S[N][2];
void dfs1(int x,int fa){
	Fa[x]=fa;int c0=0,c1=0;
	for(auto v:e[x])if(v!=fa)dfs1(v,x),++(f[v]==1?c1:c0);
	if(fa){if(c1<c0)f[x]=1,++c1;else f[x]=0,++c0;}
	if(c1<c0-1||c0<c1)flag=1;
}
int DG[N],dg[N];std::vector<pi> ans;
void apply(int x,int y){ans.pb({x,y}),S[x][dg[x]%2].erase(y),S[y][dg[y]%2].erase(x),++dg[x],++dg[y];}
void dfs2(int x){
	int v=*S[x][dg[x]%2].begin();
	if(dg[v]%2!=dg[x]%2)dfs2(v);
	apply(x,v);
}
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)e[i].clear(),DG[i]=0;
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x),++DG[x],++DG[y];
	flag=0,dfs1(1,0);if(flag)return puts("NO"),void();
	for(int i=1;i<=n;++i)dg[i]=0,S[i][0].clear(),S[i][1].clear();
	for(int i=2;i<=n;++i)S[i][f[i]].insert(Fa[i]),S[Fa[i]][f[i]].insert(i);
	ans.clear();for(int i=1;i<=n;++i)while(dg[i]<DG[i])dfs2(i);
	std::reverse(ans.begin(),ans.end());
	puts("YES");for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}