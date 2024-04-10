#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector <int> a;
  for (char c : s)
    a.push_back(c - '0');
  int n = a.size();
  vector <int> dp(n + 1);
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j <= min(i, 10); j++) {
      s += a[i - j];
      dp[i + 1] = max(dp[i + 1], dp[i - j] + (s % 3 == 0));
    }
  }
  cout << dp[n];
  return 0;
}