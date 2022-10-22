/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define ls rt<<1
#define rs rt<<1|1
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
const int MAXN = 2e5 + 10;
int n,m,a[MAXN],opt,l,r;
struct Segment{
	int Min[MAXN<<2],tag[MAXN<<2],size[MAXN<<2];
	ll sum[MAXN<<2]; 
	inl void pushup(int rt){
		sum[rt]=sum[ls]+sum[rs];
		Min[rt]=min(Min[ls],Min[rs]);
	} 
	inl void pushdown(int rt){
		tag[ls]=tag[rs]=tag[rt];
		sum[ls]=1ll*size[ls]*tag[rt];
		sum[rs]=1ll*size[rs]*tag[rt];
		Min[ls]=Min[rs]=tag[rt];
		tag[rt]=0;
	}
	inl void build(int rt,int l,int r){
		size[rt]=r-l+1;
		if(l==r){
			Min[rt]=sum[rt]=a[l];
			return ;
		}
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(rt); 
	}
	inl int lowerbound(int rt,int l,int r,int k){
		if(l==r) return sum[rt]<k?l:l+1;
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(Min[ls]>=k) return lowerbound(rs,mid+1,r,k);
		else return lowerbound(ls,l,mid,k);
	}
	inl void update(int rt,int l,int r,int L,int R,int k){
		if(l>=L && r<=R){
			Min[rt]=tag[rt]=k;
			sum[rt]=1ll*size[rt]*k;
			return ;
		}
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(R<=mid) update(ls,l,mid,L,R,k);
		else if(L>mid) update(rs,mid+1,r,L,R,k);
		else update(ls,l,mid,L,R,k),update(rs,mid+1,r,L,R,k);
		pushup(rt);
	}
	inl int query(int rt,int l,int r,int L,int R,int &nw){
		if(Min[rt]>nw) return 0;
		if(l>=L && r<=R && sum[rt]<=nw){
			nw-=sum[rt];
			return size[rt];
		}
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(R<=mid) return query(ls,l,mid,L,R,nw);
		else if(L>mid) return query(rs,mid+1,r,L,R,nw);
		else {
			int res=query(ls,l,mid,L,R,nw);
			return res+query(rs,mid+1,r,L,R,nw);
		}
		
	}
}mjy;
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,n) read(a[i]);
	mjy.build(1,1,n);
	rep(i,1,m){
		read(opt),read(l),read(r);
		if(opt==1){
			int pos=mjy.lowerbound(1,1,n,r);
			if(pos<=l) mjy.update(1,1,n,pos,l,r);
		}
		else {
			printf("%d\n",mjy.query(1,1,n,l,n,r)); 
		}
	}
	return 0;
}