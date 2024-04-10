#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool dp[10005][5];

int main() {
  string s;
  cin >> s;
  set<string> f;
  int n = s.size(); s+= "$$$";

  // for (int i = 5; i + 1 < n; ++i) {
  //   if (i + 3 == n) continue;

  //   if (s[i] != s[i + 2] || s[i + 1] != s[i + 3]) {
  //     f.insert(s.substr(i, 2));
  //   }
  // }
  // for (int i = 5; i + 2 < n; ++i) {
  //   if (i + 4 == n) continue;

  //   if (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5]) {
  //     f.insert(s.substr(i, 3));
  //   }
  // }

  dp[n][2] = dp[n][3] = true;
  for (int i = n - 1; i >= 5; --i) {
    if (i + 2 <= n && (dp[i + 2][2] && s.substr(i + 2, 2) != s.substr(i, 2) || dp[i + 2][3])) {
      dp[i][2] = true;
      f.insert(s.substr(i, 2));
    }
    if (i + 3 <= n && (dp[i + 3][2] || dp[i + 3][3] && s.substr(i + 3, 3) != s.substr(i, 3))) {
      dp[i][3] = true;
      f.insert(s.substr(i, 3));
    }
  }

  cout << f.size() << endl;
  for (string x : f)
    cout << x << endl;
  return 0;
}