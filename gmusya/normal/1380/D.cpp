#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

ll x, y, k;

ll solve(vector <int> &arr) {
  if (arr.size() == 2)
    return 0;
  ll res = INF;
  ll a = arr[0], b = arr.back();
  int sz = (int)arr.size() - 2;
  {
    ll ma = 0;
    for (int i = 1; i + 1 < (int)arr.size(); i++)
      ma = max(ma, (ll)arr[i]);
    if (max(a, b) > ma)
      res = min(res, sz * y);
  }
  if (sz >= k) {
    res = min(res, sz / k * x + (sz % k) * y);
    res = min(res, x + (sz - k) * y);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  cin >> x >> k >> y;
  vector <int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
  }
  a[0] = 0, a.back() = 1;
  vector <int> b(m + 2);
  b[0] = 0, b.back() = 1;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    b[i]++;
  }
  n += 2, m += 2;
  vector <int> p(n);
  for (int i = 0; i < n; i++)
    p[a[i]] = i;
  for (int i = 0; i + 1 < m; i++)
    if (p[b[i]] > p[b[i + 1]]) {
      cout << -1;
      return 0;
    }
  ll res = 0;
  for (int i = 0; i + 1 < m; i++) {
    int l = p[b[i]], r = p[b[i + 1]];
    vector <int> tmp;
    for (int j = l; j <= r; j++)
      tmp.push_back(a[j]);
    res += solve(tmp);
    if (res >= INF) {
      cout << -1;
      return 0;
    }
  }
  cout << res;
  return 0;
}