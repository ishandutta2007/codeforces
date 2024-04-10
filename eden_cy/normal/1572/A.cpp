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

int deg[N];
vector<int> E[N];
set<int> S;
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) E[i].clear(),deg[i]=0;
	FOR(i,1,n) {
		int K;
		scanf("%d",&K);
		FOR(j,1,K) {
			int x;
			rd(x);
			E[x].push_back(i);
			deg[i]++;
		}
	}
	S.clear();
	int sz=0;
	FOR(i,1,n) {
		if(deg[i]==0) {
			++sz;
			S.insert(i);
		}
	}
	int p=0,res=1,c=0;
	while(sz) {
		set<int> :: iterator it=S.lower_bound(p+1);
		if(it!=S.end()) {
			++c;
			p=*it;
			S.erase(it);
			--sz;
			for(auto x: E[p]) {
				--deg[x];
				if(deg[x]==0) S.insert(x),++sz;
			}
		} else {
			p=0;
			++res;
		}
	}
	if(c<n) res=-1;
	printf("%d\n",res);
	
}
int main() {
	int T; 
	rd(T);
	while(T--) {
		solve();
	}
	
	return 0;
}