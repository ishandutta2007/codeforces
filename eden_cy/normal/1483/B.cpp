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
int a[M];
int gcd(int x,int y) {
	return y?gcd(y,x%y):x;
}
set<int> s,s0;
int prev(int x) {
	if(s.size()==1) return x;
	set<int> :: iterator it;
	it=s.find(x);
	if(it==s.begin()) {
		return *s.rbegin();
	}
	return *(--it);
}
int next(int x) {
	if(s.size()==1) return x;
	set<int> :: iterator it;
	it=s.find(x);
	++it;
	if(it==s.end()) {
		return *s.begin();
	}
	return *it;
}
int ans[M],res;
void solve() {
	int n;
	rd(n);
	FOR(i,1,n) rd(a[i]);
	s.clear();
	s0.clear();
	FOR(i,1,n) s.insert(i);
	FOR(i,1,n) if(gcd(a[prev(i)],a[i])==1) s0.insert(i);
	int e=2;
	res=0;
	while(!s0.empty()) {
		set<int> :: iterator it=s0.lower_bound(e);
		if(it==s0.end()) it=s0.begin();
		ans[++res]=*it;
		int x=*it;
		
		e=next(x);
		
		if(e==x) break;
		
		s.erase(s.find(x));
		s0.erase(it);
		
		if(gcd(a[x],a[e])==1) s0.erase(s0.find(e));
		if(gcd(a[prev(e)],a[e])==1) s0.insert(e);
		
		++e;
	}
	printf("%d ",res);
	FOR(i,1,res) printf("%d ",ans[i]);
	putchar('\n');
}
int main() {
	int T;
	rd(T);
	while(T--) solve();
	return 0;
}