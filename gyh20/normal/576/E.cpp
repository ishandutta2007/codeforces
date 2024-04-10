#include<cstdio>
#define re register
const int Mxdt=1000000;	// 
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
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
int n,m,cnt,head[2000002],q,k,a[500002],b[500002],nxt[500002],c[500002],d[500002],lst[500002],col[500002];
struct DSU{
	int fa[500002],sz[500002],stkx[500002],stky[500002],tp,tg,tmp;
	bool w[500002];
	inline void pre(){for(re int i=1;i<=n;++i)fa[i]=i,sz[i]=1;}
	inline int root(re int x){
		if(x==fa[x])return x;
		tmp^=w[x]^1;
		return root(fa[x]);
	}
	inline void merge(re int x,re int y){
		tmp=0,x=root(x),y=root(y);
		if(x==y)return;
		if(sz[x]>sz[y])x^=y^=x^=y;
		fa[x]=y,sz[y]+=sz[x],w[x]=tmp,stkx[++tp]=x,stky[tp]=y;
	}
	inline int ask(re int x){tmp=0;root(x);return tmp;}
	inline void undo(re int x){
		while(tp^x){
			fa[stkx[tp]]=stkx[tp],sz[stky[tp]]-=sz[stkx[tp]];
			w[stkx[tp]]=0,--tp;
		}
	}
}D[51];
struct edge{int to,next;}e[10000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void ins(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return add(p,z);
	re int mid=l+r>>1;
	if(x<=mid)ins(p<<1,l,mid,x,y,z);
	if(y>mid)ins(p<<1|1,mid+1,r,x,y,z);
}
inline void solve(re int p,re int l,re int r){
	re int L[52],mid=l+r>>1;
	for(re int i=1;i<=k;++i)L[i]=D[i].tp;
	for(re int i=head[p];i;i=e[i].next)D[col[e[i].to]].merge(a[e[i].to],b[e[i].to]);
	if(l==r){
		re int x=d[l];D[x].tmp=0;
		if(D[x].root(a[c[l]])==D[x].root(b[c[l]])&&!D[x].tmp)pc('N',0),pc('O',0);
		else pc('Y',0),pc('E',0),pc('S',0),col[c[l]]=x;pc('\n',0);
		ins(1,1,q,l+1,nxt[l],c[l]);
	}
	else solve(p<<1,l,mid),solve(p<<1|1,mid+1,r);
	for(re int i=1;i<=k;++i)D[i].undo(L[i]);
}
int main(){
	n=read(),m=read(),k=read(),q=read();
	for(re int i=1;i<=k;++i)D[i].pre();
	for(re int i=1;i<=m;++i)a[i]=read(),b[i]=read(),lst[i]=q+1;
	for(re int i=1;i<=q;++i)c[i]=read(),d[i]=read();
	for(re int i=q;i;--i)nxt[i]=lst[c[i]]-1,lst[c[i]]=i;
	solve(1,1,q);
	pc('o',1);
}