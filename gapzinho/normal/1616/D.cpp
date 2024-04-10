#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 50005; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[ms];
int pre[ms];
int biggestPre[ms];
int biggestSuf[ms];
int choose[ms];

void solve() {
  int n, x;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> x;
  for(int i = 1; i<=n; i++) a[i] -= x;
  int ans = 0;
  choose[0] = 1;
  for(int i = 1; i <= n; i++) {
    pre[i] = pre[i-1] + a[i-1];
    if(!choose[i-1] && pre[i] - biggestPre[i-1] + a[i] < 0) {
      choose[i] = 1;
      // cout << "Tirei o " << i << endl;
      ans++;
    } else {
      choose[i] = 0;
    }
    biggestPre[i] = max(pre[i], biggestPre[i-1]);
    if (choose[i-1]) biggestPre[i] = pre[i];
  }
  cout << n - ans << '\n';
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // #ifdef ONLINE_JUDGE
  //   freopen("grid.in", "r", stdin);
  //   freopen("grid.out", "w", stdout);
  // #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}