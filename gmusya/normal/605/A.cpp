#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector <int> p(n);
  for (int i = 0; i < n; i++)
    p[a[i]] = i;
  vector <int> dp(n, 1);
  for (int i = 1; i < n; i++)
    dp[i] = (p[i] > p[i - 1] ? dp[i - 1] : 0) + 1;
  cout << n - *max_element(dp.begin(), dp.end());
  return 0;
}