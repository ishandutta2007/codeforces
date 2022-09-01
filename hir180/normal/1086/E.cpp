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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
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
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[4005],R[4005];
void make(){
	F[0] = 1;
	for(int i=1;i<4005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<4005;i++) R[i] = modpow(F[i],mod-2);
}
ll C[2005][2005];
ll t[2005][2005];
int n,a[2005][2005];
struct BIT
{
	int bit[(1<<12)+5];
	void init(){
		memset(bit,0,sizeof(bit));
	}
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<=(1<<12);s+=f(s)) bit[s]+=x;
	}
	int query(int i)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}B[2];
int main(){
    make();
	rep(i,2005)rep(j,i+1){
		if(j==0||j==i) C[i][j]=1;
		else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int b=0;b<=2000;b++){
		vector<int>c,d;
		for(int j=0;j<=b;j++){
			int q = C[b][j];
			if(j%2 == 1) q *= -1;
			if(q<0) q += mod;
			c.pb(q);
		}
		for(int j=0;j<=2000;j++){
			d.pb(F[j]);
		}
		vector<int>e = ntt::multiply(c,d);
		for(int a=0;a<=2000-b;a++){
			t[b][a] = e[a+b];
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		scanf("%d",&a[i][j]);
	}
	ll ans = 0;
	int used[2005]={};
	for(int j=1;j<=n;j++){
		int C = 0;
		for(int i=1;i<a[1][j];i++){
			if(!used[i]){
				C++;
			}
		}
		ans += 1LL*C*F[n-j]%mod;
		used[a[1][j]] = 1;
	}
	ans = ans%mod*modpow(t[n][0],n-1)%mod;
	for(int i=2;i<=n;i++){
		bool x[2005][2]={};
		bool y[2005][2]={};
		int cnt = 0;
		ll add = 0;
		B[0].init(); B[1].init();
		for(int j=n;j>=1;j--){
			x[a[i-1][j]][0] = 1;
			if(x[a[i-1][j]][0] && x[a[i-1][j]][1]) B[1].add(a[i-1][j],1);
			x[a[i][j]][1] = 1;
			if(x[a[i][j]][0]&&x[a[i][j]][1]) B[1].add(a[i][j],1);
			
			B[0].add(a[i][j],1);
			if(j < n){
				y[a[i-1][j+1]][0] = 1;
				if(y[a[i-1][j+1]][0]&&y[a[i-1][j+1]][1]) cnt++;
			}
			y[a[i][j]][1] = 1;
			if(y[a[i][j]][0]&&y[a[i][j]][1]) cnt++;
			
			int p[2]={};
			p[1] = B[1].query(a[i][j]-1);
			p[0] = B[0].query(a[i][j]-1)-p[1];
			if(a[i-1][j]<a[i][j]){
				if(x[a[i-1][j]][1]){
					p[x[a[i-1][j]][0]]--;
				}
			}/*
			for(int k=1;k<a[i][j];k++){
			    if(k == a[i-1][j]) continue;
				if(x[k][1]){
					p[x[k][0]]++;
				}
			}*/
			if(cnt) add += p[1]*t[cnt-1][n-j-cnt+1];
			add += p[0]*t[cnt][n-j-cnt];//cout<<add<<endl;
			//cout<<cnt<<" "<<p[0]<<" "<<p[1]<<" "<<i<<" "<<j<<endl;
		}
		add %= mod;
		add = add*modpow(t[n][0],n-i)%mod;
		ans += add;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}