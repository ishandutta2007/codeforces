#include <bits/stdc++.h>
using namespace std;

void ioThings() {
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

  int n, m, k, t; cin >> n >> m >> k >> t;
  vector<int> waste(k);
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    waste[i] = (x - 1) * m + y - 1;
  }
  sort(all(waste));
  while (t--) {
    int i, j; cin >> i >> j;
    int pos = (i - 1) * m + j - 1;
    auto lb = lower_bound(all(waste), pos);
    auto ub = upper_bound(all(waste), pos);
    if (lb != ub)
      cout << "Waste\n";
    else {
      int dist = distance(waste.begin(), lb);
      int c = (pos - dist) % 3;
      if (c == 0)
        cout << "Carrots\n";
      else if (c == 1)
        cout << "Kiwis\n";
      else
        cout << "Grapes\n";
    }
  }

  return 0;
}