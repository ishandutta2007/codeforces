#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

int main() {
  ioThings();

  int r1 = 0, p1 = 0, p2 = 1e9;
  int n; cin >> n;
  while (n--) {
    int m; cin >> m;
    r1 = max(r1, m);
  }
  cin >> n;
  while (n--) {
    int m; cin >> m;
    p1 = max(p1, m);
  }
  cin >> n;
  while (n--) {
    int m; cin >> m;
    p2 = min(p2, m);
  }

  int a, b; cin >> a >> b;

  cout << setprecision(6) << fixed << sqrt((double)b * p1 / (a * p2 + b * p1)) * r1;
  

  return 0;
}