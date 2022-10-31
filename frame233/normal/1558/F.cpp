#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N],b[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int mx[N<<2],tag[N<<2],n;
void build(int l,int r,int u){
	tag[u]=0,mx[u]=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,ls(u)),build(mid+1,r,rs(u));
}
inline void upd(int u,int C){mx[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Modify(int pos,int l,int r,int u){
	if(l==r)return mx[u]+=n-l,void();
	int mid=(l+r)>>1;pushdown(u);
	pos<=mid?Modify(pos,l,mid,ls(u)):Modify(pos,mid+1,r,rs(u));
	mx[u]=std::max(mx[ls(u)],mx[rs(u)]);
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	mx[u]=std::max(mx[ls(u)],mx[rs(u)]);
}
int ask(int L,int R,int l,int r,int u){
	if(L<=l&&r<=R)return mx[u];
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid&&R>mid)return std::max(ask(L,R,l,mid,ls(u)),ask(L,R,mid+1,r,rs(u)));
	return L<=mid?ask(L,R,l,mid,ls(u)):ask(L,R,mid+1,r,rs(u));
}
void MAIN(){
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	if(std::is_sorted(a+1,a+n+1))return puts("0"),void();
	for(int i=1;i<n;i+=2)if(a[i]>a[i+1])std::swap(a[i],a[i+1]);
	for(int i=1;i<=n;++i)b[a[i]]=i;
	build(1,n,1);
	int ans=0,mn=n,mx=n;
	for(int i=n;i>=1;--i){
		int p=b[i];mn=std::min(mn,p);while(mx&&a[mx]>=i)--mx;
		Modify(p,1,n,1),Update(1,p,-1,1,n,1),Update(p,n,1,1,n,1);
		if(mn<=mx)ans=std::max(ans,ask(mn,mx,1,n,1));
	}
	printf("%d\n",ans+1);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}