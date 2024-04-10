#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
void print(ll x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(ll x,char ch)
{
	print(x),pc(ch,false);
}
int n,k,m,q,X[300002],Y[300002],W[300002],fa[600002],top[600002],F[600002],tot,siz[600002],son[600002],cnt,head[300002];
ll val[600002];
struct node{
	int x;ll dis;
	bool operator <(const node A)const{return dis>A.dis;}
}h[100002];
struct edge{int to,next,w;}e[600002];
struct Edge{int x,y;ll z;bool operator <(const Edge A)const{return z<A.z;};}E[600002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(top[x]<top[y])x=F[top[x]];
		else y=F[top[y]];
	}return x>y?x:y;
}
priority_queue<node>Q;
int main(){
	n=read(),m=read(),k=read(),q=read();
	for(re int i=1,x,y,z;i<=m;++i){
		X[i]=read(),Y[i]=read(),W[i]=read();
		add(X[i],Y[i],W[i]),add(Y[i],X[i],W[i]);
	}
	for(re int i=1;i<=n;++i)h[i].x=i,h[i].dis=1e18;
	for(re int i=1;i<=k;++i)h[i].dis=0,Q.push(h[i]);
	while(!Q.empty()){
		re node x=Q.top();Q.pop();
		if(x.dis!=h[x.x].dis)continue;
		for(re int i=head[x.x];i;i=e[i].next)
			if(x.dis+e[i].w<h[e[i].to].dis)
				h[e[i].to].dis=x.dis+e[i].w,Q.push(h[e[i].to]);
	}
	for(re int i=1;i<=m;++i)E[i]=(Edge){X[i],Y[i],h[X[i]].dis+h[Y[i]].dis+W[i]};
	sort(E+1,E+m+1);
	for(re int i=1;i<=n+n;++i)fa[i]=i;tot=n;
	for(re int i=1;i<=m;++i)
		if(root(E[i].x)^root(E[i].y)){
			re int x=root(E[i].x),y=root(E[i].y);
			++tot,F[x]=F[y]=fa[x]=fa[y]=tot,val[tot]=E[i].z,siz[tot]=siz[x]+siz[y]+1,son[tot]=siz[x]>siz[y]?x:y;
		}
	for(re int i=tot;i;--i)top[i]=i==son[F[i]]?top[F[i]]:i;
	while(q--)printnum(val[lca(read(),read())],'\n');pc('o',1);
}