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
const int N=500010;
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
int a[N];
int ans[N];
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	int g=0;
	FOR(i,0,29) {
		int c=0;
		FOR(j,1,n) if((a[j]>>i)&1) ++c;
		g=gcd(c,g);
	}
	int m=0;
	FOR(i,1,n) if(g%i==0) ans[++m]=i;
//	cerr << ": " << endl;
	FOR(i,1,m) printf("%d%c",ans[i]," \n"[i==m]);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}