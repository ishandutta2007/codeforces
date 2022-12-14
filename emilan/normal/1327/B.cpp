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
    int n;
    cin >> n;

    set<int> m;
    int d = -1;
    rep(i, n) {
      int k;
      cin >> k;
      vi a(k);
      rep(j, k) cin >> a[j];

      bool flag = false;
      for (auto& j : a) {
        if (!m.count(j)) {
          m.insert(j);
          flag = true;
          break;
        }
      }

      if (!flag) d = i;
    }

    if (d == -1) cout << "OPTIMAL\n";
    else {
      cout << "IMPROVE\n";

      int p = 0;
      for (auto& i : m) {
        if (i - p != 1) {
          break;
        }

        p = i;
      }
      cout << d + 1 << ' ' << p + 1 << '\n';
    }
  }

  return 0;
}