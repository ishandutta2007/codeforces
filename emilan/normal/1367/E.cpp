#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define fastio    ios::sync_with_stdio(0); cin.tie(0)
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
  fastio;
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<char, int> f;
    for (char c : s) f[c]++;
    vi a;
    for (auto& i : f) a.pb(i.se);

    int mx = *max_element(all(a));
    for (int i = 2; i <= k; i++) {
      if (k % i == 0) {
        int l = 0, r = n / i;
        while (l < r) {
          int mi = (l + r + 1) / 2;

          int cur = 0;
          for (int j : a) cur += j / mi;

          if (cur >= i) l = mi;
          else r = mi - 1;
        }

        mx = max(mx, l * i);
      }
    }

    cout << mx << '\n';
  }

  return 0;
}