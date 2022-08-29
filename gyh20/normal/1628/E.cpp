#include<bits/stdc++.h>
#define re register
#define ll int
using namespace std;
const int Mxdt=300000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int t,n,m,a[1000002],ans,cnt,hyx[1200002],L[1200002],tim,fst[600002],lst[600002],F[1200002],tot,dep[1000002],head[1000002],siz[1000002],top[1000002],son[1000002],ca[1200002],cb[1200002],ffa[1000002],tg[1200002],fa[1200002],fb[1200002],st[22][1200002];
ll d[600002],fd[1200002],cd[1200002],val[1200002];
struct node{
	int x,y,z;
	bool operator <(const node A)const{return z<A.z;}
}p[300002];
struct edge{
	int to,next,w;
}e[1200002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline void dfs(re int x,re int y){
	hyx[++tim]=x;
	lst[x]=tim;
	fst[x]=tim;
	ffa[x]=y,dep[x]=dep[y]+1,siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			d[e[i].to]=d[x]+e[i].w;
			dfs(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;hyx[++tim]=x;
			lst[x]=tim;
		} 
}
inline void dfs1(re int x,re int y){
	top[x]=y;
	if(son[x])dfs1(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to!=son[x]&&e[i].to!=ffa[x])
			dfs1(e[i].to,e[i].to);
}
inline int lca(re int x,re int y) {
	if(x==y)return x;
	if(fst[x]>fst[y])x^=y^=x^=y;
	x=fst[x];
	y=lst[y];
	int tmp=L[y-x];
	if(dep[st[tmp][x]]<dep[st[tmp][y-(1<<tmp)+1]])return st[tmp][x];
	else return st[tmp][y-(1<<tmp)+1];
}
inline ll dis(re int x,re int y){
	if(x==0&&y==0)return -2;
	if(x==0||y==0)return -1;
	return d[x]+d[y]-(d[lca(x,y)]<<1);
}
inline void pu(re int &X,re int &Y,re ll &d,re int A,re int B,re ll d1,re int C,re int D,re ll d2){
	if(d1>d2)X=A,Y=B,d=d1;
	else X=C,Y=D,d=d2;
	re ll tmp=dis(A,C);
	if(tmp>d)d=tmp,X=A,Y=C;
	tmp=dis(A,D);
	if(tmp>d)d=tmp,X=A,Y=D;
	tmp=dis(B,C);
	if(tmp>d)d=tmp,X=B,Y=C;
	tmp=dis(B,D);
	if(tmp>d)d=tmp,X=B,Y=D; 
}
inline void build(re int p,re int l,re int r){
	cd[p]=-2;
	if(l==r){
		fa[p]=fb[p]=l,fd[p]=0;
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(fa[p],fb[p],fd[p],fa[p<<1],fb[p<<1],fd[p<<1],fa[p<<1|1],fb[p<<1|1],fd[p<<1|1]);
}
inline void Cov(re int x,re int y){
	if(y==2)ca[x]=cb[x]=0,cd[x]=-2,tg[x]=2;
	else ca[x]=fa[x],cb[x]=fb[x],cd[x]=fd[x],tg[x]=1;
}
inline void pd(re int p){
	if(tg[p]){
		Cov(p<<1,tg[p]),Cov(p<<1|1,tg[p]);
		tg[p]=0;
	}
}
inline void cg(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y){
		Cov(p,z);
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y,z);
	if(y>mid)cg(p<<1|1,mid+1,r,x,y,z);
	pu(ca[p],cb[p],cd[p],ca[p<<1],cb[p<<1],cd[p<<1],ca[p<<1|1],cb[p<<1|1],cd[p<<1|1]);
}
inline int root(re int x){
	return x==F[x]?x:F[x]=root(F[x]);
}
inline int Rand(re int x){
	return ((rand()<<15)|(rand()))%x+1;
}
int main(){
	n=read(),m=read();srand(time(0));
	for(re int i=1;i<=n;++i)F[i]=i;
	for(re int i=1;i<n;++i)p[i].x=read(),p[i].y=read(),p[i].z=read();
	sort(p+1,p+n);
	tot=n;
	for(re int i=1;i<n;++i){
		++tot,val[tot]=p[i].z;
		add(tot,root(p[i].x),val[tot]-val[root(p[i].x)]),add(tot,root(p[i].y),val[tot]-val[root(p[i].y)]);
		F[root(p[i].x)]=F[root(p[i].y)]=F[tot]=tot;
	}
	dfs(tot,tot),dfs1(tot,tot);
	for(re int i=2;i<=tim;++i)L[i]=L[i>>1]+1;
	for(re int i=1;i<=tim;++i)st[0][i]=hyx[i];
	for(re int i=1;i<=21;++i)
		for(re int j=1;j+(1<<i)-1<=tim;++j){
			re int x=st[i-1][j],y=st[i-1][j+(1<<i-1)];
			if(dep[x]<dep[y])st[i][j]=x;
			else st[i][j]=y;
		}
	build(1,1,n);
	while(m--){
		re int o=read(),l,r,x;
		if(o<=2){
			l=read(),r=read();
			if(l>r)swap(l,r);
			cg(1,1,n,l,r,o);
		}
		else{
			x=read();
			re ll D=max(dis(x,ca[1]),dis(x,cb[1]));
			if(D<=0)puts("-1");
			else printf("%d\n",D>>1);
		}
	}
}