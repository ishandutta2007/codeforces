#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <ll> dp(10, -1e18);
  dp[0] = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector <ll> newdp = dp;
    int k;
    cin >> k;
    vector <ll> a1, a2, a3;
    for (int j = 0; j < k; j++) {
      int c, d;
      cin >> c >> d;
      if (c == 1)
        a1.push_back(d);
      if (c == 2)
        a2.push_back(d);
      if (c == 3)
        a3.push_back(d);
    }
    sort(a1.rbegin(), a1.rend());
    sort(a2.rbegin(), a2.rend());
    sort(a3.rbegin(), a3.rend());
    if (a1.size() >= 3) { // 1 + 1 + 1 = 3
      ll a = a1[0], b = a1[1], c = a1[2];
      for (int oldc = 0; oldc < 7; oldc++)
        newdp[oldc + 3] = max(newdp[oldc + 3], dp[oldc] + a + b + c);
      for (int oldc = 7; oldc <= 9; oldc++)
        newdp[oldc - 7] = max(newdp[oldc - 7], dp[oldc] + 2 * a + b + c);
    }
    if (a1.size() >= 2) { // 1 + 1 = 2
      ll a = a1[0], b = a1[1];
      for (int oldc = 0; oldc < 8; oldc++)
        newdp[oldc + 2] = max(newdp[oldc + 2], dp[oldc] + a + b);
      for (int oldc = 8; oldc <= 9; oldc++)
        newdp[oldc - 8] = max(newdp[oldc - 8], dp[oldc] + 2 * a + b);
    }
    if (a1.size() >= 1) { // 1 = 1
      ll a = a1[0];
      for (int oldc = 0; oldc < 9; oldc++)
        newdp[oldc + 1] = max(newdp[oldc + 1], dp[oldc] + a);
      newdp[0] = max(newdp[0], dp[9] + 2 * a);
    }
    if (a1.size() >= 1 && a2.size() >= 1) { // 1 + 2 = 3
      ll a = a1[0], b = a2[0];
      if (a < b)
        swap(a, b);
      for (int oldc = 0; oldc < 8; oldc++)
        newdp[oldc + 2] = max(newdp[oldc + 2], dp[oldc] + a + b);
      for (int oldc = 8; oldc <= 9; oldc++)
        newdp[oldc - 8] = max(newdp[oldc - 8], dp[oldc] + 2 * a + b);
    }
    if (a2.size() >= 1) {
      ll a = a2[0];
      for (int oldc = 0; oldc < 9; oldc++)
        newdp[oldc + 1] = max(newdp[oldc + 1], dp[oldc] + a);
      newdp[0] = max(newdp[0], dp[9] + 2 * a);
    }
    if (a3.size() >= 1) {
      ll a = a3[0];
      for (int oldc = 0; oldc < 9; oldc++)
        newdp[oldc + 1] = max(newdp[oldc + 1], dp[oldc] + a);
      newdp[0] = max(newdp[0], dp[9] + 2 * a);
    }
    for (int i = 0; i <= 9; i++)
      dp[i] = max(dp[i], newdp[i]);
  }
  cout << *max_element(dp.begin(), dp.end());
  return 0;
}