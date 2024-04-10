#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];
vector<int> wh[100005];
vector<int> v;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &arr[i]);
    if (i) ans += abs(arr[i] - arr[i - 1]);
    wh[arr[i]].push_back(i);
  }
  long long init = ans;
  for (int i = 1; i <= n; ++i) {
    if (wh[i].size()) {
      v.clear();
      long long cur = init;
      for (int j = 0; j < wh[i].size(); ++j) {
        if ((j == 0 || wh[i][j] > wh[i][j - 1] + 1) && wh[i][j] > 0) {
          v.push_back(arr[wh[i][j] - 1]);
          cur -= abs(arr[wh[i][j]] - arr[wh[i][j] - 1]);
        }
        if (wh[i][j] + 1 < m && arr[wh[i][j] + 1] != i) {
          v.push_back(arr[wh[i][j] + 1]);
          cur -= abs(arr[wh[i][j]] - arr[wh[i][j] + 1]);
        }
      }
      sort(v.begin(), v.end());
      // for (int j = 0; j < v.size(); ++j)
      //   cout << v[j] << " ";
      // cout << endl;
      if (v.size() == 0) continue;
      int med = v[v.size() / 2];
      for (int j = 0; j < wh[i].size(); ++j) {
        if ((j == 0 || wh[i][j] > wh[i][j - 1] + 1) && wh[i][j] > 0) {
          int nx = arr[wh[i][j] - 1];
          if (nx == i) nx = med;
          cur += abs(med - nx);
        }
        if (wh[i][j] + 1 < m && arr[wh[i][j] + 1] != i) {
          int nx = arr[wh[i][j] + 1];
          if (nx == i) nx = med;
          cur += abs(med - nx);
        }
      }
      // cout << i << "  " << med << "  " << cur << endl;
      ans = min(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}