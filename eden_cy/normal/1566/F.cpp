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

ll a[N];
struct node {
	ll l,r;
	bool operator <(const node &s) const{
		if(r!=s.r) return r<s.r;
		return l>s.l;
	}
} b[N];
node c[N];
ll f[N][2];
int main() {
	int T,n,m;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		FOR(i,1,n) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		FOR(i,1,m) scanf("%lld%lld",&b[i].l,&b[i].r);
		sort(b+1,b+m+1);
		int p=1,K=0;
		while(p<=m && b[p].r<a[1]) {
			if(!K || b[p].l>c[K].l) c[++K]=b[p];
			p++;
		}
//		FOR(j,1,K) {
//			cerr << c[j].l << " - " << c[j].r << endl;
//		}
		if(K) {
			f[1][0]=a[1]-c[1].r;
			f[1][1]=(a[1]-c[1].r)*2;
		} else {
			f[1][0]=f[1][1]=0;
		}
		FOR(i,2,n) {
			K=0;
			while(p<=m && b[p].l<=a[i-1]) {
				++p;
			}
//			if(i==2)
			while(p<=m && b[p].r<a[i]) {
				if(!K || b[p].l>c[K].l) c[++K]=b[p];
				p++;
			}
//			if(i==2) cerr << a[i] << " " << b[p].l << " - " << b[p].r << endl;
			if(!K) {
				f[i][0]=f[i][1]=min(f[i-1][0],f[i-1][1]);
				continue;
			}
//			cerr << i << " --- " << endl;
//			if(i==2) {
//				FOR(j,1,K) {
//					cerr << c[j].l << " - " << c[j].r << endl;
//				}
//			}
			f[i][0]=min(f[i-1][0]+a[i]-c[1].r,f[i-1][1]+a[i]-c[1].r);
			f[i][1]=min(f[i-1][0]+2*(a[i]-c[1].r),f[i-1][1]+2*(a[i]-c[1].r));
//			if(i==2) cerr << f[i][0] << endl;
			
			f[i][0]=min(f[i][0],min(f[i-1][0]+(c[K].l-a[i-1])*2,f[i-1][1]+(c[K].l-a[i-1])));
			f[i][1]=min(f[i][1],min(f[i-1][0]+(c[K].l-a[i-1])*2,f[i-1][1]+(c[K].l-a[i-1])));
			
			FOR(j,1,K-1) {
				f[i][0]=min(f[i][0],min(f[i-1][0]+(c[j].l-a[i-1])*2+(a[i]-c[j+1].r)*1,
					f[i-1][1]+(c[j].l-a[i-1])*1+(a[i]-c[j+1].r)*1));
				f[i][1]=min(f[i][1],min(f[i-1][0]+(c[j].l-a[i-1])*2+(a[i]-c[j+1].r)*2,
					f[i-1][1]+(c[j].l-a[i-1])*1+(a[i]-c[j+1].r)*2));
//				if(f[i][0]<0) cerr << " --- " << endl;
			}
		}
//		cerr << f[4][1] << endl;
		K=0;
		while(p<=m && b[p].l<=a[n]) {
			++p;
		}
		while(p<=m) {
			if(!K || b[p].l>c[K].l) c[++K]=b[p];
			p++;
		}
		ll res;
		if(K) {
			res=min(f[n][0]+(c[K].l-a[n])*2,f[n][1]+(c[K].l-a[n])*1);
		} else {
			res=min(f[n][0],f[n][1]);
		}
//		FOR(j,1,K) {
//			cerr << c[j].l << " - " << c[j].r << endl;
//		}
		printf("%lld\n",res);
	}
	return 0;
}