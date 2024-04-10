#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005;typedef std::pair<int,int> pi;
std::vector<int> e[N];int anc[N][20],X[N],Y[N],Z[N],dfn[N],id,dep[N];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1,dfn[x]=++id;
	anc[x][0]=fa;for(int i=1;i<20;++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto v:e[x])if(v!=fa)dfs1(v,x);
}
int lca(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=19;i>=0;--i)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;--i)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int jump(int x,int k){
	for(int i=19;i>=0;--i)if(k>>i&1)x=anc[x][i];
	return x;
}
std::set<int> S;std::vector<int> v1[N],v2[N];bool mark[N];
void dfs2(int x){
	for(auto it:v1[x])S.insert(it);
	std::vector<int> vec;
	for(auto it:v2[x]){
		auto IT=S.find(it);
		if(IT!=S.end())S.erase(IT),vec.pb(it);
	}
	for(auto v:e[x])dfs2(v);
	for(auto it:v1[x])if(S.find(it)!=S.end())S.clear(),mark[x]=1;
	for(auto it:vec)S.insert(it);
}
int s[N];void dfs3(int x){s[x]=mark[x];for(auto v:e[x])dfs3(v),s[x]+=s[v];}
int main(){
	int n,m;read(n,m);
	for(int i=2,x;i<=n;++i)read(x),e[x].pb(i);
	dfs1(1,0);
	for(int i=1;i<=m;++i){
		read(X[i],Y[i]),Z[i]=lca(X[i],Y[i]);
		if(dfn[X[i]]>dfn[Y[i]])std::swap(X[i],Y[i]);
		if(dep[X[i]]+dep[Y[i]]-dep[Z[i]]*2==1)return puts("-1"),0;
		if(X[i]==Z[i]){
			int u=jump(Y[i],dep[Y[i]]-dep[X[i]]-1);
			v1[u].pb(i),v2[Y[i]].pb(i);
		}
	}
	dfs2(1),dfs3(1);int all=s[1];bool flag=1;
	for(int i=1;i<=m;++i)if(X[i]!=Z[i])flag&=s[X[i]]+s[Y[i]]<all;
	if(!flag)++all;
	printf("%d\n",all);
	return 0;
}