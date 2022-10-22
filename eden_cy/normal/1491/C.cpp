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

const int M=1e5+50;
ll a[M];
ll b[M];
ll s[M];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		rd(n);
		FOR(i,1,n) rd(a[i]);
		FOR(i,1,n) b[i]=s[i]=0;
		ll t=0;
		ll res=0;
		FOR(i,1,n) {
			t+=s[i];
			b[i]=t;
			if(b[i]<a[i]-1) {
				res+=(a[i]-1)-b[i];
				b[i]+=(a[i]-1)-b[i];
			}
			++s[i+2];
			--s[min(n+5ll,i+a[i]+1)];
			s[i+1]+=b[i]-(a[i]-1);
			s[i+2]-=b[i]-(a[i]-1);
		}
		printf("%lld\n",res);
	}
	return 0;
}