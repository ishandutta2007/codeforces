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

const int M=2e5+50;
vector<int> a[M];
int b[M];
int ans[M];
void solve() {
	int n,m;
	rd(n);rd(m);
	FOR(i,1,m) {
		int K;
		rd(K);
		a[i].clear();
		FOR(j,1,K) {
			int x;
			rd(x);
			a[i].push_back(x);
		}
	}
	FOR(i,1,n) b[i]=0;
	int lim=(m+1)/2;
	FOR(i,1,m) {
		if(a[i].size()==1) {
			++b[a[i][0]];
			ans[i]=a[i][0];
		}
	}
	FOR(i,1,n) if(b[i]>lim) {
		puts("NO");
		return ;
	}
	FOR(i,1,m) {
		if(a[i].size()!=1) {
			FOR(j,0,a[i].size()-1) {
				if(b[a[i][j]]+1<=lim) {
					++b[a[i][j]];
					ans[i]=a[i][j];
					break;
				}
			}
		}
	}
	puts("YES");
	FOR(i,1,m) printf("%d%c",ans[i]," \n"[i==m]);
}
int main() {
	int T;
	rd(T);
	while(T--) solve();
	return 0;
}