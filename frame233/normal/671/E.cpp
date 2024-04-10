#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp max(_Tp a,_Tp b){return a<b?b:a;}
typedef long long ll;
const int N=100005;
int w[N],g[N],n,k;
ll sg[N],sw[N],A[N],B[N];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
ll mb[N<<2],mc[N<<2],tag[N<<2];
inline void pushup(int x){mb[x]=max(mb[ls(x)],mb[rs(x)]),mc[x]=max(mc[ls(x)],mc[rs(x)]);}
void build(int l,int r,int cur){
	if(l==r)return mb[cur]=B[l],mc[cur]=B[l],void();
	int mid=(l+r)>>1;
	build(l,mid,ls(cur)),build(mid+1,r,rs(cur));
	pushup(cur);
}
inline void upd(int cur,ll C){tag[cur]+=C,mc[cur]+=C;}
inline void pushdown(int cur){if(tag[cur])upd(ls(cur),tag[cur]),upd(rs(cur),tag[cur]),tag[cur]=0;}
void Update(int L,int R,int C,int l,int r,int cur){
	if(L<=l&&r<=R)return upd(cur,C);
	int mid=(l+r)>>1;pushdown(cur);
	if(L<=mid)Update(L,R,C,l,mid,ls(cur));
	if(R>mid)Update(L,R,C,mid+1,r,rs(cur));
	pushup(cur);
}
int _;
ll ask(int L,int R,ll mx,int l,int r,int cur){
	if(l==r){
		if(mb[cur]+k>=mx)_=max(_,l);
		return max(mx,mc[cur]);
	}
	int mid=(l+r)>>1;pushdown(cur);
	if(L<=l&&r<=R){
		ll tp=max(mx,mc[ls(cur)]);
		mb[rs(cur)]+k>=tp?ask(L,R,tp,mid+1,r,rs(cur)):ask(L,R,mx,l,mid,ls(cur));
		return max(mx,mc[cur]);
	}
	if(L<=mid)mx=ask(L,R,mx,l,mid,ls(cur));
	if(R>mid)mx=ask(L,R,mx,mid+1,r,rs(cur));
	return mx;
}
int st[N],top;
int main(){
	read(n,k);
	for(int i=1;i<n;++i)read(w[i]);
	for(int i=1;i<=n;++i)read(g[i]);
	for(int i=1;i<=n;++i)sw[i]=sw[i-1]-w[i],sg[i]=sg[i-1]+g[i],A[i]=sg[i]+sw[i],B[i]=sg[i]+sw[i-1];
	build(1,n,1),st[0]=n+1,st[top=1]=n;
	int ans=0;
	for(int l=n;l>=1;--l){
		while(top&&A[l-1]<=A[st[top]]){
			if(top>1)Update(st[top-1],n,A[st[top-1]]-A[st[top]],1,n,1);
			--top;
		}
		if(top)Update(st[top],n,A[l-1]-A[st[top]],1,n,1);
		st[++top]=l-1;
		int L=0,R=top,mid;
		while(L<R)mid=(L+R+1)>>1,A[l-1]-A[st[mid]]>k?L=mid:R=mid-1;
		_=0,ask(l,std::min(n,st[L]),-1e18,1,n,1),ans=max(ans,_-l+1);
	}
	printf("%d\n",ans);
	return 0;
}