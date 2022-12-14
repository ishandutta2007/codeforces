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

  int r, c;
  cin >> r >> c;
  vector<string> m(r);
  rep(i, r) cin >> m[i];

  auto adj = [&](int x, int y) {
    vector<pair<int, int>> ret;
    for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
        if (i * j || (!i && !j)) continue;
        int xx = x + i, yy = y + j;
        if (xx < 0 || xx >= r || yy < 0 || yy >= c) continue;
        ret.eb(xx, yy);
      }
    }
    return ret;
  };

  rep(i, r) {
    rep(j, c) {
      if (m[i][j] == 'S') {
        auto v = adj(i, j);
        for (auto& z : v) {
          auto& a = m[z.fi][z.se];
          if (a == '.') a = 'D';
          else if (a == 'W') {
            cout << "No";
            return 0;
          }
        }
      }
    }
  }

  cout << "Yes\n";
  for (string s : m) cout << s << '\n';

  return 0;
}