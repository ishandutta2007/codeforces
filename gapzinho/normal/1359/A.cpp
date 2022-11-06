
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 3000+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = min(n/k, m);
  m -= a;
  for(int i = 1; i < k; i++) {
    arr[i] = 0;
  }
  int cur = 0;
  while(m > 0) {
    arr[cur+1]++;
    m--;
    cur = (cur + 1) % (k-1);
  }
  cerr << a << endl;
  cout << a - arr[1] << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}