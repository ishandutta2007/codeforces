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
    int n; cin >> n;

    int x = -1;
    vector<int> a(n);
    rep(i, n)
      cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        if (x == -1)
          x = i;
        else {
          cout << "2\n" << x + 1 << ' ' << i + 1 << '\n';
          break;
        }
      } else {
        cout << "1\n" << i + 1 << '\n';
        break;
      }

      if (i == n - 1)
        cout << "-1\n";
    }
  }

  return 0;
}