#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    a.push_back(a[i]);
  int pos = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > a[pos])
      pos = i;
  stack <pair <int, int>> s;
  ll ans = 0;
  for (int i = pos; i < pos + n; i++) {
    while (!s.empty() && s.top().first < a[i]) {
      ans += s.top().second;
      s.pop();
    }
    if (!s.empty() && s.top().first == a[i]) {
      ans += s.top().second;
      if (s.size() >= 2)
        ans++;
    }
    if (!s.empty() && s.top().first != a[i])
      ans++;
    if (!s.empty() && s.top().first == a[i])
      s.top().second++;
    else
      s.push({a[i], 1});
  }
  vector <pair <ll, ll>> x;
  while (!s.empty()) {
    x.push_back(s.top());
    s.pop();
  }
  reverse(x.begin(), x.end());
  for (int i = 1 + (x[0].second == 1); i < (int)x.size(); i++)
    ans += x[i].second;
  cout << ans;
  return 0;
}