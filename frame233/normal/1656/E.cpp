#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
std::vector<int> e[N];int a[N];
void dfs(int x,int fa,int col){
	a[x]=col?SZ(e[x]):-SZ(e[x]);
	for(auto v:e[x])if(v!=fa)dfs(v,x,!col);
}
void MAIN(){
	int n;read(n);for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs(1,0,0);for(int i=1;i<=n;++i)printf("%d%c",a[i]," \n"[i==n]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}