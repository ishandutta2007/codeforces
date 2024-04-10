#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  int pw = 1, it = 0;
  while (pw < n) {
    pw <<= 1;
    ++it;
  }

  int ans = -1;
  for (int i = 0; i < it; ++i) {
    vector<int> v[2];
    for (int j = 0; j < n; ++j) {
      v[(j >> i) & 1].push_back(j);
    }
    if (v[0].size() == 0 || v[1].size() == 0) continue;

    cout << v[0].size() << " " << v[1].size();
    for (int x : v[0])
      cout << " " << x + 1;
    for (int x : v[1])
      cout << " " << x + 1;
    cout << endl;

    int d;
    cin >> d;
    ans = max(ans, d);
  }
  cout << "-1 " << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}