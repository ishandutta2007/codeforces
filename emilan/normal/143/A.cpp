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

  int r1, r2, c1, c2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (i == j) continue;
      for (int k = 1; k < 10; k++) {
        if (i == k || j == k) continue;
        for (int l = 1; l < 10; l++) {
          if (i == l || j == l || k == l) continue;
          if (i + j == r1 && k + l == r2 &&
              i + k == c1 && j + l == c2 &&
              i + l == d1 && j + k == d2) {
            cout << i << ' ' << j << '\n' << k << ' ' << l;
            return 0;
          }
        }
      }
    }
  }
  cout << -1;

  return 0;
}