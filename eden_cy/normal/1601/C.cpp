#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])
namespace Eddd {
	inline char sc() {
		return getchar();
		static const int LEN=100000;
		static char Buf[LEN],*OP=Buf,*ED=Buf;
		if(OP==ED) ED=(OP=Buf)+fread(Buf,1,LEN,stdin);
		return *OP++;
	}
	template<class T> void rd(T &x) {
		static int c,f;x=f=0;
		while(c=sc(),c<48) if(c=='-') f=1;
		do x=(x<<3)+(x<<1)+(c^48);
		while(c=sc(),c>47);if(f) x=-x;
	}
	template<class T> void pt(T x) {
		if(x<0) putchar('-'),x=-x;
		else if(!x) putchar('0');
		static int Stk[30],tp=0;
		for(; x; x/=10) Stk[tp++]=x%10;
		while(tp) putchar(Stk[--tp]^48);
	}
	template<class T> void ptk(const T &x) {
		pt(x);putchar(' ');
	}
	template<class T> void ptn(const T &x) {
		pt(x);putchar('\n');
	}
	template<class T> bool chkmi(T &x,const T &y) {
		return x>y?x=y,true:false;
	}
	template<class T> bool chkmx(T &x,const T &y) {
		return x<y?x=y,true:false;
	}
	template<class T> T gcd(const T &x,const T &y) {
		return y?gcd(y,x%y):x;
	}
}
using namespace Eddd;

typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=1e6+50;
const int Mod=1e9+7;
ll Fast(ll x,ll b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
ll gcd(ll a,ll b) {
	return b?gcd(b,a%b):a;
}

bool __;

#define ls Tr[p][0]
#define rs Tr[p][1]
#define lson L,mid,ls
#define rson mid+1,R,rs
const int V=4e7;

int Tr[V][2],sum[V],tid;

void ins(int L,int R,int &p,int x) {
	int q=p;p=++tid;
	Tr[p][0]=Tr[q][0];
	Tr[p][1]=Tr[q][1];
	sum[p]=sum[q]+1;
	if(L==R) return ;
	int mid=L+R>>1;
	if(x<=mid) ins(lson,x);
	else ins(rson,x);
}
int qry(int L,int R,int p,int l,int r) {
	if(l>r) return 0;
	if(!p) return 0;
	if(L==l && R==r) return sum[p];
	int mid=L+R>>1;
	if(r<=mid) return qry(lson,l,r);
	else if(l>mid) return qry(rson,l,r);
	else return qry(lson,l,mid)+qry(rson,mid+1,r);
}
//int qry(int L,int R,int p,int q,int l,int r) {
//	if(l>r) return 0;
//	if(!p || !q) return sum[q]-sum[p];
//	if(L==l && R==r) return sum[q]-sum[p];
//	int mid=L+R>>1;
//	if(r<=mid) return qry(lson,l,r);
//	else if(l>mid) return qry(rson,l,r);
//	else return qry(lson,l,mid)+qry(rson,mid+1,r);
//}
int lt[N];
int a[N],b[N];
int c[N<<1];
int K;

int n=1e6,m=1e6;
ll res=0;
void divide(int L,int R,int l,int r) {
	if(L>R) return ;
	int p=L+R>>1;
	int mn=2e9,q=l;
	int t=qry(1,K,lt[l],b[p]+1,K)+(qry(1,K,lt[n],1,b[p]-1)-qry(1,K,lt[l],1,b[p]-1));
	FOR(i,l,r) {
		if(t<mn) mn=t,q=i;
		if(a[i+1]<b[p]) {
			t--;
		} else if(a[i+1]>b[p]) {
			t++;
		}
	}
	res+=mn;
	divide(L,p-1,l,q);
	divide(p+1,R,q,r);
}
void solve() {
	tid=0;
	res=0;
	rd(n);rd(m);
	
	FOR(i,1,n) rd(a[i]);
	FOR(i,1,m) rd(b[i]);
	
	K=0;
	FOR(i,1,n) c[++K]=a[i];
	FOR(i,1,m) c[++K]=b[i];
	sort(c+1,c+K+1);
	K=unique(c+1,c+K+1)-c-1;
	FOR(i,1,n) a[i]=lower_bound(c+1,c+K+1,a[i])-c;
	FOR(i,1,m) b[i]=lower_bound(c+1,c+K+1,b[i])-c;
	
	
	sort(b+1,b+m+1);
	lt[0]=0;
	FOR(i,1,n) {
		res+=qry(1,K,lt[i-1],a[i]+1,K);
		ins(1,K,lt[i]=lt[i-1],a[i]);
	}
	
	divide(1,m,0,n);
	printf("%lld\n",res);
}
bool ___;
int main() {
//	cerr << (&__-&___)/1024.0/1024 << endl;
	int T;
	rd(T);
	while(T--) {
		solve();
	}
	return 0;
}