#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

#define mod 998244353
map<int,int>M;
map<int,int>C;
const int md = 998244353;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
 
inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}
 
inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
 
inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
 
namespace ntt {
  int base = 1;
  vector<int> roots = {0, 1};
  vector<int> rev = {0, 1};
  int max_base = -1;
  int root = -1;
 
  void init() {
  	base = 1;
  	roots = {0,1};
  	rev = {0,1};
  	max_base = -1;
  	root = -1;
    int tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (true) {
      if (power(root, 1 << max_base) == 1) {
        if (power(root, 1 << (max_base - 1)) != 1) {
          break;
        }
      }
      root++;
    }
  }
 
  void ensure_base(int nbase) {
    if (max_base == -1) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      int z = power(root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
      }
      base++;
    }
  }
 
  void fft(vector<int> &a) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          int x = a[i + j];
          int y = mul(a[i + j + k], roots[j + k]);
          a[i + j] = x + y - md;
          if (a[i + j] < 0) a[i + j] += md;
          a[i + j + k] = x - y + md;
          if (a[i + j + k] >= md) a[i + j + k] -= md;
        }
      }
    }
  }
 
  vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
    int need = a.size() + b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++) {
      a[i] = mul(mul(a[i], b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
  }
 
  vector<int> square(vector<int> a) {
    return multiply(a, a, 1);
  }
};
ll modpow(ll a,ll n){
    ll cur = a,ret = 1;
    while(n){
        if(n%2 == 1) ret = ret*cur%mod;
        cur = cur*cur%mod;
        n /= 2;
    }
    return ret;
}


namespace power_series_master {
    //x^ivecc[i]
    //mod x^M
    
    //add,sub,diff,intg,mul_int,mul,inv,sqrt,log,exp
    //add sub
    //diff,intgdiff0
    //logexpGP peterhof H verify
    //mod 998244353mularbitrary_mod_conv
    
    //verify list
    
    //mul_int,sub,sqrt,inv... CF 438E
    //exp... yosupo judge
    #define vi vector<int>
    vi init(vi a, int x){
    	a.resize(x,0);
    	return a;
    }
    vi add(vi a, vi b,int M=-1){
        if(a.size() < b.size()) swap(a,b);
        for(int i=0;i<b.size();i++){
            a[i]+=b[i];
            if(a[i] < 0) a[i] += mod;
            if(a[i] >= mod) a[i] -= mod;
        }
        if(M >= 0 && a.size() > M) a.resize(M);
        return a;
    }
    vi sub(vi a, vi b,int M=-1){
        if(a.size() < b.size()) a.resize(b.size(),0);
        for(int i=0;i<b.size();i++){
            a[i]-=b[i];
            if(a[i] < 0) a[i] += mod;
            if(a[i] >= mod) a[i] -= mod;
        }
        if(M >= 0 && a.size() > M) a.resize(M);
        return a;
    }
    //
    vi diff(vi a,int M=-1){
    	reverse(a.begin(),a.end());
    	a.pop_back();
    	reverse(a.begin(),a.end());
    	for(int i=0;i<a.size();i++) a[i] = 1LL*a[i]*(i+1)%mod;
    	if(M >= 0 && a.size() > M) a.resize(M);
    	if(a.empty()) a.pb(0);
    	return a;
    }
    //
    vi intg(vi a,int coef=0,int M=-1){
    	reverse(a.begin(),a.end());
    	a.push_back(coef);
    	reverse(a.begin(),a.end());
    	for(int i=1;i<a.size();i++) a[i] = 1LL*a[i]*modpow(i,mod-2)%mod;
    	if(M >= 0 && a.size() > M) a.resize(M);
    	return a;
    }
    vi mul_int(vi a,int x,int M=-1){
        for(int i=0;i<a.size();i++){
            ll A = 1LL*a[i]*x%mod;
            if(A < 0) A += mod;
            a[i] = A;
        }
        if(M >= 0 && a.size() > M) a.resize(M);
        return a;
    }
    vi mul(vi a,vi b,int M=-1){
        //mod99...ntt
        //modgarner
        ntt::init();
		a = ntt::multiply(a,b);
		if(M >= 0 && a.size() > M) a.resize(M);
        return a;
    }
    //vec-1x^(M-1)Mvector
    //vec[0] = 0
    //r1(z)f(z) = x*? + 1
    //rn(z)f(z) = x^n*? + 1
    //r(2n)(z) = 2*rn(z)-rn(z)^2f(z)OK!
    vi inv(vi a,int M){
        if(a.empty() || a[0] == 0) return vi();
        //1
        vi r[30];
        r[0].pb(modpow(a[0],mod-2));
        int cur = 1;
        int nxt = 1;
        vi vec3;
        while(cur < M){
        	int nw = min(cur*2,(int)(a.size()));
        	int sz = vec3.size();
        	vec3.resize(nw,0);
        	for(int t=sz;t<nw;t++){
        		vec3[t] = a[t];
        	}
            r[nxt] = sub(mul_int(r[nxt-1],2),mul(mul(r[nxt-1],r[nxt-1]),vec3));
            r[nxt].resize(r[nxt-1].size()*2);
            nxt++;
            cur *= 2;
        }
        assert(r[nxt-1].size() >= M);
        r[nxt-1].resize(M);
        assert(r[nxt-1].size() == M);
        return r[nxt-1];
    }
    //vecx^(M-1)Mvector
    //vec[0] = 0
    //
    //s1(z)^2 = f(z) (mod z)
    //sn(z)^2 = f(z) (mod z^n) 
    //s(2n)(z) = 1/2 * (sn(z)+f(z)*sn(z)^-1)
    vi sqrt(vi a,int M){
        if(a.empty() || a[0] == 0) return vi();
        //1
        vi s[30];
        //vec[0] = 1
        s[0].pb(1);
        assert(1LL*s[0][0]*s[0][0]%mod == a[0]);
        int cur = 1;
        int nxt = 1;
        vi vec3;
        while(cur < M){
            int nw = min(cur*2,(int)(a.size()));
        	int sz = vec3.size();
        	vec3.resize(nw,0);
        	for(int t=sz;t<nw;t++){
        		vec3[t] = a[t];
        	}
            s[nxt] = add(s[nxt-1],mul(vec3,inv(s[nxt-1],cur*2)));
            s[nxt] = mul_int(s[nxt],modpow(2,mod-2));
            s[nxt].resize(cur*2);
            nxt++;
            cur *= 2;
        }
        s[nxt-1].resize(M);
        assert(s[nxt-1].size() == M);
        return s[nxt-1];
    }
    //veclog()x^(M-1)Mvector
    //vec[0] = 0
    //log(f(x)) = intg(f'(x)/f(x)) = intg(mul(diff(f(x),need+1),inv(f(x),need+1),need+1))
    //0vec[0]!=1
    vi log(vi a,int M){
        if(a.empty() || a[0] == 0) return vi();
        vi x = diff(a,M);
        vi y = inv(a,M);
        vi z = mul(x,y,M);
        return intg(z,0,M);
    }
    //vecexp()x^(M-1)Mvector
    //vec[0] != 0
    //exp(a)1!=1log
    //http://www.csd.uwo.ca/~eschost/publications/BoSc09-final.pdf
    vi exp(vi a,int M){
        if(a.empty() || a[0] != 0) return vi();
        vi f={1},g={1},q,aa;
        int m = 1;
        vi h = diff(a);
        while(m<=M){
			g = sub(mul_int(g,2,m),mul(mul(f,g,m),g,m),m);
			while(aa.size() < 2*m){
			    if(aa.size() >= a.size()) aa.pb(0);
			    else aa.pb(a[aa.size()]);
			}
			if(m>1){
				vi w = add(q,mul(g,sub(diff(f,2*m-1),mul(f,q,2*m-1),2*m-1),2*m-1),2*m-1);
				f = add(f,mul(f,sub(aa,intg(w,0,2*m),2*m),2*m),2*m);
			}
			else{
				vi w = mul(g,diff(f,2*m-1),2*m-1);
				f = add(f,mul(f,sub(aa,intg(w,0,2*m),2*m),2*m),2*m);
			}
			m*=2;
			while(q.size() < m-1){
				if(q.size() >= h.size()) q.pb(0);
				else q.pb(h[q.size()]);
			}
		}
		f.resize(M);
		assert(f.size() == M);
		return f;
    }
};
vector<vector<int>>vec;
vi calc(int a,int b){
	if(a == b){
		return vec[a];
	}
	return power_series_master::mul(calc(a,(a+b)/2),calc(1+(a+b)/2,b));
}
int main(){
	int n; cin >> n;
	for(int i=0;i<n;i++){
		int x; scanf("%d",&x); M[x]++;
	}
	for(auto a:M) C[a.second]++;
	
	for(auto a:C){
		vector<int>vv;
		vv.resize(a.first+1,1);
		for(int i=0;i<a.second;i++) vec.pb(vv);
	}
	vi ans = calc(0,vec.size()-1);
	cout << (ans[n/2]%mod+mod)%mod << endl;
}