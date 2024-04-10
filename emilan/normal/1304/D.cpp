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

using ll = long long;
//#define int ll
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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

ll mod(1000000007);
double pi(acos(-1.0));

int main() {
  ioThings();

  dotc() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi ret1;
    int cur = n;
    rep(i, n - 1) {
      if (s[i] == '>') ret1.pb(cur);
      else {
        int cnt = 1;
        for (int j = i + 1; j < n - 1; j++) {
          if (s[j] == '>') break;
          cnt++;
        }
        for (int j = cnt; j >= 0; j--) {
          ret1.pb(cur - j);
        }
        cur -= cnt;
        i += cnt;
      }
      cur--;
    }

    if (sz(ret1) != n) ret1.pb(cur);

    for (int i : ret1) cout << i << ' ';
    cout << '\n';

    vi ret2;
    cur = 1;
    rep(i, n - 1) {
      if (s[i] == '<') ret2.pb(cur);
      else {
        int cnt = 1;
        for (int j = i + 1; j < n - 1; j++) {
          if (s[j] == '<') break;
          cnt++;
        }
        for (int j = cnt; j >= 0; j--) {
          ret2.pb(cur + j);
        }
        cur += cnt;
        i += cnt;
      }
      cur++;
    }

    if (sz(ret2) != n) ret2.pb(cur);

    for (int i : ret2) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}