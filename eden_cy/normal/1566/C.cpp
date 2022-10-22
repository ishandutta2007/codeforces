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

char a[2][M];
int b[M];
int main() {
	int T,n,s;
	rd(T);
	while(T--) {
		int n;
		rd(n);
		scanf("%s",a[0]);
		scanf("%s",a[1]);
		b[0]=b[1]=0;
		int res=0;
		FOR(i,0,n-1) {
			int s=(a[0][i]-'0'+1)|(a[1][i]-'0'+1);
			if(s==3) {
				if(b[0] && b[1]) res+=2;
				else if(b[0]) res+=1;
				b[0]=b[1]=0;
				res+=2;
			} else if(s==2) {
				if(b[0]) res+=2,b[0]=b[1]=0;
				else b[1]=1;
			} else if(s==1) {
				if(b[1]) res+=2,b[0]=b[1]=0;
				else if(b[0]) ++res;
				else b[0]=1;
			}
		}
		if(b[0] && b[1]) res+=2;
		else if(b[0]) res+=1;
		ptn(res);
	}
	return 0;
}