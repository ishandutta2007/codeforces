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

const int N=600010;
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
#define ls p<<1
#define rs p<<1|1
#define lson L,mid,ls
#define rson mid+1,R,rs

vector<int> T[N<<2];
void ins(int L,int R,int p,int l,int r,int x) {
	if(L==l && R==r) {
		T[p].push_back(x);
		return ;
	}
	int mid=L+R>>1;
	if(r<=mid) ins(lson,l,r,x);
	else if(l>mid) ins(rson,l,r,x);
	else ins(lson,l,mid,x),ins(rson,mid+1,r,x);
}
vector<int> W;
void qry(int L,int R,int p,int x) {
	if(T[p].size()) {
		for(auto x: T[p]) {
			W.push_back(x);
		}
		T[p].clear();
	}
	if(L==R) return ;
	int mid=L+R>>1;
	if(x<=mid) qry(lson,x);
	else qry(rson,x);
}

int a[N],b[N];
vector<int> G[N];
int f[N][2];
int fr[N];
pii Q[N*2];
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) scanf("%d",&b[i]);
	FOR(i,1,n) FOR(j,0,1) f[i][j]=-1;
	FOR(i,1,n) G[i+b[i]].push_back(i);
	FOR(i,1,n) ins(0,n,1,i-a[i],i,i);
	f[0][1]=0;
	int l=1,r=0;
	Q[++r]=make_pair(0,0);
	while(l<=r) {
		pii q=Q[l++];
		int x=q.fi;
		int v=f[x][q.se];
		if(q.se==0) {
			W.clear();
			qry(0,n,1,x);
			for(auto y: W) {
				if(f[y][1]==-1) {
					f[y][1]=v+1;
					fr[y]=x;
					Q[++r]=make_pair(y,1);
				}
			}
		} else {
			for(auto y: G[x]) {
				if(f[y][0]==-1) {
					f[y][0]=v;
					Q[++r]=make_pair(y,0);
				}
			}
		}
	}
	printf("%d\n",f[n][1]);
	if(f[n][1]!=-1) {
		int x=n;
		FOR(j,1,f[n][1]) {
			printf("%d%c",fr[x]," \n"[j==f[n][1]]);
			if(j<f[n][1]) {
				x=fr[x]+b[fr[x]];
			} else {
				x=fr[x];
			}
		}
	}
	return 0;
}