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

  int p, q, l, r; cin >> p >> q >> l >> r;
  vector<bool> z(1001);
  while (p--) {
    int a, b; cin >> a >> b;
    while (a <= b)
      z[a++] = true;
  }

  vector<pair<int, int>> x(q);
  for (int i = 0; i < q; i++)
    cin >> x[i].fi >> x[i].se;
  
  int cnt = 0;
  while (l <= r) {
    bool ok = false;
    for (auto& s : x) {
      int end = min(s.se + l, 1000);
      for (int i = s.fi + l; i <= end; i++)
        if (z[i]) {
          ok = true;
          cnt++;
          break;
        }
      if (ok)
        break;
    }
    l++;
  }

  cout << cnt;
    

  return 0;
}