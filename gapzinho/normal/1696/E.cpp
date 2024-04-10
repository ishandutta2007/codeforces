#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 1e9;
const int ms = 1e6+1;
const int mod = 1e9+7;

// int arr[ms];
int fat[ms], ifat[ms];

int choose(int a, int b) {
  return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
}

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  fat[0] = 1;
  for(int i = 1; i < ms; i++) {
    fat[i] = (fat[i-1] * i) % mod;
  }
  ifat[ms-1] = fexp(fat[ms-1], mod-2);
  for(int i = ms-2; i >= 0; i--) {
    ifat[i] = ifat[i+1] * (i+1) % mod;
  }
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i <= n; i++) {
    int x;
    cin >> x;
    if(x == 0) continue;
    ans = (ans + choose(x+i, x-1)) % mod;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}