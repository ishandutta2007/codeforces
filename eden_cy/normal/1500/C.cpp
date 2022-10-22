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

const int M=2005;

typedef unsigned long long ull;

const int Base=233;

int a[M][M],b[M][M];

ull ha[M],hb[M];

map<ull,int> id;
vector<int> f[M];
int p[M],sz[M];
int v[M];

int c[M],d[M];
int Q[M];

int main() {
	int n,m;
	rd(n);rd(m);
	
	FOR(i,1,n) FOR(j,1,m) rd(a[i][j]);
	FOR(i,1,n) FOR(j,1,m) rd(b[i][j]);
	
	FOR(i,1,n) FOR(j,1,m) ha[i]=ha[i]*Base+a[i][j];
	FOR(i,1,n) FOR(j,1,m) hb[i]=hb[i]*Base+b[i][j];
	
	int cnt=0;
	FOR(i,1,n) {
		if(!id[ha[i]]) id[ha[i]]=++cnt;
		f[id[ha[i]]].push_back(i);
		++sz[id[ha[i]]];
	}
	FOR(i,1,n) {
		if(p[id[hb[i]]]==sz[id[hb[i]]]) {
			puts("-1");
			return 0;
		}
		v[i]=f[id[hb[i]]][p[id[hb[i]]]++];
	}
	
//	cerr << v[1] << endl;
	
	int l=1,r=0;
	FOR(i,2,n) FOR(j,1,m) {
		if(b[i-1][j]>b[i][j]) ++c[j];
	}
	
	int K=0;
	FOR(i,1,m) if(c[i]==0) Q[++r]=i;
	while(l<=r) {
		int x=Q[l++];
		FOR(i,2,n) {
			if(b[i-1][x]<b[i][x] && !d[i]) {
//				cerr << " --- " << endl;
				d[i]=1;
				FOR(j,1,m) if(b[i-1][j]>b[i][j]) {
					--c[j];
					if(!c[j]) Q[++r]=j;
				}
			}
		}
	}
	FOR(i,2,n) {
		if(!d[i] && v[i-1]>v[i]) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",r);
	DOR(i,r,1) printf("%d ",Q[i]);
	putchar('\n');
	return 0;
}