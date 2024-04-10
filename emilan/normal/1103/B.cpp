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
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  string s;
  while (cin >> s && s == "start") {
    int cur = 1;
    while (cur < 1e9) {
      cout << "? " << cur * 2 << ' ' << cur << endl;

      char c;
      cin >> c;
      if (c == 'y') break;
      else if (c == 'e') exit(0);

      cur *= 2;
    }

    if (cur >= 1e9) cout << "! 1" << endl;
    else {
      if (cur > 5e8) cur = 5e8;
      cout << "? " << cur * 4 << ' ' << cur * 2 << endl;
      int l = cur + 1, r;
      char c;
      cin >> c;
      if (c == 'y') r = cur * 3 / 2;
      else if (c == 'x') r = cur * 2;
      else exit(0);

      while (l < r) {
        int mi = l + (r - l) / 2;
        cout << "? " << mi * 2 << ' ' << mi << endl;
        cin >> c;
        if (c == 'y') l = mi + 1;
        else if (c == 'x') r = mi;
        else exit(0);
      }

      cout << "! " << l << endl;
    }
  }

  return 0;
}