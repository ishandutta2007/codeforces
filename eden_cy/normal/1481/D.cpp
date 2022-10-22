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

const int M=1e3+50;

char s[M][M];
void solve() {
	int n,m;
	rd(n);rd(m);
	FOR(i,1,n) scanf("%s",s[i]+1);
	if(m%2) {
		puts("YES");
		FOR(i,1,m+1) {
			if(i%2) ptk(1);
			else ptk(2);
		}
		putchar('\n');
		return ;
	}
	FOR(i,1,n) {
		FOR(j,i+1,n) {
			if(s[i][j]==s[j][i]) {
				puts("YES");
				FOR(k,1,m+1) {
					if(k%2) ptk(i);
					else ptk(j);
				}
				putchar('\n');
				return ;
			}
		}
	}
	FOR(i,1,n) {
		int x=0,y=0;
		FOR(j,1,n) if(j!=i) {
			if(s[j][i]=='a') x=j;
			else y=j;
		}
		if(!x || !y) continue;
		puts("YES");
		FOR(k,1,m/2) {
			if((m/2-k)%2==0) ptk(x);
			else ptk(i);
		}
		ptk(i);
		FOR(k,1,m/2) {
			if(k%2) ptk(y);
			else ptk(i);
		}
		putchar('\n');
		return ;
	}
	puts("NO");
}
int main() {
	int T;
	rd(T);
	while(T--) {
		solve();
	}
	return 0;
}