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

  int n;
  cin >> n;

  vi a(n);
  rep(i, n) cin >> a[i];

  ll gcd = 1;
  int sqr = sqrt(200000) + 5;
  for (int i = 2; i < sqr; i++) {
    int cnt = 0;
    while (cnt < 2) {
      cnt = 0;
      rep(r, n) {
        if (a[r] % i) cnt++;
        else a[r] /= i;
      }
      if (cnt < 2) gcd *= i;
    }
  }

  int c = 0;
  for (int i = 0; i < n && c < 2; i++) {
    if (a[i] < sqr) continue;
    c++;
    int cnt = 0, cur = a[i];
    rep(r, n) {
      if (a[r] % cur) cnt++;
      else a[r] /= cur;
    }
    if (cnt < 2) {
      gcd *= cur;
    }
  }

  cout << gcd;

  return 0;
}