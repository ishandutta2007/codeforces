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

  cout << setprecision(7) << fixed;
  double pi = acos(-1.0);

  dotc() {
    int n;
    cin >> n;

    auto calc = [&](double start) {
      //cout << start / acos(-1.0) * 180 << endl;
      double rad = pi * 0.5 - start;
      double ans1 = 0, ans2 = 0;
      for (int i = 0; i < n; i++, rad -= pi / n) {
        ans1 += abs(cos(rad));
        ans2 += abs(sin(rad));
        //cout << i << ' ' << rad / acos(-1.0) * 180 << ' ' << ans << endl;
      }
      return max(ans1, ans2);
    };

    double l = 0, r = acos(-1.0) / n;
    while (l * (1 + 1e-9) < r) {
      double m1 = (l * 2 + r) / 3;
      double m2 = (r * 2 + l) / 3;

      if (calc(m1) < calc(m2)) r = m1;
      else l = m2;
    }

    //cout << l / pi * 180  << '\n';
    cout << calc(l) << '\n';
  }

  return 0;
}