#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    vector <int> dp(n + 1);
    for (int i = n; i >= 0; i--) {
      int newpos = i + a[i];
      dp[i] = a[i] + (newpos <= n ? dp[newpos] : 0);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}