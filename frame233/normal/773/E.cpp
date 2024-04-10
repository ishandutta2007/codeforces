#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005,NC=(1<<20)+5,inf=0x3f3f3f3f;
int o[N],a[N],b[N],t[N],c[N],n;
void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
int ask(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int mn0[NC],mn1[NC],tag[NC];
inline void pushup(int u){mn0[u]=std::min(mn0[ls(u)],mn0[rs(u)]),mn1[u]=std::min(mn1[ls(u)],mn1[rs(u)]);}
inline void upd(int u,int C){tag[u]+=C,mn0[u]-=C,mn1[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void build(int l,int r,int u){
	mn0[u]=inf,mn1[u]=inf;if(l==r)return;
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	pushup(u);
}
void Modify(int pos,int l,int r,int u){
	if(l==r){
		int x=o[pos],v=ask(pos-1);
		mn0[u]=x==v?1:x<v?inf:x-v,mn1[u]=x==v?1:x>v?inf:v-x;
		return;
	}
	int mid=(l+r)>>1;pushdown(u);
	pos<=mid?Modify(pos,l,mid,ls(u)):Modify(pos,mid+1,r,rs(u));
	pushup(u);
}
int find0(int L,int R,int l,int r,int u){
	if(mn0[u]>0)return n+1;
	if(l==r)return l;
	int mid=(l+r)>>1;pushdown(u);
	if(L<=l&&r<=R)return mn0[ls(u)]<=0?find0(L,R,l,mid,ls(u)):find0(L,R,mid+1,r,rs(u));
	int ans=n+1;if(L<=mid)ans=find0(L,R,l,mid,ls(u));
	if(ans<n+1)return ans;
	return R>mid?find0(L,R,mid+1,r,rs(u)):n+1;
}
int find1(int L,int R,int l,int r,int u){
	if(mn1[u]>0)return n+1;
	if(l==r)return l;
	int mid=(l+r)>>1;pushdown(u);
	if(L<=l&&r<=R)return mn1[ls(u)]<=0?find1(L,R,l,mid,ls(u)):find1(L,R,mid+1,r,rs(u));
	int ans=n+1;if(L<=mid)ans=find1(L,R,l,mid,ls(u));
	if(ans<n+1)return ans;
	return R>mid?find1(L,R,mid+1,r,rs(u)):n+1;
}
int main(){
	read(n);for(int i=1;i<=n;++i)read(a[i]),t[i]=i;
	std::sort(t+1,t+n+1,[&](int x,int y){return a[x]<a[y];});
	for(int i=1;i<=n;++i)b[t[i]]=i;
	for(int i=1;i<=n;++i)o[b[i]]=a[i];
	build(1,n,1);
	for(int _=1;_<=n;++_){
		int x=a[_],p=b[_],v=ask(p-1);Modify(p,1,n,1);
		if(x>v){
			add(p,1);if(p<n)Update(p+1,n,1,1,n,1);
			int pos=p<n?find0(p+1,n,1,n,1):n+1;
			if(pos<=n){
				add(pos,-1);if(pos<n)Update(pos+1,n,-1,1,n,1);
				Modify(pos,1,n,1);
			}
		}
		else if(x<v){
			add(p,-1);if(p<n)Update(p+1,n,-1,1,n,1);
			int pos=p<n?find1(p+1,n,1,n,1):n+1;
			if(pos<=n){
				add(pos,1);if(pos<n)Update(pos+1,n,1,1,n,1);
				Modify(pos,1,n,1);
			}
		}
		printf("%d\n",ask(n));
	}
	return 0;
}