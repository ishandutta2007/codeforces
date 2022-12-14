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

  int n; cin >> n;
  vector<int> seg(n);
  for (int i = 0; i < n; i++)
    cin >> seg[i];
  sort(all(seg));

  vector<int> diff(n);
  adjacent_difference(all(seg), diff.begin());
  int mn = 1e9;
  for (int i = n - 3; i >= 0; i--) {
    mn = min(mn, diff[i + 2]);
    if (mn < seg[i]) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}