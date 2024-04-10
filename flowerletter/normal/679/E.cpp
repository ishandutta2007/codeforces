/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
const int MAXN = 1e5 + 10; 
int n,q,opt,l,r,x,a[MAXN];
struct Node {
	ll S[15]; 
	inl void init(){
		ll nw=1;S[0]=nw;
		rep(i,1,11) nw*=42,S[i]=nw;
	}
	inl ll val(ll x){
		return *lower_bound(S,S+12,x)-x;
	}
}hlt;
struct Segment{
	#define ls rt<<1
	#define rs rt<<1|1
	ll Min[MAXN<<2],tag1[MAXN<<2],tag2[MAXN<<2];
	inl void pushup(int rt){Min[rt]=min(Min[ls],Min[rs]);}
	inl void pushdown(int rt){
		if(tag1[rt]) {
			tag1[ls]=tag1[rs]=tag1[rt];
			Min[ls]=Min[rs]=hlt.val(tag1[rt]);
			tag2[ls]=tag2[rs]=tag1[rt]=0;
		}
		if(tag2[rt]) {
			if(tag1[ls]) tag1[ls]+=tag2[rt];
			else tag2[ls]+=tag2[rt];
			if(tag1[rs]) tag1[rs]+=tag2[rt];
			else tag2[rs]+=tag2[rt];
			Min[ls]-=tag2[rt],Min[rs]-=tag2[rt];
			tag2[rt]=0;
		}
	}
	inl void build(int rt,int l,int r){
		if(l==r) {
			Min[rt]=hlt.val(a[l]);
			tag2[rt]=a[l];
			return ;
		}
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(rt);
	}
	inl void cover(int rt,int l,int r,int L,int R,ll k){
		if(l>=L && r<=R) {
			Min[rt]=hlt.val(k);
			tag1[rt]=k;
			tag2[rt]=0;
			return ;
		}
		int mid=l+r>>1;pushdown(rt);
		if(R<=mid) cover(ls,l,mid,L,R,k);
		else if(L>mid) cover(rs,mid+1,r,L,R,k);
		else cover(ls,l,mid,L,R,k),cover(rs,mid+1,r,L,R,k);
		pushup(rt);
	}
	inl void add(int rt,int l,int r,int L,int R,ll k){
		if(l>=L && r<=R) {
			if(tag1[rt]) tag1[rt]+=k;
			else tag2[rt]+=k; 
			Min[rt]-=k;
			return ;
		}
		int mid=l+r>>1;pushdown(rt);
		if(R<=mid) add(ls,l,mid,L,R,k);
		else if(L>mid) add(rs,mid+1,r,L,R,k);
		else add(ls,l,mid,L,R,k),add(rs,mid+1,r,L,R,k);
		pushup(rt);
	}
	inl bool check(int rt,int l,int r){
		if(Min[rt]>=0) return Min[rt]==0;
		if(l==r){
			Min[rt]=hlt.val(tag1[rt]+tag2[rt]);
			return Min[rt]==0;
		}
		int mid=l+r>>1;pushdown(rt);
		check(ls,l,mid),check(rs,mid+1,r);
		pushup(rt);
		return Min[rt]==0;
	}
	inl ll query(int rt,int l,int r,int pos){
		if(l==r) return tag1[rt]+tag2[rt];
		int mid=l+r>>1;pushdown(rt);
		if(pos<=mid) return query(ls,l,mid,pos);
		else return query(rs,mid+1,r,pos);
	}
	#undef ls 
	#undef rs
}mjy;
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(q); 
	rep(i,1,n) read(a[i]);
	hlt.init(),mjy.build(1,1,n);
	rep(i,1,q) {
		read(opt);
		if(opt==1) read(x),printf("%lld\n",mjy.query(1,1,n,x));
		else if(opt==2) {
			read(l),read(r),read(x);
			mjy.cover(1,1,n,l,r,x);
		}
		else if(opt==3) {
			read(l),read(r),read(x);
			do mjy.add(1,1,n,l,r,x); while(mjy.check(1,1,n));
		}
	}
	return 0;
}