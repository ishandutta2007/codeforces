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

  vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  dotc() {
    int n;
    cin >> n;
    vi a(n), c(n);
    rep(i, n) cin >> a[i];

    map<int, int> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 11; j++) {
        if (a[i] % primes[j] == 0) {
          if (!m.count(j)) {
            int len = sz(m);
            m[j] = len + 1;
          }
          c[i] = m[j];
          break;
        }
      }
    }

    cout << sz(m) << '\n';
    for (int i : c) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}