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
  int n, k, arr[202];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int ans = arr[0];
  for (int l = 0; l < n; ++l) {
    vector<int> in;
    int sum = 0;
    for (int r = l; r < n; ++r) {
      sum += arr[r];
      in.push_back(arr[r]);
      vector<int> out;
      for (int i = 0; i < n; ++i) {
        if (i < l || i > r)
          out.push_back(arr[i]);
      }
      sort(in.begin(), in.end());
      sort(out.rbegin(), out.rend());
      int old = sum;
      ans = max(ans, sum);
      for (int i = 0; i < k && i < in.size() && i < out.size(); ++i) {
        sum += out[i] - in[i];
        ans = max(ans, sum);
      }
      sum = old;
    }
  }
  cout << ans << endl;
  return 0;
}