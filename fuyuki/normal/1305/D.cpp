#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e3+1;
int n,m,mod,ans,tag[N],dis[N][N],pre[N],dep[N];
vector<int>e[N];
int a[N*N],b[N*N],id[N*N];
int root,DEP[N],FA[N];
V koishi(int u,int fa){
	FA[u]=fa;
	for(int v:e[u])if(v!=fa)
		DEP[v]=DEP[u]+1,koishi(v,u);
}
V input(){
	cin>>n;int x,y;
//	cin>>root;
	FOR(i,2,n){
		cin>>x>>y;
		e[x].push_back(y),e[y].push_back(x);
	}
}
V dfs(int u){
	for(int v:e[u])if(v!=pre[u])
		dep[v]=dep[u]+1,pre[v]=u,dfs(v);
}
I ask(int x,int y){
	if(x==y||dis[x][y])return dis[x][y];
	if(dep[x]<dep[y])swap(x,y);
	return dis[x][y]=ask(pre[x],y)+1;
}
B cmp(int x,int y){return ask(a[x],b[x])>ask(a[y],b[y]);}
V init(){
	dfs(1);
	FOR(i,1,n)FOR(j,i+1,n)m++,a[m]=i,b[m]=j,id[m]=m;
	sort(id+1,id+1+m,cmp);
}
I lca(int x,int y){
	while(DEP[x]>DEP[y])x=FA[x];
	while(DEP[x]<DEP[y])y=FA[y];
	while(x^y)x=FA[x],y=FA[y];
	return x;
}
I query(int x,int y){
	cout<<"? "<<x<<' '<<y<<'\n',cout.flush();
	cin>>x;
	return x;
//	return lca(x,y);
}
B find(int u,int fa,int x,int y){
	if(u==x||u==y)return true;
	for(int v:e[u])if(v!=fa&&find(v,u,x,y))
		return true;
	return false;
}
V cha(int u,int fa){
	tag[u]=1;
	for(int v:e[u])if(v!=fa)cha(v,u);
}
V work(){
//	koishi(root,0);
	int x,y,p;
	FOR(i,1,m){
		x=a[id[i]],y=b[id[i]];
		if(tag[x]||tag[y])continue;
		p=query(x,y);
		for(int v:e[p])if(find(v,p,x,y))
			cha(v,p);
	}
	FOR(i,1,n)if(!tag[i])
		cout<<"! "<<i,cout.flush();
}
int main(){
//	freopen("test.in","r",stdin);
//	for(int T=getint();T--;){
		input();
		init();
		work();
//	}
	return 0;
}