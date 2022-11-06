#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
// using i4 = tuple<int, int, int, int>;
using i4 = pair<ii, ii>;
using ll = long long;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 1e6+5;
const int mod = 1e9+7;;


int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int p[ms];
int startacc[ms];

void solve() {
  int n;
  cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
    return;
  }
  for(int i = 0; i <= n; i++) {
    // p[i] = 0;
    startacc[i] = 0;
  }
  int acc = 0;
  int inv = fexp(2, mod-2);
  for(int i = n; i > 1; i--) {
    int k = i/2;
    int x = 0;
    if(i != n) {
      x++;
    }
    x += (i-k-1);
    // cout << i << " -> " << x << endl;
    acc = (acc + startacc[i]) % mod;
    int magic = (1 + mod - acc) % mod;
    p[i] = magic * fexp(inv, x) % mod;
    // cout << i << " ?? " << p[i] << " - " << x << " e " << acc << " com " << magic << endl;
    startacc[k] = (startacc[k] + p[i]) % mod;
  }
  for(int i = 1; i <= n; i++) {
    cout << p[i] << "\n";
  }
  // cout << '\n';
}
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= 500; i++) {
    
  }
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}