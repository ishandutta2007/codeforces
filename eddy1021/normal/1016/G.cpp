#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n2] if
// you want to use magic.
LL add(LL a, LL b, LL mod){
  a+=b;
  return a>=mod?a-mod:a;
}
LL mul(LL a, LL b, LL mod){
  LL ret=0;
  while(b){
    if(b&1LL) ret=(ret+a)%mod;
    a=(a+a)%mod;
    b>>=1;
  }
  return ret;
}
LL mypow(LL a, LL b, LL mod){
  LL ret=1;
  while(b){
    if(b&1LL) ret=mul(ret, a, mod);
    a=mul(a, a, mod);
    b>>=1;
  }
  return ret;
}
bool witness(LL a,LL n,LL u,int t){
	LL x=mypow(a,u,n);
	for(int i=0;i<t;i++) {
		LL nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool miller_rabin(LL n) {
	// iterate s times of witness on n
	// return 1 if prime, 0 otherwise
	if(n<2) return 0;
	if(!(n&1)) return n == 2;
	LL u=n-1; int t=0;
	// n-1 = u*2^t
	while(!(u&1)) u>>=1, t++;
  for(LL a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
    if(a > n-2)
      continue;
		if(witness(a,n,u,t))
      return 0;
	}
	return 1;
}
// does not work when n is prime
LL f(LL x, LL mod){ return add(mul(x,x,mod),1,mod); }
LL myrand(LL n){
  LL ret=1;
  for(int i=0; i<4; i++)
    ret=(ret<<15)|(rand() & ((1LL<<15)-1));
  return ret%n;
}
LL pollard_rho(LL n) {
	if(!(n&1)) return 2;
  while(true){
    LL y=2, x=myrand(n-1)+1, res=1;
    for(int sz=2; res==1; sz*=2) {
      for(int i=0; i<sz && res<=1; i++) {
        x = f(x, n);
        res = __gcd(abs(x-y), n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
  }
}
const int N=202020;
LL n, x, y, a[N];
vector<LL> pris;
bool factor(LL val, vector<LL>& cc){
  cc.resize(pris.size());
  for(size_t i=0; i<pris.size(); i++){
    cc[i]=0;
    while(val % pris[i] == 0){
      val/=pris[i];
      cc[i]++;
    }
  }
  return val==1;
}
vector<LL> cx, cy;
vector<LL> coe[N];
bool okay[N];
LL cnt[1<<19];
void go(){
  assert(factor(x, cx));
  assert(factor(y, cy));
  for(int i=0; i<n; i++)
    okay[i]=factor(a[i], coe[i]);
  for(int i=0; i<n; i++){
    { // as i
      bool ok=true;
      int msk=0;
      for(size_t j=0; j<pris.size(); j++){
        if(coe[i][j] < cx[j]){
          ok=false;
          break;
        }
        if(coe[i][j] == cx[j] or cx[j] == cy[j])
          continue;
        msk|=(1<<j);
      }
      if(not ok) continue;
      cnt[msk]++;
    }
  }
  for(size_t i=0; i<pris.size(); i++)
    for(int j=0; j<(1<<(pris.size())); j++)
      if((j >> i) & 1)
        cnt[j]+=cnt[j^(1<<i)];
  LL ans=0;
  int ALL=(1<<pris.size())-1;
  for(int i=0; i<n; i++){
    { // as j
      if(not okay[i]) continue;
      bool ok=true;
      int msk=0;
      for(size_t j=0; j<pris.size(); j++){
        if(coe[i][j] > cy[j]){
          ok=false;
          break;
        }
        if(coe[i][j] == cy[j] or cx[j] == cy[j])
          continue;
        msk|=(1<<j);
      }
      if(not ok) continue;
      msk^=ALL;
      ans+=cnt[msk];
    }
  }
  printf("%lld\n", ans);
}
int main(){
  scanf("%lld%lld%lld", &n, &x, &y);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);
  if(y%x){
    puts("0");
    exit(0);
  }
  {
    LL tmpy=y;
    for(LL i=2; i<=1e6+10; i++){
      if(tmpy % i) continue;
      pris.push_back(i);
      while(tmpy % i == 0) tmpy/=i;
    }
    if(tmpy > 1){
      if(miller_rabin(tmpy))
        pris.push_back(tmpy);
      else{
        LL aa=pollard_rho(tmpy);
        LL bb=tmpy/aa;
        pris.push_back(aa);
        pris.push_back(bb);
      }
    }
    sort(pris.begin(), pris.end());
    pris.resize(unique(pris.begin(), pris.end())-pris.begin());
  }
  go();
}