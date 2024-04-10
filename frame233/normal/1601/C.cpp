#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
const int BUF_SIZ=1<<18;
char ibuf[BUF_SIZ],*iS=ibuf,*iT=ibuf;
#define getchar() (iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,BUF_SIZ,stdin)),iS==iT?EOF:*iS++)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005;
int a[N],b[N],t[N],st[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int v[N<<2],tag[N<<2];
inline void upd(int u,int C){v[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void build(int l,int r,int u){
	tag[u]=0,v[u]=l;
	if(l==r)return;
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	v[u]=std::min(v[ls(u)],v[rs(u)]);
}
int c[N];void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
int ask(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
int TP[N],POS,d[N];
void MAIN(){
	int n,m;read(n,m);
	POS=0;for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)t[i]=i,st[i]=1,TP[++POS]=a[i];
	std::sort(TP+1,TP+POS+1),POS=std::unique(TP+1,TP+POS+1)-TP-1;
	for(int i=1;i<=n;++i)d[i]=std::lower_bound(TP+1,TP+POS+1,a[i])-TP;
	memset(c,0,(n+3)<<2);
	long long ans=0;for(int i=n;i>=1;--i)ans+=ask(d[i]-1),add(d[i],1);
	for(int i=1;i<=m;++i)read(b[i]);
	std::sort(b+1,b+m+1),std::sort(t+1,t+n+1,[&](int x,int y){return a[x]<a[y];});
	build(0,n,1);int P=1;
	for(int i=1,p=1;i<=m;++i){
		while(p<=n&&a[t[p]]<b[i]){
			if(st[t[p]]==1)Update(t[p],n,-1,0,n,1);
			Update(0,t[p]-1,1,0,n,1),++p;
		}
		P=std::max(P,p);
		while(P<=n&&a[t[P]]==b[i]){
			if(st[t[P]]==1)Update(t[P],n,-1,0,n,1),st[t[P]]=0;
			++P;
		}
		ans+=v[1];
	}
	printf("%lld\n",ans);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}