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

  int x1, y1, x2, y2;
  int x3, y3, x4, y4;
  int x5, y5, x6, y6;

  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  cin >> x5 >> y5 >> x6 >> y6;

  if (x3 <= x1 && x2 <= x4) {
    if (y3 <= y1 && y1 <= y4) y1 = y4;
    if (y3 <= y2 && y2 <= y4) y2 = y3;
  }

  if (y3 <= y1 && y2 <= y4) {
    if (x3 <= x1 && x1 <= x4) x1 = x4;
    if (x3 <= x2 && x2 <= x4) x2 = x3;
  }

  if (x5 <= x1 && x2 <= x6) {
    if (y5 <= y1 && y1 <= y6) y1 = y6;
    if (y5 <= y2 && y2 <= y6) y2 = y5;
  }

  if (y5 <= y1 && y2 <= y6) {
    if (x5 <= x1 && x1 <= x6) x1 = x6;
    if (x5 <= x2 && x2 <= x6) x2 = x5;
  }

  if (x1 >= x2 || y1 >= y2) cout << "NO";
  else cout << "YES";
  

  return 0;
}