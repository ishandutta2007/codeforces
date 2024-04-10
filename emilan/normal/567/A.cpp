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

  int n; cin >> n;
  vector<ll> x(n + 2);
  x[0] = -1e18, x[n + 1] = 1e18;
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  
  for (int i = 1; i <= n; i++) {
    cout << min(x[i] - x[i - 1], x[i + 1] - x[i]) << ' ';
    cout << max(x[i] - x[1], x[n] - x[i]) << '\n';
  }

  return 0;
}