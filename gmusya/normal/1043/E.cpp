#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <ll> x(n), y(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  vector <pair <int, int>> e(m);
  for (int i = 0; i < m; i++) {
    cin >> e[i].first >> e[i].second;
    e[i].first--, e[i].second--;
  }
  ll sumy = 0;
  for (ll tmp : y)
    sumy += tmp;
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return x[i] - y[i] < x[j] - y[j];
  });
  vector <ll> ans(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ans[p[i]] = sumy + (n - 2) * y[p[i]];
    ans[p[i]] += sum;
    ans[p[i]] += (n - i - 1) * (x[p[i]] - y[p[i]]);
    sum += x[p[i]] - y[p[i]];
  }
  for (auto [u, v] : e) {
    ll todel = min(x[u] + y[v], x[v] + y[u]);
    ans[u] -= todel;
    ans[v] -= todel;
  }
  for (ll cur : ans)
    cout << cur << ' ';
  return 0;
}