#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int n;
  cin >> n;
  vector <ll> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 2; i <= n; i++)
    a[i] += a[i - 1]; // sum on [i; j) = a[j - 1] - a[i]
  pair <pair <ll, ll>, pair <ll, ll>> ans = {{-INF, -1}, {-1, -1}};
  for (int i = 1; i <= n + 1; i++) {
    pair <ll, ll> left = {-INF, -1}, right = {-INF, -1};
    for (int j = 1; j <= i; j++) // [1; j) u [j; i)
      left = max(left, {(a[j - 1] - a[0]) - (a[i - 1] - a[j - 1]), j});
    for (int j = i; j <= n + 1; j++) // [i; j) u [j; n+1)
      right = max(right, {(a[j - 1] - a[i - 1]) - (a[n] - a[j - 1]), j});
    ans = max(ans, {{left.fi + right.fi, left.se}, {i, right.se}});
  }
  cout << ans.fi.se - 1 << ' ' << ans.se.fi - 1 << ' ' << ans.se.se - 1;
  return 0;
}