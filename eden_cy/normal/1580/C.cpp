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

const int N=2e5+50;
const int S=400;

int A[N],B[N];
int sum[N];

int cnt[S+2][S+2];

int pre[N];
int n,m;
int res;
void solve() {
	rd(n);rd(m);
	FOR(i,1,n) {
		rd(A[i]);
		rd(B[i]);
	}
	int s=0;
	res=0;
	FOR(i,1,m) {
		int op,x;
		rd(op);rd(x);
		if(op==1) {
			if(A[x]+B[x]<=S) {
				int p=A[x]+B[x];
				FOR(j,1,B[x]) {
					cnt[p][(i+A[x]+j-1)%p]++;
				}
			} else {
				for(int j=i+A[x]; j<=m; j+=A[x]+B[x]) {
					sum[j]++;
					if(j+B[x]<=m) {
						--sum[j+B[x]];
					}
				}
			}
			pre[x]=i;
		} else {
			if(A[x]+B[x]<=S) {
				int p=A[x]+B[x];
				int t=pre[x];
				FOR(j,1,B[x]) {
					cnt[p][(t+A[x]+j-1)%p]--;
				}
			} else {
				int t=pre[x];
				for(int j=t+A[x]; j<=m; j+=A[x]+B[x]) {
					sum[j]--;
					if(j<i) --res;
					if(j+B[x]<=m) {
						++sum[j+B[x]];
						if(j+B[x]<i) ++res;
					}
				}
			}
			pre[x]=0;
		}
		res+=sum[i];
		int t=0;
		FOR(j,1,S) {
			t+=cnt[j][i%j];
		}
		ptn(res+t);
	}
}
int main() {
	solve();
//	int T; 
//	rd(T);
//	while(T--) {
//		solve();
//	}
	return 0;
}