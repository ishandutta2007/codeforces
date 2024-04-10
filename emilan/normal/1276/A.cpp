#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

ll mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    string s;
    cin >> s;

    size_t i = 0;
    while ((i = s.find("twone", i)) != s.npos) {
      s[i + 2] = '_';
      i += 5;
    }

    i = 0;
    while ((i = s.find("one", i)) != s.npos) {
      s[i + 1] = '_';
      i += 3;
    }

    i = 0;
    while ((i = s.find("two", i)) != s.npos) {
      s[i + 1] = '_';
      i += 3;
    }

    vi pos;
    rep(r, sz(s)) if (s[r] == '_') pos.pb(r);

    cout << sz(pos) << '\n';
    for (int r : pos) cout << r + 1 << ' ';
    cout << '\n';
  }

  return 0;
}