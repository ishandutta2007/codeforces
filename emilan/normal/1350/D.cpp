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
    int n, k;
    cin >> n >> k;

    vi a(n);
    bool ok = false;
    rep(i, n) {
      cin >> a[i];
      if (a[i] == k) ok = true;
    }

    if (!ok) {
      cout << "no\n";
      continue;
    }

    if (n < 3) {
      sort(all(a));
      if (a[0] != k) cout << "no\n";
      else cout << "yes\n";
      continue;
    }

    bool yes = false;
    for (int i = 0; i < n - 2; i++) {
      vi b(a.begin() + i, a.begin() + i + 3);
      sort(all(b));
      if (b[1] >= k) {
        yes = true;
        break;
      }
    }

    cout << (yes ? "yes\n" : "no\n");
  }

  return 0;
}