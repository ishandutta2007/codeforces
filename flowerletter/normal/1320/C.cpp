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
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
#define int long long
const int MAXN = 2e5+10;
int n,m,p;
struct Node{
	int x,y,z;
}s[MAXN];
struct NODE{
	int x,c;
}a[MAXN],b[MAXN];
struct Seg{
	ll Max,lazy;
}tree[MAXN<<2];
ll ans=-1e18;
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
inl bool cmp(Node a,Node b){
	return a.x<b.x;
}
inl bool CMP(NODE a,NODE b){
	return a.x<b.x;
}
inl bool Cmp(NODE a,int b){
	return a.x<=b;
}
inl void pushup(int root){
	tree[root].Max=max(tree[lson].Max,tree[rson].Max);
}
inl void givetag(int root,ll k){
	tree[root].Max+=k;
	tree[root].lazy+=k;
}
inl void pushdown(int root){
	givetag(lson,tree[root].lazy),givetag(rson,tree[root].lazy);
	tree[root].lazy=0;
} 
inl void build(int root,int l,int r){
	if(l==r) return tree[root].Max=-b[l].c,void();
	int mid=l+r>>1;
	build(lson,l,mid),build(rson,mid+1,r);
	pushup(root);
}
inl void update(int root,int l,int r,int L,int R,ll k){
	if(l>=L && r<=R) return givetag(root,k),void();
	if(tree[root].lazy) pushdown(root);
	int mid=l+r>>1;
	if(R<=mid) update(lson,l,mid,L,R,k);
	else if(L>mid) update(rson,mid+1,r,L,R,k);
	else update(lson,l,mid,L,R,k),update(rson,mid+1,r,L,R,k);
	pushup(root);
 }
inl void add(int k,ll val){
	int pos=lower_bound(b+1,b+m+1,k,Cmp)-b-1;
	if(pos<m) update(1,1,m,pos+1,m,val);
}
signed main(){
	read(n),read(m),read(p);
	rep(i,1,n) read(a[i].x),read(a[i].c);
	rep(i,1,m) read(b[i].x),read(b[i].c);
	rep(i,1,p) read(s[i].x),read(s[i].y),read(s[i].z);
	sort(s+1,s+p+1,cmp),sort(a+1,a+n+1,CMP),sort(b+1,b+m+1,CMP);
	int now=1;
	build(1,1,m);
	rep(i,1,n) {
		while(now<=m && s[now].x<a[i].x) add(s[now].y,s[now].z),now++;
		ylmax(ans,tree[1].Max-a[i].c);
	}
	printf("%lld\n",ans);
	return 0;
}