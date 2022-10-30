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
int a[N],fa[N];int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
std::vector<int> e[N];int Fa[N];
void dfs(int x,int fa){
	Fa[x]=fa;
	for(auto v:e[x])if(v!=fa)dfs(v,x);
}
int main(){
	int n,m;read(n,m);
	std::iota(fa+1,fa+n+1,1);
	for(int i=1,x,y;i<=m;++i){
		read(x,y);
		int u=find(x),v=find(y);
		if(u!=v)fa[u]=v,e[x].pb(y),e[y].pb(x);
	}
	int q;read(q);
	std::vector<std::vector<int>> ans;
	for(int i=1,x,y;i<=q;++i){
		read(x,y),++a[x],++a[y];
		dfs(y,0);std::vector<int> cur;
		for(int u=x;u;u=Fa[u])cur.pb(u);
		ans.pb(cur);
	}
	int cnt=0;for(int i=1;i<=n;++i)if(a[i]%2)++cnt;
	if(cnt)return printf("NO\n%d\n",cnt/2),0;
	puts("YES");
	for(const auto &v:ans){
		printf("%d ",SZ(v));
		for(auto it:v)printf("%d ",it);
		printf("\n");
	}
	return 0;
}