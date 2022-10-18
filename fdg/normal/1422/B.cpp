#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[101][101];

long long solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];

  long long ans = 0;
  for (int i = 0; i < (n + 1) / 2; ++i) {
    for (int j = 0; j < (m + 1) / 2; ++j) {
      vector<int> v(1, arr[i][j]);
      if (n - 1 - i != i) v.push_back(arr[n - 1 - i][j]);
      if (m - 1 - j != j) {
        v.push_back(arr[i][m - 1 - j]);
        if (n - 1 - i != i) v.push_back(arr[n - 1 - i][m - 1 - j]);
      }
      sort(v.begin(), v.end());
      int ind = (v.size() / 2);
      for (int x : v) {
        ans += abs(x - v[ind]);
      }
      // cout << "Ind: " << v[ind] << endl;
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    cout << solve() << endl;

  return 0;
}