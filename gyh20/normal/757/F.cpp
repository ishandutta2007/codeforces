#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define re register
using namespace std;
const int Mxdt=200000;	//
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read() {
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,head[600002],fa[600002][22],val[600002],rd[600002],dep[600002],L[600002],q[600002],hd,tl,cnt,head1[600002],m,pos;
bool vv[600002];
long long dis[600002];
struct edge {
	int to,next;
	long long w;
} e[1000002],e1[1000002];
inline void add(re int x,re int y,re int w) {
	e1[++cnt]=(edge) {y,head1[x],w};
	head1[x]=cnt;
}
deque <int> qq;
void spfa(register int s){
    memset(dis,127,sizeof(dis));
	qq.push_front(s);
	dis[s]=0;
	vv[s]=1;
	while(!qq.empty()){
		int r=qq.front();
		qq.pop_front();
		vv[r]=0;
        for(register int i=head1[r];i;i=e1[i].next){
			if(dis[e1[i].to]>dis[r]+e1[i].w){
				dis[e1[i].to]=dis[r]+e1[i].w;
				if(!vv[e1[i].to]){
			vv[e1[i].to]=1;
				if(!qq.empty()&&dis[e1[i].to]<dis[qq.front()])
			    qq.push_front(e1[i].to);
			    else qq.push_back(e1[i].to);	
				}
			}
		}
	}
}
inline void add(re int x,re int y) {
	e[++cnt]=(edge) {y,head[x]};
	head[x]=cnt,++rd[y];
}
inline void add(re int x) {
	dep[x]=dep[fa[x][0]]+1;
	for(re int i=1; i<=L[dep[x]]; ++i)fa[x][i]=fa[fa[x][i-1]][i-1];
}
inline int lca(re int x,re int y) {
	if(dep[x]<dep[y])x^=y^=x^=y;
	re int t=dep[x]-dep[y];
	for(; t; t^=(t&(-t)))x=fa[x][L[t&(-t)]];
	if(x==y)return x;
	for(re int i=L[dep[x]]; ~i; --i)if(fa[x][i]^fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
vector<int>v[600002];
inline void dfs(re int x) {
	for(re int i=0; i<v[x].size(); ++i)dfs(v[x][i]),val[x]+=val[v[x][i]];
}
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x) {
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch) {
	print(x),pc(ch,false);
}
int main() {
	re int s;
	n=read();m=read();s=read();
	dep[s]=1;
	for(re int i=2; i<=n; ++i)L[i]=L[i>>1]+1;
	for(re int i=1,x,y,z; i<=m; ++i)x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	spfa(s);cnt=0;
	for(re int i=1;i<=n;++i){
		for(re int j=head1[i];j;j=e1[j].next)if(dis[e1[j].to]==dis[i]+e1[j].w)add(i,e1[j].to);
	}
	hd=1;
	q[tl=1]=s;
	while(hd<=tl) {
		re int x=q[hd++];
		if(!fa[x][0])fa[x][0]=s;
		add(x);if(fa[x][0]^x)v[fa[x][0]].push_back(x);++val[x];
		for(re int i=head[x]; i; i=e[i].next) {
			if(!fa[e[i].to][0])fa[e[i].to][0]=x;
			else if(x==s)fa[e[i].to][0]=s;
			else if(fa[e[i].to][0]^s)fa[e[i].to][0]=lca(fa[e[i].to][0],x);
			if(!(--rd[e[i].to]))q[++tl]=e[i].to;
		}
	}
	dfs(s);val[0]=-1;
	for(re int i=1; i<=n; ++i)if((i^s)&&(val[i]>val[pos]))pos=i;
	printf("%d",val[pos]);
}