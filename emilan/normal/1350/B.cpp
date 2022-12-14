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
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    rep(i, n) cin >> a[i + 1];

    int mx = 0;
    for (int i = n; i > 0; i--) {
      int cur = 1;
      for (int j = i + i; j <= n; j += i) {
        if (a[i] < a[j]) cur = max(cur, b[j] + 1);
      }
      mx = max(mx, cur);
      b[i] = cur;
    }

    cout << mx << '\n';
  }

  return 0;
}