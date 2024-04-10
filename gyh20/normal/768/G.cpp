#include<bits/stdc++.h>
#define re register
using namespace std;
int rt[200002],ls[20000002],rs[20000002],n,tot,sz[20000002],dfn[200002],top[200002],R,head[200002],cnt,dep[200002],siz[200002],tim,fa[200002],pl[200002],ans[200002],A,B;
struct edge{int to,next;}e[400002];
const int Mxdt=100000;	// 
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
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void ins(re int &p,re int l,re int r,re int x,re int y){
	++tot,ls[tot]=ls[p],rs[tot]=rs[p],sz[tot]=sz[p]+y,p=tot;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x,y);
	else ins(rs[p],mid+1,r,x,y);
}
inline void add(re int &p,re int l,re int r,re int x,re int y){
	if(!p)p=++tot;
	sz[p]+=y;
	if(l==r)return;
	re int mid=l+r>>1;
	if(x<=mid)add(ls[p],l,mid,x,y);
	else add(rs[p],mid+1,r,x,y);
}
inline int findqq(re int p,re int q,re int z,re int l,re int r,re int x){
	if(!(sz[p]-sz[q]-sz[z]))return 0;
	if(l==r){
		if(sz[p]-sz[q]-sz[z])return l;
		return 0;
	}
	re int mid=l+r>>1;
	if(x<=mid)return findqq(ls[p],ls[q],ls[z],l,mid,x);
	re int xx=findqq(rs[p],rs[q],rs[z],mid+1,r,x);
	if(xx)return xx;
	return findqq(ls[p],ls[q],ls[z],l,mid,x);
}
inline int findhj(re int p,re int q,re int z,re int l,re int r,re int x){
	if(!(sz[p]-sz[q]-sz[z]))return 0;
	if(l==r){
		if(sz[p]-sz[q]-sz[z])return l;
		return 0;
	}
	re int mid=l+r>>1;
	if(x>mid)return findhj(rs[p],rs[q],rs[z],mid+1,r,x);
	re int xx=findhj(ls[p],ls[q],ls[z],l,mid,x);
	if(xx)return xx;
	return findhj(rs[p],rs[q],rs[z],mid+1,r,x);
}
inline void dfs(re int x,re int y){
	dfn[x]=++tim,siz[x]=1,fa[x]=y,pl[dfn[x]]=x;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}
inline int ask(re int l,re int r,re int x,re int ext=0,re int D=n+1){
	if(l>r)return A;
	re int xx=findqq(rt[r],rt[l-1],rt[D],1,n<<1,x),yy=findhj(rt[r],rt[l-1],rt[D],1,n<<1,x),s=A;
	xx-=ext,yy-=ext;
	if(xx>0)s=min(s,max(A-(xx>>1),B+(xx>>1)));if(yy>0)s=min(s,max(A-(yy>>1),B+(yy>>1)));
	return s;
}
inline void dfs1(re int x,re int y){
	int MX=0,SEC=0,MN=n+1,tmp;
	tmp=siz[fa[x]];
	if(x^R)siz[fa[x]]=n-siz[x];
	for(re int i=head[x];i;i=e[i].next){
		if(siz[e[i].to]>siz[MX])SEC=MX,MX=e[i].to;
		else if(siz[e[i].to]>siz[SEC])SEC=e[i].to;
		if(siz[e[i].to]<siz[MN])MN=e[i].to;
	}
	if(siz[MX]==siz[SEC]||siz[MX]==siz[MN])ans[x]=siz[MX];
	else{
		re int dlt=siz[MX]-siz[MN];
		A=siz[MX],B=siz[MN];
		if(MX==fa[x])ans[x]=max(siz[SEC],min(ask(1,n+1,dlt+(siz[x]<<1),siz[x]<<1,0),min(ask(1,dfn[x]-1,dlt),ask(dfn[x]+siz[x],n,dlt,0,0))));
		else ans[x]=max(siz[SEC],ask(dfn[MX],dfn[MX]+siz[MX]-1,dlt,0,0));
	}
	siz[fa[x]]=tmp;
	if(x^fa[x])add(rt[n+1],1,n<<1,siz[x]<<1,1);
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs1(e[i].to,x); 
	if(x^fa[x])add(rt[n+1],1,n<<1,siz[x]<<1,-1);
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
int main(){
	n=read();
	R=1;
	for(re int i=1,x,y;i<=n;++i){
		x=read(),y=read();
		if(!x||!y)R=x+y;
		else add(x,y),add(y,x);
	}
	dfs(R,R);
	for(re int i=1;i<=n;++i)rt[i]=rt[i-1],ins(rt[i],1,n<<1,siz[pl[i]]<<1,1);siz[n+1]=n+1;
	dfs1(R,R);
	for(re int i=1;i<=n;++i)printnum(ans[i],'\n');
	return pc('o',1);
}