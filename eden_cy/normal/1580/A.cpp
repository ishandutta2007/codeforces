#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;

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
}
using namespace Eddd;

const int Mod=998244353;

ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}

const int N=405;

char a[N][N];
int b[N][N];
void solve() {
	int n,m;
	rd(n);rd(m);
	FOR(i,1,n) scanf("%s",a[i]+1);
	FOR(i,1,n) FOR(j,1,m) b[i][j]=b[i-1][j]+a[i][j]-'0';
	int res=2e9;
	FOR(l,1,n) FOR(r,l+4,n) {
		int pr=2e9;
		FOR(i,4,m) {
			int c1=0,c2=0;
			c1+=(r-1-l)-b[r-1][i]+b[l][i];
			c2+=(r-1-l)-b[r-1][i-3]+b[l][i-3];
			FOR(j,i-2,i-1) {
				c2+='1'-a[l][j];
				c2+='1'-a[r][j];
			}
			FOR(j,i-2,i-1) {
				c2+=b[r-1][j]-b[l][j];
			}
//			cerr << c1 << " " << c2 << endl;
			pr=min(pr,c2);
			res=min(res,pr+c1);
			pr+='1'-a[l][i];
			pr+='1'-a[r][i];
			pr+=b[r-1][i]-b[l][i];
		}
	}
	ptn(res);
}
int main() {
	int T; 
	rd(T);
	while(T--) {
		solve();
	}
	return 0;
}