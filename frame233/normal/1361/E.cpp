#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=100005;
std::vector<int> e[N],son[N];
bool vis[N],in[N],flag,can[N];int dfn[N],id,to[N];
std::multiset<int> s[N];
void dfs1(int x){
	vis[x]=1,dfn[x]=++id,in[x]=1;
	for(auto v:e[x])if(!vis[v])dfs1(v);else if(dfn[v]>dfn[x]||!in[v])flag=1;
	in[x]=0;
}
void dfs2(int x){
	vis[x]=1;
	for(auto v:e[x]){
		if(!vis[v]){
			dfs2(v),son[x].pb(v);
			if(SZ(s[v])>SZ(s[x]))s[x].swap(s[v]);
			for(auto it:s[v])s[x].insert(it);
		}
		else s[x].insert(v);
	}
	s[x].erase(x);
	if(SZ(s[x])==1)to[x]=*s[x].begin();else to[x]=0;
}
void dfs3(int x){can[x]=can[to[x]];for(auto v:son[x])dfs3(v);}
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)e[i].clear(),son[i].clear(),s[i].clear();
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x].pb(y);
	int rt=-1;
	for(int t=0;t<80;++t){
		int x=rnd()%n+1;flag=0,memset(vis,0,n+3),id=0,dfs1(x);
		if(!flag){rt=x;break;}
	}
	if(rt==-1)return puts("-1"),void();
	memset(vis,0,n+3),id=0,dfs2(rt),to[rt]=rt,can[rt]=1,dfs3(rt);
	std::vector<int> ans;for(int i=1;i<=n;++i)if(can[i])ans.pb(i);
	if(SZ(ans)*5<n)return puts("-1"),void();
	for(auto it:ans)printf("%d ",it);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}