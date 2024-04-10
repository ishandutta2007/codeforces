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
  int n, a;
  cin >> n;
  set<int> ans;
  for (int i = 0; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      cin >> a;
      if (a == 3 || a == 1)
        ok = false;
    }
    if (ok)
      ans.insert(i);
  }
  cout << ans.size() << endl;
  for (int x : ans)
    cout << x + 1 << " ";
  cout << endl;
  return 0;
}