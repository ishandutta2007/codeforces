#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 3e5+5;
const int mod = 998244353;

int d[ms];
int fat[ms];
int ifat[ms];

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = a*ans % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int choose(int a, int b) {
  return fat[a] * ifat[a-b] % mod;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int tot = 0;
  for(int i = 0; i < n; i++) {
    cin >> d[i];
    tot += d[i];
  }
  int cntPares = 0;
  for(int i = 1; i < n; i++) {
    d[i] += d[i-1];
  }
  if(tot % 2 == 0) {
    for(int i = 0; i < n; i++) {
      if(binary_search(d, d+n, d[i] + tot/2)) {
        cntPares++;
      }
    }
  }
  fat[0] = 1;
  for(int i = 1; i < ms; i++) {
    fat[i] = fat[i-1] * i % mod;
  }
  ifat[ms-1] = fexp(fat[ms-1], mod-2);
  for(int i = ms-1; i > 0; i--) {
    ifat[i-1] = ifat[i] * i % mod;
  }
  int ans = 0;
  for(int uc = 0; uc <= min(m, cntPares); uc++) {
    if(uc == m) {
      if(cntPares * 2 == n) {
        ans = (ans + fat[m]) % mod;
      }
      break;
    }
    if(uc == m-1) {
      if(cntPares <= uc) ans = (ans + fat[m-1] * m) % mod;
      continue;
    }
    int sobrando = n - cntPares*2;
    int tmp = fexp(m-uc, sobrando+cntPares-uc) * fexp(m-uc-1, cntPares-uc) % mod;
    tmp = tmp * choose(cntPares, uc) % mod * choose(m, uc) % mod * ifat[uc] % mod;
    // cout << uc << ": " << tmp << endl;
    ans = (ans + tmp) % mod;
  }
  cout << ans << '\n';
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}