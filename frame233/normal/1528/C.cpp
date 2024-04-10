#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005;
std::vector<int> e1[N],e2[N];
int dfn[N],rev[N],siz[N],id,ans;
void dfs1(int x,int fa){
	dfn[x]=++id,siz[x]=1,rev[id]=x;
	for(auto v:e2[x])if(v!=fa)dfs1(v,x),siz[x]+=siz[v];
}
std::set<int> S;
void dfs2(int x,int fa){
	auto it=*--S.lower_bound(dfn[x]);
	if(it+siz[rev[it]]>dfn[x])S.erase(it);
	S.insert(dfn[x]);
	ans=std::max(ans,SZ(S)-1);
	for(auto v:e1[x])if(v!=fa)dfs2(v,x);
	if(it+siz[rev[it]]>dfn[x])S.insert(it);
	S.erase(dfn[x]);
}
void MAIN(){
	int n,x;read(n);
	for(int i=1;i<=n;++i)e1[i].clear(),e2[i].clear();
	for(int i=2;i<=n;++i)read(x),e1[x].pb(i);
	for(int i=2;i<=n;++i)read(x),e2[x].pb(i);
	id=0,ans=0,S={0},dfs1(1,0),dfs2(1,0);
	printf("%d\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}