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

const int M=2e6+50;

int Head[M],E[M<<1],Nxt[M<<1],tol;

bool del[M<<1];

void Edge(int x,int y) {
	E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}
int fib[M];
bool is[M];

int sz[M],Fa[M];
int p,e;
void dfs(int x,int fr,int n) {
	Fa[x]=fr;
	sz[x]=1;
	EOR(i,x) if(E[i]!=fr && !del[i]) {
		dfs(E[i],x,n);
		sz[x]+=sz[E[i]];
	}
	EOR(i,x) if(E[i]!=fr && !del[i]) {
//		if(n==2) cerr << x <<endl; 
		if(is[n-sz[E[i]]] && is[sz[E[i]]]) {
			p=E[i];
			e=i;
		}
	}
}
void solve(int x,int n) {
	if(n==1) return ;
//	cerr << n << endl;
	p=0;
	dfs(x,0,n);
//	cerr << x << " -- " << p << " " << Fa[p] << " " << n << endl;
	if(!p) {
		puts("NO");
		exit(0);
	}
//	cerr << " --- "<< E[e^1] << endl;
	del[e]=del[e^1]=1;
	int tt=Fa[p],ss=n-sz[p];
//	cerr << n << " " << sz[p] <<  " " << ss << endl;
//	cerr << sz[p] << wend
	solve(p,sz[p]);
	solve(tt,ss);
}
int main() {
	fib[0]=1;
	fib[1]=1;
	FOR(i,2,30) fib[i]=fib[i-2]+fib[i-1];
//	cerr << fib[30] << endl;
	
	memset(Head,-1,sizeof(Head));
	int n;
	rd(n);
	FOR(i,2,n) {
		int x,y;
		rd(x);rd(y);
		Edge(x,y);
		Edge(y,x);
	}
	
	FOR(i,0,30) if(fib[i]<=n) is[fib[i]]=1;
	if(!is[n]) {
		puts("NO");
//		cerr << " -- " << endl;
		return 0;
	}
	solve(1,n);
	puts("YES");
	return 0;
}