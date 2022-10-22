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

const int M=3e5+50;

int h[M],w[M];
int e[M][2];
ll v[M][2];
int p[M];
int main() {
	int n;
	rd(n);
	FOR(i,1,n) rd(h[i]),p[h[i]]=i;
	FOR(i,1,n) rd(w[i]);
	FOR(i,2,n) e[i][0]=i-1,v[i][0]=0;
	FOR(i,1,n-1) e[i][1]=i+1,v[i][1]=0;
	ll res=0;
	DOR(i,n,1) {
		int x=p[i];
		int a=e[x][0];
		int b=e[x][1];
		e[a][1]=b;
		e[b][0]=a;
//		cerr << x << " " << a << " " << b << endl;
		if(a && b) {
//			cerr << v[x][0]+v[x][1]+w[x]-min(0ll,min(v[x][0]+w[x],v[x][1]+w[x])) << endl;
			v[a][1]=v[b][0]=v[x][0]+v[x][1]+w[x]-min(0ll,min(v[x][0]+w[x],v[x][1]+w[x]));
		} else if(a) {
			res+=max(0ll,v[a][1]+w[x]);
		} else if(b) {
			res+=max(0ll,v[b][0]+w[x]);
		} else {
			res+=w[x];
//			cerr << res << endl;
		}
	}
	printf("%lld\n",res);
	return 0;
}