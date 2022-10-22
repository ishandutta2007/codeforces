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

const int M=5e6+50;

#define fi first
#define se second

int a[M];
int b[M];
vector<int> c[M];
bool d[M];
int X[M],Y[M];
int main() {
	int n;
	rd(n);
	FOR(i,1,n) rd(a[i]);
	FOR(i,1,n) {
		++b[a[i]];
		c[a[i]].push_back(i);
		if(b[a[i]]>1) {
			d[i]=1;
		}
	}
	int x=0;
	int m=5e6;
	FOR(i,1,m) if(b[i]>1) {
		if(!x) x=i;
		else {
			printf("YES\n%d %d %d %d\n",c[x][0],c[i][0],c[x][1],c[i][1]);
			return 0;
		}
	}
	if(x) {
		if(b[x]>=4) {
			printf("YES\n%d %d %d %d\n",c[x][0],c[x][1],c[x][2],c[x][3]);
			return 0;
		}
		int r=1;
		while(1<=x-r && x+r<=m) {
			if(b[x-r] && b[x+r]) {
				printf("YES\n%d %d %d %d\n",c[x][0],c[x][1],c[x-r][0],c[x+r][0]);
				return 0;
			}
			++r;
		}
	}
	FOR(i,1,n) if(!d[i]) {
		FOR(j,i+1,n) if(!d[j]) {
			int t=a[i]+a[j];
			if(X[t]) {
				printf("YES\n%d %d %d %d\n",i,j,X[t],Y[t]);
				return 0;
			}
			X[t]=i;
			Y[t]=j;
		}
	}
	puts("NO");
	return 0;
}