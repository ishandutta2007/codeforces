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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);

    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i] > a[i + 1])
        b[i] = 1;
    }

    int cur = accumulate(b.begin() + 1, b.begin() + k - 1, 0);
    int l = 0, mx = cur;
    for (int i = 1; i < n - k + 1; i++) {
      cur += -b[i] + b[i + k - 2];
      if (cur > mx) {
        mx = cur;
        l = i;
      }
    }

    cout << mx + 1 << ' ' << l + 1 << '\n';
  }

  return 0;
}