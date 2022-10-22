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
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 12e4+10;
int n,q,a[MAXN];ll ans[MAXN];
struct Pro{int l,r,id;}Q[MAXN];
vector<Pro> mjy[MAXN];
struct Node{
	int Min,cnt,minlazy;
	ll ans,anslazy;
}tree[MAXN<<2];
template<class T>struct Stack{
	T buf[MAXN];
	int Top;
	Stack():Top(0){}
	inl bool empty(){return Top==0;}
	inl T top(){return buf[Top];}
	inl void push(T x){buf[++Top]=x;}
	inl void pop(){Top--;}
	inl T nth(int x){return buf[Top-x+1];}
	inl void clear(){Top=0;}
};
Stack<int> Smax,Smin;
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
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
inl void PushUp(int root){
	if(tree[lson].Min<tree[rson].Min) tree[root].Min=tree[lson].Min,tree[root].cnt=tree[lson].cnt;
	else if(tree[lson].Min>tree[rson].Min) tree[root].Min=tree[rson].Min,tree[root].cnt=tree[rson].cnt;
	else tree[root].Min=tree[lson].Min,tree[root].cnt=tree[lson].cnt+tree[rson].cnt;
	tree[root].ans=tree[lson].ans+tree[rson].ans;
}
inl void tagans(int root,int k){
	tree[root].ans+=1ll*k*tree[root].cnt;
	tree[root].anslazy+=k;
}
inl void tagmin(int root,int k){
	tree[root].Min+=k;
	tree[root].minlazy+=k;
}
inl void PushDown(int root){
	if(tree[root].minlazy) tagmin(lson,tree[root].minlazy),tagmin(rson,tree[root].minlazy),tree[root].minlazy=0;
	if(tree[root].anslazy) {
		if(tree[lson].Min==tree[root].Min) tagans(lson,tree[root].anslazy);
		if(tree[rson].Min==tree[root].Min) tagans(rson,tree[root].anslazy);
		tree[root].anslazy=0;
	}
}
inl void build(int root,int l,int r){
	tree[root].Min=l,tree[root].cnt=1;
	if(l^r) build(lson,l,Mid),build(rson,Mid+1,r);
}
inl void update(int root,int l,int r,int L,int R,int k){
	if(l>=L && r<=R) return tagmin(root,k),void();
	PushDown(root);
	if(R<=Mid) update(lson,l,Mid,L,R,k);
	else if(L>Mid) update(rson,Mid+1,r,L,R,k);
	else update(lson,l,Mid,L,R,k),update(rson,Mid+1,r,L,R,k);
	PushUp(root);
}
inl ll query(int root,int l,int r,int L,int R){
	if(l>=L && r<=R) return tree[root].ans;
	PushDown(root);
	if(R<=Mid) return query(lson,l,Mid,L,R);
	else if(L>Mid) return query(rson,Mid+1,r,L,R);
	else return query(lson,l,Mid,L,R)+query(rson,Mid+1,r,L,R);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);rep(i,1,n) read(a[i]);
	read(q);rep(i,1,q) read(Q[i].l),read(Q[i].r),Q[i].id=i,mjy[Q[i].r].pb(Q[i]);
	build(1,1,n);
	rep(i,1,n){
		tagmin(1,-1);
		while(!Smax.empty() && a[i]>a[Smax.top()]) update(1,1,n,Smax.nth(2)+1,Smax.top(),a[i]-a[Smax.top()]),Smax.pop();
		Smax.push(i);
		while(!Smin.empty() && a[i]<a[Smin.top()]) update(1,1,n,Smin.nth(2)+1,Smin.top(),a[Smin.top()]-a[i]),Smin.pop();
		Smin.push(i);
		tagans(1,1);
		for(auto x:mjy[i]) ans[x.id]=query(1,1,n,x.l,x.r);
	}
	rep(i,1,q) printf("%lld\n",ans[i]);
	return 0;
}