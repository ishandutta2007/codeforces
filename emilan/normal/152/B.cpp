#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, m; cin >> n >> m;
  int cx, cy; cin >> cx >> cy;
  int k; cin >> k;
  ll steps = 0;
  while (k--) {
    int dx, dy; cin >> dx >> dy;
    int ds = 1e9;
    if (dx)
      ds = min(ds, dx > 0 ? (n - cx) / dx : -(1 - cx) / -dx);
    if (dy)
      ds = min(ds, dy > 0 ? (m - cy) / dy : -(1 - cy) / -dy);
    steps += ds;
    cx += ds * dx;
    cy += ds * dy;
  }

  cout << steps;

  return 0;
}