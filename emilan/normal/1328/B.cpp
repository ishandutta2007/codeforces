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
    int n, k; cin >> n >> k;
    int l = 1, r = n;
    auto fcn = [&](ll x){return (x + 1) * x / 2;};
    while (l < r) {
      ll m = l + (r - l) / 2;

      if (fcn(m) < k) l = m + 1;
      else r = m;
    }

    ll c = l - (fcn(l) - k) - 1;
    string s;
    while (n--) {
      s += (n == l || n == c) ? 'b' : 'a';
    }

    cout << s << '\n';
  }

  return 0;
}