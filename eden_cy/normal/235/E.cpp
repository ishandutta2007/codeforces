#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef double db;
typedef long long ll;

namespace Eddd{
	template<class T> void rd(T &x) {
		static int f,c;x=f=0;
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
}
using namespace Eddd;

const int M=(int)4000005;
const int Mod=(int)1<<30;

int mo[M],prim[M],mark[M];
void Sieve(int Len) {
	int top=0;
	mo[1]=1;
	FOR(i,2,Len) {
		if(!mark[i]) {
			prim[++top]=i;
			mo[i]=-1;
		}
		FOR(j,1,top) {
			int x=i*prim[j];
			if(x>Len) break;
			mark[x]=true;
			if(!(i%prim[j])) {
				mo[x]=0;
				break;
			} else {
				mo[x]=-mo[i];
			}
		}
	}
}
int gcd(int x,int y) {
	return y?gcd(y,x%y):x;
}
int sum[M],S[M];
int main() {
	int a,b,c;
	rd(a);rd(b);rd(c);
	int n=a*b;
	Sieve(n);
	FOR(i,1,c) {
		for(int j=i; j<=c; j+=i) {
			sum[i]+=c/j;
		}
	}
	FOR(i,1,c) {
		for(int j=i; j<=n; j+=i) {
			S[j]=(S[j]+sum[i]*mo[i])%Mod;
		}
	}
//	FOR(i,1,n) {
//		cerr<<i<<" => "<<S[i]<<endl;
//	}
	ll res=0;
	FOR(i,1,a) {
		FOR(j,1,b) {
			if(gcd(i,j)==1) {
				res=(res+1ll*(a/i)*(b/j)*S[i*j])%Mod;
			}
		}
	}
	ptn(res);
	return 0;
}