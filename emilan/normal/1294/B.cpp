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
    vector<pair<int, int>> p(n + 1);
    rep(i, n) cin >> p[i].se >> p[i].fi;
    p[n] = {0, 0};

    sort(all(p));

    string s;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (p[i - 1].se > p[i].se) {
        ok = false;
        break;
      }
      s.append(p[i].se - p[i - 1].se, 'R');
      s.append(p[i].fi - p[i - 1].fi, 'U');
    }


    ok ? cout << "YES\n" << s << '\n' : cout << "NO\n";
  }

  return 0;
}