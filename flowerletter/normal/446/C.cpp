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
const int MAXN = 3e5+10;
const int Mod = 1e9+9;
int n,m,opt,l,r,a[MAXN],f[MAXN];
struct Seg{
	int lazy1,lazy2,sum,size;
}tree[MAXN<<2];
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
inl void upd(int &a,int b){a+=b,a=(a>=Mod)?(a-Mod):a;}
inl int add(int a,int b){return a+b>=Mod?(a+b-Mod):(a+b);}
inl int mul(int a,int b){return 1ll*a*b%Mod;}
inl int fib(int a,int b,int len){
	if(len==1) return a;
	else if(len==2) return b;
	else return add(mul(f[len-2],a),mul(f[len-1],b));
}
inl int fibsum(int a,int b,int len){
	return add(fib(a,b,len+2),Mod-b);
}
inl void pushup(int root){tree[root].sum=add(tree[lson].sum,tree[rson].sum);}
inl void givetag(int root,int lazy1,int lazy2){
	upd(tree[root].lazy1,lazy1);
	upd(tree[root].lazy2,lazy2); 
	upd(tree[root].sum,fibsum(lazy1,lazy2,tree[root].size));
}
inl void pushdown(int root){
	givetag(lson,tree[root].lazy1,tree[root].lazy2);
	givetag(rson,fib(tree[root].lazy1,tree[root].lazy2,tree[lson].size+1)
				,fib(tree[root].lazy1,tree[root].lazy2,tree[lson].size+2));
	tree[root].lazy1=tree[root].lazy2=0;
}
inl void build(int root,int l,int r){
	tree[root].size=r-l+1;
	if(l==r) return tree[root].sum=a[l],void();
	int mid=l+r>>1;
	build(lson,l,mid),build(rson,mid+1,r);
	pushup(root);
}
inl void update(int root,int l,int r,int L,int R){
	if(l>=L && r<=R) return givetag(root,f[l-L+1],f[l-L+2]),void();
	if(tree[root].lazy1) pushdown(root);
	int mid=l+r>>1;
	if(R<=mid) update(lson,l,mid,L,R);
	else if(L>mid) update(rson,mid+1,r,L,R);
	else update(lson,l,mid,L,R),update(rson,mid+1,r,L,R);
	pushup(root);
}
inl int query(int root,int l,int r,int L,int R){
	if(l>=L && r<=R) return tree[root].sum;
	if(tree[root].lazy1) pushdown(root);
	int mid=l+r>>1;
	if(R<=mid) return query(lson,l,mid,L,R);
	else if(L>mid) return query(rson,mid+1,r,L,R);
	else return add(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
int main(){
	read(n),read(m);
	rep(i,1,n) read(a[i]);
	f[1]=1;rep(i,2,n+9) f[i]=add(f[i-1],f[i-2]);
	build(1,1,n);
	rep(i,1,m){
		read(opt),read(l),read(r);
		if(opt==1) update(1,1,n,l,r);
		else if(opt==2) printf("%d\n",query(1,1,n,l,r));
	}
	return 0;
}