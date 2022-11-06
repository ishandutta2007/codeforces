#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;
const int inf = 1e9;
const int ms = 5e5+5;

int arr[ms];

void solve() {
  int n, z;
  cin >> n >> z;
  int resp = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    resp = max(resp, x | z);
  }
  cout << resp << '\n';
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
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}