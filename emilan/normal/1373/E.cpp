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
    int n, k;
    cin >> n >> k;

    vi mn;
    rep(i, 10) {
      int m = n;
      rep(j, k + 1) m -= (i + j) % 10;
      int a = min(k + 1, 10 - i);
      int b = k + 1 - a;

      rep(j, 20) {
        int rhs = m + 9 * b * j - b;
        if (rhs < 0) break;
        if (rhs % (a + b)) continue;

        int sol = rhs / (a + b);
        vi cur{i};
        int nine = j;
        while (nine --> 0) {
          cur.pb(9);
          sol -= 9;
        }
        if (sol < 0) break;

        if (b && sol > 7) {
          cur.pb(8);
          sol -= 8;
        }

        while (sol > 8) {
          cur.pb(9);
          sol -= 9;
        }
        
        if (sol) cur.pb(sol);
        reverse(all(cur));

        if (mn.empty() ||
            sz(mn) > sz(cur) ||
            (sz(mn) == sz(cur) && mn > cur)) mn = cur;
      }
    }

    if (mn.empty()) cout << -1;
    else {
      for (int i : mn) cout << i;
    }
    cout << '\n';
  }

  return 0;
}