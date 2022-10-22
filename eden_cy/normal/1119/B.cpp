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

int A[M],B[M];
int H;
bool cmp(int x,int y) {
	return x>y;
}
bool check(int n) {
	FOR(i,1,n) A[i]=B[i];
	bool res=false;
	{
		sort(A+1,A+n+1);
		bool t=true;
		int h=H;
		for(int i=2; i<=n; i+=2) {
			if(h<A[i]) t=false;
			h-=A[i];
		}
		if(n&1) if(h<A[n]) t=false;
		res|=t;
	}
	{
		sort(A+1,A+n+1,cmp);
		bool t=true;
		int h=H;
		for(int i=1; i<=n; i+=2) {
			if(h<A[i]) t=false;
			h-=A[i];
		}
		res|=t;
	}
	return res;
}
int main() {
	int n;
	rd(n);rd(H);
	FOR(i,1,n) rd(B[i]);
	int L=1,R=n,res=0;
	while(L<=R) {
		int mid=L+R>>1;
		if(check(mid)) res=mid,L=mid+1;
		else R=mid-1;
	}
	ptn(res);
	return 0;
}