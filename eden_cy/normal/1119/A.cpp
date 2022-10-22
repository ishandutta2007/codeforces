#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

template<class T> void rd(T &x) {
	static int c,f;x=f=0;
	while(c=getchar(),c<48) if(c=='-') f=1;
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);if(f) x=-x;
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

const int M=(int)300005;

int A[M];
int main() {
	int n;
	rd(n);
	FOR(i,1,n) {
		rd(A[i]);
	}
	int res=0;
	FOR(i,1,n) {
		if(A[i]!=A[n]) {
			chkmx(res,n-i);
		}
		if(A[i]!=A[1]) {
			chkmx(res,i-1);
		}
	}
	ptn(res);
	return 0;
}