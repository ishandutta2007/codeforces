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
#define Mid (tree[root].l+tree[root].r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e5+10;
const int Mod = 1e9+7;
int n,a[MAXN],Set[MAXN],last[MAXN],L[MAXN],R[MAXN];
ll ans;
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
template<class T>inl void add(T &a,T b){a=a+b>=Mod?a+b-Mod:a+b;}
template<class T>inl void dec(T &a,T b){a=a-b<0?a-b+Mod:a-b;}
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
Stack<int> S1,S2;
struct Date{
	ll smax,smin,minmax,valmin;
	friend inl Date operator + (const Date a,const Date b) {
		return (Date){(a.smax+b.smax)%Mod,(a.smin+b.smin)%Mod,(a.minmax+b.minmax)%Mod,(a.valmin+b.valmin)%Mod};
	}
};
struct Node{
	int l,r;ll lazymin,lazymax;
	Date mjy; 
}tree[MAXN<<2];
inl ll cacl(int l,int r){return (1ll*(r-l+1)*(l+r)/2)%Mod;}
inl void build(int root,int l,int r){
	tree[root].l=l,tree[root].r=r;
	if(l^r) build(lson,l,Mid),build(rson,Mid+1,r); 
}
inl void mintag(int root,ll k){
	add(tree[root].lazymin,k);
	add(tree[root].mjy.smin,k*(tree[root].r-tree[root].l+1)%Mod);
	add(tree[root].mjy.valmin,k*cacl(tree[root].l,tree[root].r)%Mod);
	add(tree[root].mjy.minmax,k*tree[root].mjy.smax%Mod);
} 
inl void maxtag(int root,ll k){
	add(tree[root].lazymax,k);
	add(tree[root].mjy.smax,k*(tree[root].r-tree[root].l+1)%Mod);
	add(tree[root].mjy.minmax,k*tree[root].mjy.smin%Mod);
}
inl void PushDown(int root){
	if(tree[root].lazymin) mintag(lson,tree[root].lazymin),mintag(rson,tree[root].lazymin),tree[root].lazymin=0;
	if(tree[root].lazymax) maxtag(lson,tree[root].lazymax),maxtag(rson,tree[root].lazymax),tree[root].lazymax=0;
}
inl void PushUp(int root){
	tree[root].mjy=tree[lson].mjy+tree[rson].mjy;
}
inl void update(int root,int L,int R,ll k,int type){
	if(tree[root].l>=L && tree[root].r<=R) return type?maxtag(root,k):mintag(root,k),void();
	PushDown(root);
	if(R<=Mid) update(lson,L,R,k,type);
	else if(L>Mid) update(rson,L,R,k,type);
	else update(lson,L,R,k,type),update(rson,L,R,k,type);
	PushUp(root);
}
inl Date query(int root,int L,int R){
	if(tree[root].l>=L && tree[root].r<=R) return tree[root].mjy;
	PushDown(root);
	if(R<=Mid) return query(lson,L,R);
	else if(L>Mid) return query(rson,L,R);
	else return query(lson,L,R)+query(rson,L,R);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]);
	memcpy(Set,a,sizeof(a));
	sort(Set+1,Set+n+1);
	int *end=unique(Set+1,Set+n+1);
	rep(i,1,n) a[i]=lower_bound(Set+1,end,a[i])-Set;
	rep(i,1,n) L[i]=last[a[i]]+1,last[a[i]]=i;
	rep(i,1,n) last[i]=n+1 ;
	per(i,n,1) R[i]=last[a[i]]-1,last[a[i]]=i;
	int Pos=1;build(1,1,n);
	rep(i,1,n){
		while(!S1.empty() && L[i]>=L[S1.top()]) update(1,S1.nth(2)+1,S1.top(),-L[S1.top()],1),S1.pop();
		update(1,S1.top()+1,i,L[i],1);S1.push(i);
		while(!S2.empty() && R[i]<=R[S2.top()]) update(1,S2.nth(2)+1,S2.top(),-R[S2.top()],0),S2.pop();
		update(1,S2.top()+1,i,R[i],0);S2.push(i);
		ylmax(Pos,L[i]);
		Date res=query(1,Pos,i);
		add(ans,res.valmin),add(ans,res.smax*i%Mod);
		dec(ans,cacl(Pos,i)*i%Mod),dec(ans,res.minmax);
	}
	printf("%d\n",ans);
	return 0;
}