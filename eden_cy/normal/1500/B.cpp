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

struct node{
	ll x,y;	
};
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}
 
node extgcd(ll a,ll b) {
	if(!b) return (node){1,0};
	else {
		node tmp=extgcd(b,a%b);
		return (node){tmp.y,tmp.x-a/b*tmp.y};
	}
}

ll a[M],b[M];
ll c[M];
ll d[M];
int main() {
	ll n,m;
	ll K;
	rd(n);rd(m);
	rd(K);
	FOR(i,1,n) rd(a[i]);
	FOR(i,1,m) rd(b[i]);
	FOR(i,1,m) c[b[i]]=i;
	ll g=gcd(n,m);
	ll r=n*m/g;
	node s=extgcd(n,m);
	FOR(i,1,n) if(c[a[i]]) {
		int j=c[a[i]];
		if((i-j)%g) {
			continue;
		}
		node ss=(node){-(i-j)/g*s.x,(i-j)/g*s.y};
		ll dd=i+ss.x*n;
		dd=((dd-1)%r+r)%r+1;
		d[i]=dd;
//		cerr << i << " " << d[i] << endl;
	}
	ll L=0,R=1e18,res;
	while(L<=R) {
		ll mid=L+R>>1;
		ll t=mid;
		ll k=mid/r;
		ll e=mid%r;
		FOR(i,1,n) {
			if(d[i]) {
				t-=k+(d[i]<=e);
			}
		}
		if(t>=K) res=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%lld\n",res);
	return 0; 
}