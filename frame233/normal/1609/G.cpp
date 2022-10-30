#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,NN=105;typedef long long ll;typedef std::pair<ll,ll> pr;
ll aa[N],bb[N],a[N],b[N],A[N];
inline ll calc(int i,int j){return 1LL*i*b[j]+A[i];}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
ll s[N<<2],v[N<<2],tag[N<<2];int len[N<<2];int n,m,q;
inline void pushup(int u){s[u]=s[ls(u)]+s[rs(u)],v[u]=v[rs(u)];}
inline void upd(int u,ll C){s[u]+=C*len[u],v[u]+=C,tag[u]+=C;}
inline void pushdown(int u){if(tag[u])upd(ls(u),tag[u]),upd(rs(u),tag[u]),tag[u]=0;}
void build(int l,int r,int u){
	len[u]=r-l+1;if(l==r)return s[u]=b[l],v[u]=b[l],void();
	int mid=(l+r)>>1;build(l,mid,ls(u)),build(mid+1,r,rs(u));
	pushup(u);
}
void Update(int L,int R,ll C,int l,int r,int u){
	if(L<=l&&r<=R)return upd(u,C);
	int mid=(l+r)>>1;pushdown(u);
	if(L<=mid)Update(L,R,C,l,mid,ls(u));
	if(R>mid)Update(L,R,C,mid+1,r,rs(u));
	pushup(u);
}
ll ask(int L,int R,int l,int r,int u){
	if(L<=l&&r<=R)return s[u];
	int mid=(l+r)>>1;pushdown(u);
	return (L<=mid?ask(L,R,l,mid,ls(u)):0)+(R>mid?ask(L,R,mid+1,r,rs(u)):0);
}
int cur,pos;
void find(int L,int R,int l,int r,int u){
	if(l==r){
		ll V=v[u];
		if(pos==m-1&&cur*V+A[cur]<=(cur+1)*V+A[cur+1])pos=l-1;
		return;
	}
	int mid=(l+r)>>1;pushdown(u);
	if(L<=l&&r<=R){
		ll val=v[ls(u)];
		if(cur*val+A[cur]<=(cur+1)*val+A[cur+1])find(L,R,l,mid,ls(u));
		else find(L,R,mid+1,r,rs(u));
		return;
	}
	if(L<=mid)find(L,R,l,mid,ls(u));
	if(R>mid)find(L,R,mid+1,r,rs(u));
}
inline ll f(int n){return 1LL*n*(n+1)/2;}
int main(){
	read(n,m,q);
	for(int i=1;i<=n;++i)read(aa[i]);
	for(int i=1;i<=m;++i)read(bb[i]);
	for(int i=0;i<n;++i)a[i]=aa[i+1]-aa[i];
	for(int i=0;i<m;++i)b[i]=bb[i+1]-bb[i];
	for(int i=n-1;i>=0;--i)A[i]=A[i+1]+a[i];
	ll ans=0;for(int i=0;i<n;++i)ans+=a[i]*(n+m-i);
	for(int i=0;i<m;++i)ans+=b[i]*(n+m-i);
	int opt,k,d;build(0,m-1,1);
	while(q--){
		read(opt,k,d);
		if(opt==1){
			for(int i=0;i<k;++i)a[n-k+i]+=d,ans+=d*(n+m-(n-k+i));
			for(int i=n-1;i>=0;--i)A[i]=A[i+1]+a[i];
		}
		else ans+=1LL*d*(f(n+k)-f(n)),Update(m-k,m-1,d,0,m-1,1);
		int last=0;ll res=A[1];
		for(int i=1;i<n;++i){
			cur=i,pos=m-1;if(last+1<=m-1)find(last+1,m-1,0,m-1,1);
			if(last<pos)res+=1LL*i*ask(last+1,pos,0,m-1,1)+1LL*(pos-last)*A[i];
			last=pos;
		}
		if(last+1<m)res+=1LL*n*ask(last+1,m-1,0,m-1,1)+1LL*(m-1-last)*A[n];
		printf("%lld\n",ans-res-a[0]-ask(0,0,0,m-1,1));
	}
	return 0;
}