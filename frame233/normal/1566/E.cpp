#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
std::vector<int> e[N];
int st[N];bool flag;
void dfs(int x,int fa){
	st[x]=1;int qwq=0;
	for(auto v:e[x])if(v!=fa){
		dfs(v,x),++qwq;
		if(st[v]==1)st[x]=0;
	}
}
void MAIN(){
	int n;read(n);
	for(int i=1;i<=n;++i)e[i].clear();
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs(1,0);
	bool flag=0;int cnt=0,s=0;
	for(auto v:e[1])flag|=st[v]==1;
	for(int i=2;i<=n;++i)s+=st[i]==0,cnt+=st[i]==1;
	printf("%d\n",cnt-s+(flag?0:1));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}