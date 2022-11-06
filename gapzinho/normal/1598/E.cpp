
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 1000+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[ms][ms];
int n, m , q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int get(int x, int y, int d1, int d2) {
  if(x < 0 || x >= n || y < 0 || y >= m || a[x][y]) {
    return 0;
  }
  return 1 + get(x+dx[d1], y+dy[d1], d2, d1);
}

void solve() {
  cin >> n >> m >> q;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int dx = n-i-1;
      int dy = m-j-1;
      ans++;
      ans += min(dx, dy)*4;
      if(dx != dy) ans++;
      // if(i == n-1 && j < m-1) ans--;
      // else if(i < n-1 && j == m-1) ans--;
    }
  }
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++) {
  //     if(i+1 < n) ans++;
  //     if(j+1 < n) ans++;
  //     ans++;
  //   }
  // }
  // cout << ans << endl;
  while(q--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int tmp = a[x][y];
    a[x][y] = 0;
    int cur = get(x, y, 1, 0)*get(x, y, 2, 3) + get(x, y, 0, 1)*get(x, y, 3, 2) - 1;
    // cout << cur << " ";
    if(!tmp) {
      ans-=cur;
    } else {
      ans+=cur;
    }
    a[x][y] = !tmp;
    cout << ans << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  // cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}