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
    string s; cin >> s;
    int l = 1, r = sz(s) + 1;
    while (l < r) {
      int m = (l + r) / 2;

      bool ok = false;
      int pos = 0, j;
      for (;;) {
        if (pos + m >= sz(s) + 1) {
          ok = true;
          break;
        }

        for (j = m; j > 0; j--) {
          if (s[pos + j - 1] == 'R') {
            pos += j;
            break;
          }
        }
        if (!j) break;
      }

      if (ok) r = m;
      else l = m + 1;
    }

    cout << l << '\n';
  }

  return 0;
}