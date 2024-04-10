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
void print(ll x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(ll x,char ch)
{
	print(x),pc(ch,false);
}
inline ll read(){
	re ll t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,A[100002],B[100002],I[200002],O[200002],cnt,tot,pl[200002],head[100002];
ll w,la,C[100002],mx[800002],lmx[800002],rmx[800002],D[800002],dep[800002],mn[800002],tg[800002];
struct edge{int to,next,w;}e[200002];
inline void add(re int x,re int y,re int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}
inline void dfs(re int x,re int y){
	pl[++tot]=x,I[x]=tot;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dep[e[i].to]=dep[x]+C[e[i].w];
			dfs(e[i].to,x),pl[++tot]=x;
		}
	O[x]=tot;
}
inline void pu(re int p){
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
	D[p]=max(D[p<<1],D[p<<1|1]);
	D[p]=max(D[p],lmx[p<<1]+mx[p<<1|1]);
	D[p]=max(D[p],mx[p<<1]+rmx[p<<1|1]);
	lmx[p]=max(lmx[p<<1],lmx[p<<1|1]);
	lmx[p]=max(lmx[p],mx[p<<1]-2*mn[p<<1|1]);
	rmx[p]=max(rmx[p<<1],rmx[p<<1|1]);
	rmx[p]=max(rmx[p],mx[p<<1|1]-2*mn[p<<1]);
}
inline void build(re int p,re int l,re int r){
	if(l==r){
		mx[p]=mn[p]=dep[pl[l]],lmx[p]=rmx[p]=-mx[p],D[p]=0;
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(p);
}
inline void Add(re int p,re ll x){
	mx[p]+=x,mn[p]+=x,tg[p]+=x;
	lmx[p]-=x,rmx[p]-=x;
}
inline void pd(re int p){
	if(tg[p])Add(p<<1,tg[p]),Add(p<<1|1,tg[p]),tg[p]=0;
}
inline void add(re int p,re int l,re int r,re int x,re int y,re ll z){
	if(l>=x&&r<=y)return Add(p,z);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	pu(p);
}
int main(){
	n=read(),m=read(),w=read();
	for(re int i=1;i<n;++i)A[i]=read(),B[i]=read(),C[i]=read(),add(A[i],B[i],i),add(B[i],A[i],i);
	dfs(1,1),build(1,1,tot);
	for(re int i=1;i<n;++i)if(I[A[i]]<I[B[i]])swap(A[i],B[i]);
	while(m--){
		re int x=(la+read())%(n-1)+1;re ll y=(la+read())%w;
		add(1,1,tot,I[A[x]],O[A[x]],y-C[x]),C[x]=y;
		printnum(la=D[1],'\n');
	}pc('o',1);
}