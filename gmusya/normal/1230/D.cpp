#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <ll, ll>> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i].first;
  for (int i = 0; i < n; i++)
    cin >> a[i].second;
  vector <bool> tf(n);
  vector <int> take;
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (a[i].first == a[j].first) flag = true;
    }
    if (flag)
      take.push_back(i), tf[i] = true;
  }
  for (int i = 0; i < n; i++) {
    if (tf[i]) continue;
    bool flag = false;
    for (auto &j : take)
      if ((a[i].first & a[j].first) == a[i].first)
        flag = true;
    if (flag)
      take.push_back(i);
  }
  ll ans = 0;
  for (auto &i : take)
    ans += a[i].second;
  if (take.size() == 1)
    ans = 0;
  cout << ans;
  return 0;
}