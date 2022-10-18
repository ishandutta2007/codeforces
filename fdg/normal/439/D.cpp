#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[2][100002];
long long sum[2][100002];

int main() {
  int cnt[2];
  scanf("%d%d", &cnt[0], &cnt[1]);
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < cnt[t]; ++i)
      scanf("%d", &arr[t][i]);
    sort(arr[t], arr[t] + cnt[t]);
  }
  for (int i = 0; i <= cnt[0]; ++i) {
    sum[0][i] = arr[0][i];
    if (i)
      sum[0][i] += sum[0][i - 1];
  }
  for (int i = cnt[1] - 1; i >= 0; --i) {
    sum[1][i] = arr[1][i];
    sum[1][i] += sum[1][i + 1];
  }
  long long ans = -1;
  for (int i = 0; i < cnt[0]; ++i) {
    int val = arr[0][i];
    long long cur = 0;
    int pos = lower_bound(arr[0], arr[0] + cnt[0], val) - arr[0] - 1;
    if (pos >= 0)
    cur = (1LL * (min(pos + 1, cnt[0])) * val - sum[0][pos]);
    // cout << cur << endl;
    pos = upper_bound(arr[1], arr[1] + cnt[1], val) - arr[1];
    cur += sum[1][pos] - (1LL * (cnt[1] - pos) * val);
    if (ans == - 1 || ans > cur)
      ans = cur;
  }
  for (int i = 0; i < cnt[1]; ++i) {
    int val = arr[1][i];
    long long cur = 0;
    int pos = lower_bound(arr[0], arr[0] + cnt[0], val) - arr[0] - 1;
    if (pos >= 0)
    cur = (1LL * (min(pos + 1, cnt[0])) * val - sum[0][pos]);
    // cout << cur << endl;
    pos = upper_bound(arr[1], arr[1] + cnt[1], val) - arr[1];
    cur += sum[1][pos] - (1LL * (cnt[1] - pos) * val);
    if (ans == - 1 || ans > cur)
      ans = cur;
    // cout << val << "  " << cur << endl;
  }
  cout << ans << endl;
  return 0;
}