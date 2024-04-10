#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

namespace Eddd {
	char sc() {
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

const int M=1e5+50;

int A[M],B[M],C[M],D[M];
vector<int> G[M];
int sz[M];
int main() {
	int T,n,m;
	rd(T);
	while(T--) {
		rd(n);rd(m);
		FOR(i,1,n) rd(A[i]);
		FOR(i,1,n) rd(B[i]);
		FOR(i,1,m) rd(C[i]);
		FOR(i,1,n) G[i].clear(),sz[i]=0;
		FOR(i,1,n) {
			if(B[i]!=A[i]) G[B[i]].push_back(i);
		}
		FOR(i,1,n) {
			if(B[i]==A[i]) {
				G[B[i]].push_back(i);
			}
		}
		int ls=1;
		FOR(i,1,m) {
			int c=C[i];
			if(G[c].size()) {
				if(sz[c]==G[c].size()) {
					D[i]=G[c][0];
				} else {
					D[i]=G[c][sz[c]++];
				}
				ls=D[i];
			}
		}
		FOR(i,1,m) {
			int c=C[i];
			if(G[c].size()) {
				
			} else {
				D[i]=ls;
			}
		}
		FOR(i,1,m) A[D[i]]=C[i];
		bool res=true;
		FOR(i,1,n) if(A[i]!=B[i]) res=false;
		if(res) {
			puts("YES");
			FOR(i,1,m) {
				if(i<m) ptk(D[i]);
				else ptn(D[i]);
			}
		} else {
			puts("NO");
		}
	}
	return 0;
}