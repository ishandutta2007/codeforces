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

    string s;
    cin >> s;

    vi a(n), p(n);
    rep(i, n) {
      if (s[i] == '1') {
        a[max(0, i - k)]++;
        if (i + k + 1 < n) a[i + k + 1]--;
      }
    }
    partial_sum(all(a), p.begin());

    int d = 0, cnt = 0;
    rep(i, n) {
      if (!p[i]) {
        if (!d) d = k, cnt++;
        else d--;
      } else d = 0;
    }

    cout << cnt << '\n';
  }

  return 0;
}