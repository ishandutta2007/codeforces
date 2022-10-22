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

const int M=2e6+50;

int a[M];
struct node {
	int x,v;
	bool operator <(const node &s) const{
		if(v!=s.v) return v<s.v;
		return x>s.x;
	}
} b[M];
int c[M];
int T,n,m;
void upd(int x) {
	for(; x<=m; x+=x&-x) {
		++c[x];
	}
}
int qry(int x) {
	int t=0;
	for(; x; x^=x&-x) {
		t+=c[x];
	}
	return t;
}
int main() {
	rd(T);
	while(T--) {
		rd(n);rd(m);
		FOR(i,1,m) rd(a[i]),b[i]=(node){i,a[i]};
		sort(b+1,b+m+1);
		FOR(i,1,m) c[i]=0;
		ll res=0;
		FOR(i,1,m) {
			res+=qry(b[i].x);
			upd(b[i].x);
		}
		ptn(res);
	}
	return 0;
}