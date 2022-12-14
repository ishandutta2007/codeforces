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
// #define int ll
using vi = vector<int>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  int n;
  cin >> n;
  vi a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) {
    cin >> b[i];
    c[i] = a[i] - b[i];
  }
  sort(all(c));

  ll cnt = 0;
  rep(i, n - 1) {
    auto it = upper_bound(c.begin() + i + 1, c.end(), -c[i]);
    cnt += distance(it, c.end());
  }

  cout << cnt;

  return 0;
}