#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(00);
  int n;
  cin >> n;
  vector <int> g(n * n);
  for (int i = 0; i < n * n; i++)
    cin >> g[i];
  vector <int> a;
  sort(g.rbegin(), g.rend());
  for (int i = 0; i < n * n; i++) {
    int l = i;
    int r = i;
    while (r < n * n && g[l] == g[r])
      r++;
    r--;
    int cnt = 0;
    vector <int> d;
    int good = 0;
    for (int j = 0; j < (int) a.size(); j++)
      if (a[j] % g[l] == 0) {
        good++;
        d.push_back(a[j]);
      }
    for (int j1 = 0; j1 < (int) d.size(); j1++)
      for (int j2 = 0; j2 < (int) d.size(); j2++)
        if (__gcd(d[j1], d[j2]) == g[l])
          cnt++;
    int k = 0;
    while (k * k + cnt + 2 * k * good != r - l + 1)
      k++;
    while (k--)
      a.push_back(g[l]);
    i = r;
  }
  for (auto &now : a)
    cout << now << ' ';
  return 0;
}