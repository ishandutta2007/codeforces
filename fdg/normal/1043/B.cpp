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
  int n, arr[1001] = {0};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = n - 1; i > 0; --i)
    arr[i] -= arr[i - 1];

  vector<int> ans;
  for (int k = 1; k <= n; ++k) {
    bool ok = true;
    for (int i = k; i < n; ++i) {
      if (arr[i] != arr[i - k]) ok = false;
    }
    if (ok)
      ans.push_back(k);
  }
  cout << ans.size() << endl;
  for (int x : ans)
    cout << x << " ";
  cout << endl;
  return 0;
}