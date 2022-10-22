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
int n,q,a[MAXN],b[MAXN],c[MAXN];
set<int> Set[MAXN];
struct Segment{
	#define ls rt<<1
	#define rs rt<<1|1 
	int Max[MAXN<<2],lmax[MAXN<<2],rmax[MAXN<<2],Min[MAXN<<2],sum[MAXN<<2],tag[MAXN<<2];
	inl void pushup(int rt){
		Max[rt]=max(Max[ls],Max[rs]);
		Min[rt]=min(Min[ls],Min[rs]);
		if(Min[ls]<Min[rs]){
			sum[rt]=sum[ls];
			lmax[rt]=lmax[ls];
			rmax[rt]=max(rmax[ls],Max[rs]);
		}
		else if(Min[ls]>Min[rs]){
			sum[rt]=sum[rs];
			lmax[rt]=max(lmax[rs],Max[ls]);
			rmax[rt]=rmax[rs];
		}
		else {
			sum[rt]=sum[ls]+sum[rs]+max(rmax[ls],lmax[rs]);
			lmax[rt]=lmax[ls];
			rmax[rt]=rmax[rs];
		}
	}
	inl void pushdown(int rt){
		Min[ls]+=tag[rt],Min[rs]+=tag[rt];
		tag[ls]+=tag[rt],tag[rs]+=tag[rt];
		tag[rt]=0;
	}
	inl void build(int rt,int l,int r){
		if(l==r) {
			Max[rt]=lmax[rt]=c[l];
			Min[rt]=b[l];
			return ;
		}
		int mid=l+r>>1;
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(rt);
	}
	inl void update1(int rt,int l,int r,int L,int R,int k){
		if(l>=L && r<=R){
			Min[rt]+=k,tag[rt]+=k;
			return ;
		}
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(R<=mid) update1(ls,l,mid,L,R,k);
		else if(L>mid) update1(rs,mid+1,r,L,R,k);
		else update1(ls,l,mid,L,R,k),update1(rs,mid+1,r,L,R,k);
		pushup(rt);
	}
	inl void update2(int rt,int l,int r,int pos,int k){
		if(l==r){
			Max[rt]=lmax[rt]=k;
			return ;
		}
		if(tag[rt]) pushdown(rt);
		int mid=l+r>>1;
		if(pos<=mid) update2(ls,l,mid,pos,k);
		else update2(rs,mid+1,r,pos,k);
		pushup(rt);
	} 
	inl int query(){
		if(Min[1]==0) return n-lmax[1]-rmax[1]-sum[1];
		else return n-Max[1];
	}
}mjy;
inl void del(int x){
	if(!size(Set[x])) return ;
	mjy.update2(1,1,n,*Set[x].begin(),0);
	if(size(Set[x])>1) mjy.update1(1,1,n,*Set[x].begin(),*Set[x].rbegin()-1,-1);
}
inl void add(int x){
	if(!size(Set[x])) return ;
	mjy.update2(1,1,n,*Set[x].begin(),size(Set[x]));
	if(size(Set[x])>1) mjy.update1(1,1,n,*Set[x].begin(),*Set[x].rbegin()-1,1);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(q);
	rep(i,1,n) read(a[i]),Set[a[i]].insert(i);
	rep(i,1,2e5) {
		if(!size(Set[i])) continue;
		c[*Set[i].begin()]=size(Set[i]);
		b[*Set[i].begin()]++;
		b[*Set[i].rbegin()]--;
	}
	rep(i,1,n) b[i]+=b[i-1];
	mjy.build(1,1,n);
	printf("%d\n",mjy.query());
	rep(i,1,q){
		int p,x;
		read(p),read(x);
		del(a[p]);Set[a[p]].erase(p);add(a[p]);
		del(x);Set[x].insert(p);add(x);a[p]=x;
		printf("%d\n",mjy.query());
	}
	return 0;
}