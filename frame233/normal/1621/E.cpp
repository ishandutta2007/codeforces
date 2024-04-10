#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
int a[N],d[N],t[N];std::vector<int> b[N];ll s[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int tag[N<<2],mn[N<<2];
void build(int l,int r,int u){
	tag[u]=0;if(l==r)return mn[u]=d[l],void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
	mn[u]=std::min(mn[ls(u)],mn[rs(u)]);
}
inline void upd(int u,int C){tag[u]+=C,mn[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void Update(int L,int R,int C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	mn[u]=std::min(mn[ls(u)],mn[rs(u)]);
}
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)read(a[i]),t[i]=a[i];
	std::sort(t+1,t+n+1);int pos=std::unique(t+1,t+n+1)-t-1;
	memset(d,0,(pos+3)<<2);
	for(int i=1;i<=n;++i)++d[std::lower_bound(t+1,t+pos+1,a[i])-t];
	for(int i=1;i<=m;++i){
		int k;read(k);b[i].resize(k);s[i]=0;
		for(auto &&it:b[i])read(it),s[i]+=it;
		int lim=std::lower_bound(t+1,t+pos+1,(s[i]+k-1)/k)-t;
		--d[lim];
	}
	for(int i=pos;i>=1;--i)d[i]+=d[i+1];
	build(1,pos+1,1);
	for(int i=1;i<=m;++i){
		int k=SZ(b[i]),lim=std::lower_bound(t+1,t+pos+1,(s[i]+k-1)/k)-t;
		Update(1,lim,1,1,pos+1,1);
		for(auto it:b[i]){
			int p=std::lower_bound(t+1,t+pos+1,(s[i]-it+k-2)/(k-1))-t;
			Update(1,p,-1,1,pos+1,1);
			if(mn[1]>=0)putchar('1');else putchar('0');
			Update(1,p,1,1,pos+1,1);
		}
		Update(1,lim,-1,1,pos+1,1);
	}
	putchar('\n');
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}