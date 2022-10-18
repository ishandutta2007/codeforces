#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int l[1001], r[1001], arr[1001];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> l[i];
  for (int i = 0; i < n; ++i)
    cin >> r[i];

  int cnt = 0, cur = n;
  while (cnt < n) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (arr[i] == 0 && l[i] == 0 && r[i] == 0) {
        v.push_back(i);
      }
    }

    if (v.size() == 0) {
      break;
    }

    cnt += v.size();
    for (int x : v) {
      arr[x] = cur;
      for (int i = 0; i < x; ++i)
        r[i]--;
      for (int i = x + 1; i < n; ++i)
        l[i]--;
    }
    --cur;
  }

  if (cnt == n) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}