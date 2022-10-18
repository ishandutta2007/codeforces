#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ans;
  vector<bool> used(n + 1, false);
  for (int i = 2; i <= n; ++i) {
    if (!used[i]) {
      int x = i;
      for (int t = i; t <= n; t += i)
        used[t] = true;
      while (x <= n) {
        ans.push_back(x);
        x *= i;
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  if (ans.size()) {
    for (int i = 0; i < ans.size(); ++i) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}