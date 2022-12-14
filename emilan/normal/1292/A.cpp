#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, q; cin >> n >> q;
  vector<vector<int>> lava(n, {0, 0});

  int cnt = 0;
  while (q--) {
    int r, c; cin >> r >> c;
    r--, c--;

    int obs = 0;
    if (c != 0 && lava[c - 1][r ^ 1]) obs++;
    if (c != n - 1 && lava[c + 1][r ^ 1]) obs++;
    if (lava[c][r ^ 1]) obs++;

    lava[c][r] ^= 1;
    cnt += (lava[c][r] ? 1 : -1) * obs;

    cout << (cnt == 0 ? "yes" : "no") << '\n';
  }

  return 0;
}