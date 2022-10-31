#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005,NC=(1<<20)+5;
int a[N],b[N],s[N],st[N],pre[N],nxt[N],c[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int mx[NC],tag[NC];
void build(int l,int r,int u){
	if(l==r)return mx[u]=s[l],void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u)),mx[u]=std::max(mx[ls(u)],mx[rs(u)]);
}
inline void upd(int u,int C){mx[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
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
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]),b[i]=b[i+n]=a[i];
	for(int i=1,top=0;i<=n+n;++i){
		while(top&&b[i]<b[st[top]])--top;
		if(i<=n)s[i]+=top+1;
		pre[i]=st[top];if(b[i]==b[st[top]])--top;
		c[i]=top,st[++top]=i;
	}
	st[0]=n+n+1;
	for(int i=n+n,top=0;i>=1;--i){
		while(top&&b[i]<b[st[top]])--top;
		if(i>n)s[i-n]+=top;
		nxt[i]=st[top],st[++top]=i;
	}
	build(1,n+n,1);int ans=mx[1],p=0;
	for(int i=1;i<n;++i){
		Update(i+n,i+n,c[i+n],1,n+n,1);
		int k=nxt[i];if(i+1<=k-1)Update(i+1,k-1,-1,1,n+n,1);
		k=pre[i+n],Update(k+1,i+n,1,1,n+n,1);
		int tmp=ask(i+1,i+n,1,n+n,1);
		if(tmp<ans)ans=tmp,p=i;
	}
	printf("%d %d\n",ans,p);
	return 0;
}