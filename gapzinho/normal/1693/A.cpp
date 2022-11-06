#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}



const int ms = 1e6+3;

int a[ms], b[ms];

void solve() {
  int n;
  cin >> n;
  int lst = -1;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i]) lst = i;
  }
  if(lst != -1) {
    a[lst]++;
    a[0]--;
  }
  for(int i = n-2; i >= 0; i--) {
    a[i] += a[i+1];
  }
  for(int i = n-1; i >= 0; i--) {
    if(a[i] > 0) {
      cout << "NO\n";
      return;
    }
  }
  if(a[0] == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}