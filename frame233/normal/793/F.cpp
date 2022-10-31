#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,NC=(1<<18)+5,inf=0x3f3f3f3f;
int a[N],ans[N];
struct node{int l,id;};
std::vector<node> Q[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
struct VAL{int mx1,mx2;};
struct TAG{int v,x;};
VAL v[NC];TAG tag[NC];
inline VAL merge(VAL a,const VAL &b){
	if(b.mx1>a.mx1)a.mx2=a.mx1,a.mx1=b.mx1;
	else if(b.mx1!=a.mx1&&b.mx1>a.mx2)a.mx2=b.mx1;
	if(b.mx2>a.mx2)a.mx2=b.mx2;
	return a;
}
void build(int l,int r,int u){
	tag[u]={inf,0};if(l==r)return v[u]={l,0},void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u)),v[u]=merge(v[ls(u)],v[rs(u)]);
}
inline void upd(int u,const TAG &C){if(v[u].mx1>=C.v)v[u].mx1=C.x,tag[u]={std::min(C.v,tag[u].v),C.x};}
inline void pushdown(int u){if(tag[u].v<inf)upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]={inf,0};}
void Update(int L,int R,const TAG &C,int l,int r,int u){
	if(v[u].mx1<C.v)return;
	if(L<=l&&r<=R&&v[u].mx2<C.v)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	v[u]=merge(v[ls(u)],v[rs(u)]);
}
int ask(int pos,int l,int r,int u){
	if(l==r)return v[u].mx1;
	int mid=(l+r)>>1;pushdown(u);
	return pos<=mid?ask(pos,l,mid,ls(u)):ask(pos,mid+1,r,rs(u));
}
int main(){
	int n,m;read(n,m);
	for(int i=1,x,y;i<=m;++i)read(x,y),a[y]=x;
	int q;read(q);
	for(int i=1,l,r;i<=q;++i)read(l,r),Q[r].pb({l,i});
	build(1,n,1);
	for(int i=1;i<=n;++i){
		int x=a[i];if(x)Update(1,x,{x,i},1,n,1);
		for(auto [l,id]:Q[i])ans[id]=ask(l,1,n,1);
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}