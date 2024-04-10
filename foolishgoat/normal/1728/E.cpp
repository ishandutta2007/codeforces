#include <bits/stdc++.h>

using namespace std;

long long euclid(long long p, long long q, long long& x, long long& y) {
  if (p == 0) {
    x = 0, y = 1;
    return q;
  }
  long long d = euclid(q % p, p, x, y);
  long long tmp = y - (q / p) * x;
  y = x;
  x = tmp;
  return d;
}

void solve() {
  int n;
  cin >> n;
  long long cur = 0;
  vector<int> diff(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    cur += b;
    diff[i] = a - b;
  }
  sort(diff.rbegin(), diff.rend());
  vector<long long> pre(n+1);
  pre[0] = cur;
  int mid = 0;
  for (int i = 0; i < n; ++i) {
    if (diff[i] > 0)
      mid = i+1;
    pre[i+1] = pre[i] + diff[i];
  }
  int m;
  cin >> m;
  while (m--) {
    long long p, q;
    cin >> p >> q;
    long long x, y;
    long long d = euclid(p, q, x, y);
    if ((n % d)) {
      cout << "-1\n";
      continue;
    }
    long long g = n / d;
    x *= g;
    long long cx = q / d;
    long long min_x = x % cx;
    if (min_x < 0) min_x += cx;
    long long ans = -1;
    min_x += (max(mid - min_x * p, 0LL) / cx / p) * cx;
    for (int i = 0; i < 3; ++i) {
      if (min_x * p > n)
        break;
      ans = max(ans, pre[min_x * p]);
      min_x += cx;
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}