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

  dotc() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x1, x, x2, y1, y, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if ((x1 == x2 && (a || b)) ||
        (y1 == y2 && (c || d))) {
      cout << "NO\n";
      continue;
    }

    x1 -= x, x2 -= x;
    y1 -= y, y2 -= y;

    if (b - a > x2 || b - a < x1 || d - c > y2 || d - c < y1) cout << "NO\n";
    else cout << "YES\n";
  }

  return 0;
}