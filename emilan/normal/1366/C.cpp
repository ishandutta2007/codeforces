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

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    int n, m;
    cin >> n >> m;

    vvi v(n, vi(m));
    rep(i, n) rep(j, m) cin >> v[i][j];

    int cnt = 0;
    rep(i, (n + m - 1) / 2) {
      int a = 0, b = 0;
      for (int j = 0; j <= i; j++) {
        // cout << i << ' ' << j << endl;
        if (i - j >= 0 && i - j < n && j < m) {
          if (v[i - j][j]) a++;
          else b++;
        }

        if (n - i + j - 1 >= 0 && n - i + j - 1 < n && m - j - 1 >= 0) {
          if (v[n - i + j - 1][m - j - 1]) a++;
          else b++;
        }
      }
      cnt += min(a, b);
    }

    cout << cnt << '\n';
  }

  return 0;
}