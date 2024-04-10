//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,unsafe-math-optimizations")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
inline int read_char() {
    static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
    if (ptr == end_ptr) {
        int len = fread(buf, 1, sizeof(buf), stdin);
        if (len <= 0) return EOF;
        ptr = buf;
        end_ptr = buf + len;
    }
    return *ptr++;
}
inline int readint(){
    int t=0;
    char c;
    bool negative=false;
    c=read_char();
    while(c<'0'&&c>'9'){
        if(c=='-')
            negative=true;
        c=read_char();
    }
    while(c>='0'&&c<='9'){
        t=(t<<3)+(t<<1)+c-'0';
        c=read_char();
    }
    if(negative)
        t=~(t-1); //negative
    return t;
}

inline void printint(int a){
    if(a==0){putchar('0');return;}
    char buf[10],x=0;
    while(a){
        buf[x++]=a%10;
        a/=10;
    }
    while(x){
        putchar(buf[--x]+48);
    }
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int n,a,b;
int __attribute__((aligned(64))) xa[100005],ya[100005];
int __attribute__((aligned(64))) xb[100005],yb[100005];
vector<P>A,B;
vector<P>c,d;
vector<int>za;
ll __attribute__((aligned(64))) dp[400005][2];
ll __attribute__((aligned(64))) dp2[100005][2];
ll __attribute__((aligned(64))) dp3[100005][2];
struct RMQ{
	#define s (1<<20)
	ll seg[s];
	void update(int k,ll a){
		k+=s/2-1; seg[k]=(seg[k]+a)%mod;
		while(k>0){
			k=(k-1)/2;
			seg[k]=(seg[k*2+1]+seg[k*2+2])%mod;
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<a || b<l || a>b) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return (vl+vr)%mod;
		}
	}
	ll query(int a,int b){
		return query(a,b,0,0,s/2-1);
	}
}kaede[2],kaede2[2],kaede3[2];
int main(){
	n = readint(); a = readint(); b = readint();
	repn(i,a){
		xa[i] = readint(); ya[i] = readint();
		za.pb(xa[i]);za.pb(ya[i]);
		A.pb(mp(xa[i],-ya[i]));
	}
	SORT(A);
	rep(i,A.size()){
	    while(c.size() && c[c.size()-1].sc <= A[i].sc){
	        c.pop_back();
	    }
		{
			c.pb(A[i]);
		}
	}
	rep(i,c.size()) c[i].sc*=-1;
	repn(i,b){
		xb[i] = readint(); yb[i] = readint();
		za.pb(xb[i]);za.pb(yb[i]);
		B.pb(mp(xb[i],-yb[i]));
	}
	SORT(B);
	rep(i,B.size()){
	    while(d.size() && d[d.size()-1].sc <= B[i].sc){
	        d.pop_back();
	    }
		{
			d.pb(B[i]);
		}
	}
	rep(i,d.size()) d[i].sc*=-1;
	za.pb(0);
	SORT(za); ERASE(za);
	dp[0][0] = 1;
	kaede[0].update(0,1);
	int nxtc=0,nxtd=0;
	for(int i=1;i<za.size();i++){
		if(nxtc!=c.size() && za[i] == c[nxtc].sc){
			int lb = -1,ub = nxtc;
			while(ub-lb>1){
				int mid = (lb+ub)/2;
				if(c[mid].sc<c[nxtc].fi) lb = mid;
				else ub = mid;
			}
			//cout<<nxtc<<" "<<ub<<endl;
			dp2[nxtc][0] = kaede2[1].query(ub,nxtc-1);
			dp2[nxtc][1] = kaede2[0].query(ub,nxtc-1);
			int k = POSL(za,c[nxtc].fi);
			dp2[nxtc][0] += modpow(2LL,c[nxtc].fi-1) * kaede[1].query(0,k-1) % mod;
			dp2[nxtc][1] += modpow(2LL,c[nxtc].fi-1) * kaede[0].query(0,k-1) % mod;
			dp2[nxtc][0] %= mod;
			dp2[nxtc][1] %= mod;
			//cout<<nxtc<<" " <<dp2[nxtc][0]<<" "<<dp2[nxtc][1]<<endl;
			kaede2[0].update(nxtc,dp2[nxtc][0]);
			kaede2[1].update(nxtc,dp2[nxtc][1]);
			kaede[0].update(i,dp2[nxtc][0]*modpow(modpow(2LL,c[nxtc].sc),mod-2)%mod);
			kaede[1].update(i,dp2[nxtc][1]*modpow(modpow(2LL,c[nxtc].sc),mod-2)%mod);
			//cout<<dp2[nxtc][0]*modpow(modpow(2LL,c[nxtc].sc),mod-2)%mod<<" "<<za[i]<<endl;
			nxtc++;
		}
		if(nxtd!=d.size() && za[i] == d[nxtd].sc){
			int lb = -1,ub = nxtd;
			while(ub-lb>1){
				int mid = (lb+ub)/2;
				if(d[mid].sc<d[nxtd].fi) lb = mid;
				else ub = mid;
			}
			dp3[nxtd][0] = kaede3[1].query(ub,nxtd-1);
			dp3[nxtd][1] = kaede3[0].query(ub,nxtd-1);
			int k = POSL(za,d[nxtd].fi);
			dp3[nxtd][0] += modpow(2LL,d[nxtd].fi-1) * kaede[1].query(0,k-1) % mod;
			dp3[nxtd][1] += modpow(2LL,d[nxtd].fi-1) * kaede[0].query(0,k-1) % mod;
			dp3[nxtd][0] %= mod;
			dp3[nxtd][1] %= mod;
			kaede3[0].update(nxtd,dp3[nxtd][0]);
			kaede3[1].update(nxtd,dp3[nxtd][1]);
			kaede[0].update(i,dp3[nxtd][0]*modpow(modpow(2LL,d[nxtd].sc),mod-2)%mod);
			kaede[1].update(i,dp3[nxtd][1]*modpow(modpow(2LL,d[nxtd].sc),mod-2)%mod);
			nxtd++;
		}
	}
	ll pl = kaede[0].query(0,za.size()-1); //cout<<pl*32%mod<<endl;
	pl = pl*modpow(2LL,n)%mod;
	ll ge = kaede[1].query(0,za.size()-1);//cout<<ge*32%mod<<endl;
	ge = ge*modpow(2LL,n)%mod;
	ll all = modpow(2LL,n);
	printint((pl-ge+mod)%mod);
}