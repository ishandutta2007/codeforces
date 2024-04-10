#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

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

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  dotc() {
    int n, x, y; cin >> n >> x >> y;
    
    int mn = (x - 1 - min(max(n - y - 1, 0), x - 1)
           + y - 1 - min(max(n - x - 1, 0), y - 1) + 1) / 2 + 1;

    int m1 = min(n - x, y - 1), m2 = min(n - y, x - 1);
    int mx = m1 + m2 + max(y - 1 - m1, 0) + 1;
    cout << mn << ' ' << mx << '\n';
  }

  return 0;
}