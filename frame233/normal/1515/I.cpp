#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005;
typedef long long ll;
struct node{
	ll c;int w,v,id;
	inline bool operator < (const node &o)const{return v==o.v?w<o.w:v>o.v;}
}a[N];
int to[N],n;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
struct Node{ll a[20],b[20],c[20];}f[N<<2];
inline void pushup(int u){
	int x=ls(u),y=rs(u);
	for(int i=0;i<20;++i)f[u].a[i]=f[x].a[i]+f[y].a[i],f[u].b[i]=f[x].b[i]+f[y].b[i],f[u].c[i]=std::min(f[x].c[i],f[x].a[i]+f[y].c[i]);
}
void rb(int u,int p){
	for(int i=0;i<20;++i){
		f[u].a[i]=f[u].b[i]=0,f[u].c[i]=2e18;
		if(a[p].w<(1<<i))f[u].a[i]+=1LL*a[p].w*a[p].c,f[u].b[i]+=1LL*a[p].v*a[p].c;
		else if(a[p].c&&a[p].w<(1<<(i+1)))f[u].c[i]=a[p].w;
	}
}
void build(int l,int r,int u){
	if(l==r)return rb(u,l);
	int mid=(l+r)>>1;
	build(l,mid,ls(u)),build(mid+1,r,rs(u)),pushup(u);
}
void upd(int pos,int l,int r,int u){
	if(l==r)return rb(u,l);
	int mid=(l+r)>>1;
	pos<=mid?upd(pos,l,mid,ls(u)):upd(pos,mid+1,r,rs(u));
	pushup(u);
}
int k,pos;
ll ask1(int L,int R,ll rest,ll pre,int l,int r,int u){
	if(l==r){
		if(pre+f[u].a[k]>rest)chmin(pos,l);
		return f[u].a[k];
	}
	int mid=(l+r)>>1;
	if(L<=l&&r<=R){
		if(pre+f[ls(u)].a[k]>rest)ask1(L,R,rest,pre,l,mid,ls(u));
		else ask1(L,R,rest,pre+f[ls(u)].a[k],mid+1,r,rs(u));
		return f[u].a[k];
	}
	ll sum=0;
	if(L<=mid)sum+=ask1(L,R,rest,pre+sum,l,mid,ls(u));
	if(R>mid)sum+=ask1(L,R,rest,pre+sum,mid+1,r,rs(u));
	return sum;
}
ll ask2(int L,int R,ll rest,ll pre,int l,int r,int u){
	if(l==r){
		if(pre+f[u].c[k]<=rest)chmin(pos,l);
		return f[u].a[k];
	}
	int mid=(l+r)>>1;
	if(L<=l&&r<=R){
		if(pre+f[ls(u)].c[k]<=rest)ask2(L,R,rest,pre,l,mid,ls(u));
		else ask2(L,R,rest,pre+f[ls(u)].a[k],mid+1,r,rs(u));
		return f[u].a[k];
	}
	ll sum=0;
	if(L<=mid)sum+=ask2(L,R,rest,pre+sum,l,mid,ls(u));
	if(R>mid)sum+=ask2(L,R,rest,pre+sum,mid+1,r,rs(u));
	return sum;
}
ll ask3(int L,int R,int l,int r,int u){
	if(L<=l&&r<=R)return f[u].b[k];
	int mid=(l+r)>>1;
	return (L<=mid?ask3(L,R,l,mid,ls(u)):0)+(R>mid?ask3(L,R,mid+1,r,rs(u)):0);
}
ll ask4(int L,int R,int l,int r,int u){
	if(L<=l&&r<=R)return f[u].a[k];
	int mid=(l+r)>>1;
	return (L<=mid?ask4(L,R,l,mid,ls(u)):0)+(R>mid?ask4(L,R,mid+1,r,rs(u)):0);
}
int main(){
	int q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i].c,a[i].w,a[i].v),a[i].id=i;
	std::sort(a+1,a+n+1),build(1,n,1);
	for(int i=1;i<=n;++i)to[a[i].id]=i;
	int opt,x,y;ll r;
	while(q--){
		read(opt);
		if(opt==1)read(x,y),a[to[y]].c+=x,upd(to[y],1,n,1);
		else if(opt==2)read(x,y),a[to[y]].c-=x,upd(to[y],1,n,1);
		else{
			read(r);
			ll ans=0;
			for(int i=19,p=1;i>=0&&p<=n;--i){
				if(r<(1<<i))continue;
				k=i,pos=n,ask1(p,n,r,0,1,n,1),ask2(p,n,r,0,1,n,1);
				if(p<pos)ans+=ask3(p,pos-1,1,n,1),r-=ask4(p,pos-1,1,n,1);
				ll cnt=std::min((ll)a[pos].c,r/a[pos].w);
				ans+=cnt*a[pos].v,r-=cnt*a[pos].w;
				p=pos+1;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}