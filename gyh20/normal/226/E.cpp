#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,fa[22][100002],rt[100002],ls[2000002],rs[2000002],sz[2000002],dep[100002],L[100002],RT,head[100002],cnt,A[100002],B[100002],K[100002],Y[100002],q,m,a[100002],tot;
struct edge{int to,next;}e[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void ins(re int &p,re int l,re int r,re int x){
	++tot,ls[tot]=ls[p],rs[tot]=rs[p],sz[tot]=sz[p]+1,p=tot;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);
}
inline int ask(re int p,re int l,re int r,re int x,re int y){
	if(!sz[p])return 0;
	if(l>=x&&r<=y)return sz[p];
	re int mid=l+r>>1,s=0;
	if(x<=mid)s+=ask(ls[p],l,mid,x,y);
	if(y>mid)s+=ask(rs[p],mid+1,r,x,y);
	return s;
}
inline void dfs(re int x){
	for(re int i=1;fa[i-1][x];++i)fa[i][x]=fa[i-1][fa[i-1][x]];
	if(a[x])ins(rt[x],1,m,a[x]);
	for(re int i=head[x];i;i=e[i].next)dep[e[i].to]=dep[x]+1,fa[0][e[i].to]=x,rt[e[i].to]=rt[x],dfs(e[i].to);
}
inline int lca(re int x,re int y){
	if(dep[x]<dep[y])swap(x,y);
	re int d=dep[x]-dep[y];
	while(d)x=fa[L[d&(-d)]][x],d^=d&(-d);
	if(x==y)return x;
	for(re int i=18;~i;--i)if(fa[i][x]^fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
signed main(){
	n=read(),L[0]=-1;
	for(re int i=1,x;i<=n;++i){
		x=read(),L[i]=L[i>>1]+1;
		if(x)add(x,i);
		else RT=i;
	}
	m=read();
	for(re int i=1;i<=m;++i){
		if(read()==1)a[read()]=i;
		else A[i]=read(),B[i]=read(),K[i]=read(),Y[i]=read();
	}
	dep[RT]=1,dfs(RT);
	for(re int i=1;i<=m;++i)if(A[i]){
		re int x=A[i],y=B[i],z=lca(x,y),tmp=ask(rt[x],1,m,Y[i]+1,i),tmp1=ask(rt[fa[0][z]],1,m,Y[i]+1,i);
		if(a[x]<Y[i]+1||a[x]>i)++K[i];
		if(dep[x]-dep[z]+1-(tmp-tmp1)>=K[i]){
			for(re int j=18;~j;--j)if(dep[fa[j][x]]>=dep[z]&&dep[A[i]]-dep[fa[j][x]]+1-(tmp-ask(rt[fa[0][fa[j][x]]],1,m,Y[i]+1,i))<K[i])x=fa[j][x];
			x=fa[0][x];while(a[x]>=Y[i]+1&&a[x]<=i)x=fa[0][x];
			printnum((x==B[i])?-1:x,'\n');
		}
		else{
			K[i]-=dep[x]-dep[z]+1-(tmp-tmp1),tmp1=ask(rt[z],1,m,Y[i]+1,i);
			for(re int j=18;~j;--j)if(dep[fa[j][y]]>dep[z]&&dep[fa[j][y]]-dep[z]-(ask(rt[fa[j][y]],1,m,Y[i]+1,i)-tmp1)>=K[i])y=fa[j][y];
			printnum((y==B[i])?-1:y,'\n');
		}
	}pc('o',1);
}