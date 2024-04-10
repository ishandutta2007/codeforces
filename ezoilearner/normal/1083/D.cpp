#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5,mod=1e9+7;
int n,top,ans,a[N],b[N],cnt[N],lst[N],pre[N],nxt[N],Mx[N],Mn[N],st[N],sum[N<<2][4],tag[N<<2][4];
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
#define mid (l+r>>1)
#define ls x<<1
#define rs x<<1|1
#define LS ls,l,mid
#define RS rs,mid+1,r
/*
sum 0: mx
sum 1: mn
sum 2: mx*mn
sum 3: mx*i
*/
inline void pushup(int x){
	rep(i,0,3)sum[x][i]=(sum[ls][i]+sum[rs][i])%mod;
}
inline void pushtag(int x,int l,int r,int tp,int v){
	sum[x][tp]=(ll)(r-l+1)*v%mod;
	sum[x][2]=(ll)sum[x][tp^1]*v%mod;
	if(!tp)sum[x][3]=(ll)(l+r)*(r-l+1)/2%mod*v%mod;
	tag[x][tp]=v;
}
inline void pushdown(int x,int l,int r){
	rep(tp,0,1)if(tag[x][tp])
		pushtag(LS,tp,tag[x][tp]),pushtag(RS,tp,tag[x][tp]),tag[x][tp]=0;
}
inline void update(int x,int l,int r,int L,int R,int tp,int v){
	if(L<=l&&R>=r)return pushtag(x,l,r,tp,v);
	pushdown(x,l,r);
	if(L<=mid)update(LS,L,R,tp,v);
	if(R>mid)update(RS,L,R,tp,v);
	pushup(x);
}
inline int query(int x,int l,int r,int L,int R,int tp){
	if(L<=l&&R>=r)return sum[x][tp];
	int ans=0;pushdown(x,l,r);
	if(L<=mid)ans=query(LS,L,R,tp);
	if(R>mid)(ans+=query(RS,L,R,tp))%=mod;
	return ans;
}
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]),b[i]=a[i];
	sort(b+1,b+1+n);int m=unique(b+1,b+1+n)-b-1;
	rep(i,1,n)a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	rep(i,1,n)pre[i]=lst[a[i]]+1,lst[a[i]]=i;
	rep(i,1,m)lst[i]=n+1;
	per(i,n,1)nxt[i]=lst[a[i]]-1,lst[a[i]]=i;
	per(i,n,1){
		while(top&&pre[i]>pre[st[top]])--top;
		Mx[i]=top?st[top]-1:n,st[++top]=i;
	}
	top=0;
	per(i,n,1){
		while(top&&nxt[i]<nxt[st[top]])--top;
		Mn[i]=top?st[top]-1:n,st[++top]=i;
	}
	int j=n;
	per(i,n,1){
		update(1,1,n,i,Mx[i],0,pre[i]);
		update(1,1,n,i,Mn[i],1,nxt[i]);
		++cnt[a[i]];
		while(cnt[a[i]]>1)--cnt[a[j]],--j;
		(ans+=(ll)i*query(1,1,n,i,j,1)%mod)%=mod;
		(ans+=mod-(ll)(i+j)*(j-i+1)/2%mod*i%mod)%=mod;
		(ans+=mod-query(1,1,n,i,j,2))%=mod;
		(ans+=query(1,1,n,i,j,3))%=mod;
	}
	return printf("%d\n",ans),0;
}