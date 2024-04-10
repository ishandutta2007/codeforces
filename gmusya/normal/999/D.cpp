#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n), c(m);
  vector <vector <int>> g(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i] % m]++;
    g[a[i] % m].push_back(i);
  }
  int st = 0;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum += (c[i] - n / m);
    if (sum < 0) {
      st = i + 1;
      sum = 0;
    }
  }
  vector <int> ids;
  vector <int> mod;
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n / m; i++)
      mod.push_back((st + j) % m);
  for (int j = 0; j < m; j++)
    for (int i = 0; i < (int) c[(st + j) % m]; i++)
      ids.push_back(g[(st + j) % m][i]);
  long long ans = 0;
  vector <int> b = a;
  for (int i = 0; i < n; i++) {
    int blizh = a[ids[i]] - mod[i];
    if (blizh % m)
      blizh += m - (blizh % m + m) % m;
    blizh += mod[i];
    b[ids[i]] = blizh;
    ans += b[ids[i]] - a[ids[i]];
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++)
    cout << b[i] << ' ';
  return 0;
}