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

  ll l, r; cin >> l >> r;
  ll a = 0, b = 0, c = 0;
  for (a = l; a < r; a++) {
    for (b = a + 1; b < r; b++) {
      for (c = b + 1; c <= r; c++) {
        if (__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) != 1) {
          cout << a << ' ' << b << ' ' << c;
          return 0;
        }
      }
    }
  }

  cout << -1;

  return 0;
}