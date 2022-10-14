#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e5+1,INF=0x3f3f3f3f;
V cmax(int&x,int y){if(x-y>>31)x=y;}
ll k,lim;
set<P>mp;
vector<int>e[N];
int T,n,rt,now,tot,cnt,minn,flag,id[N];
int dep[N],val[N],siz[N],vis[N],tmp[N];
struct node{
	int x,y,w;
	I operator<(const node&u)const{return w<u.w;}
};
vector<node>t[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V input(){
	cin>>n>>k,cnt=n>>1;
	FOR(i,2,n)add_edge(getint(),getint());
}
V getrt(int u,int fa=0){
	int maxn(siz[u]=1);
	for(int v:e[u])if(v!=fa)getrt(v,u),cmax(maxn,siz[v]),siz[u]+=siz[v];
	if(cmax(maxn,n-siz[u]),maxn<minn)minn=maxn,rt=u;
}
V init(int u,int fa){
	siz[u]=1,val[u]=u,lim+=dep[u]=dep[fa]+1,minn++,id[u]=now;
	for(int v:e[u])if(v!=fa&&(init(v,u),siz[u]+=siz[v],val[v])){
		if(!val[u])val[u]=val[v],minn++;
		else t[now].push_back((node){val[u],val[v],dep[u]<<1}),val[u]=0,minn--;
	}
}
V init(){
	minn=INF,getrt(1),minn=0;
	for(int v:e[rt])init(now=v,rt),sort(t[v].begin(),t[v].end()),mp.insert(P(siz[v],v));
}
V solve(int x,int y){
	k-=dep[x]+dep[y],lim-=dep[x]+dep[y],vis[x]=vis[y]=1,cnt--,cout<<x<<' '<<y<<'\n';
}
V solve(const node&u){k+=u.w,solve(u.x,u.y);}
V find(int u,int w,int fa){
	val[u]=!vis[u]*u;
	for(int v:e[u])if(v!=fa&&(find(v,w,u),val[v])){
		if(!val[u])val[u]=val[v];
		else if(flag&&dep[u]==w)solve(val[u],val[v]),k+=w<<1,flag=0;
	}
}
V dfs(int u,int fa=0){
	if(!vis[u])tmp[++tot]=u;
	for(int v:e[u])if(v!=fa)dfs(v,u);
}
V work(){
	if(lim<k||k<minn||(k-lim&1))return void(cout<<"NO\n");
	cout<<"YES\n",flag=1;
	for(int u;lim!=k;){
		u=(*--mp.end()).second,mp.erase(P(siz[u],u)),mp.insert(P(siz[u]-=2,u));
		if(lim-t[u].back().w>=k)solve(t[u].back()),t[u].pop_back();
		else find(u,lim-k>>1,rt);
	}
	dfs(rt),tot>>=1;
	FOR(i,1,tot)solve(tmp[i],tmp[i+tot]);
}
int main(){
	input();
	init();
	work();
	return 0;
}