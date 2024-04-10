#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int inf = 1.5e+9;
const int K = 5000;
int arr[K * 105];
int d[K * 105], d1[K * 105], d2[K * 105];

int where[302] = {0};

int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  int left = max(0, T - K);
  T = min(T, K);
  for (int i = n; i < T * n; ++i)
    arr[i] = arr[i - n];

  d[0] = -inf;
  for (int i = 1; i <= n * T; ++i)
    d[i] = inf;
   
  for (int i = 0; i < n * T; i++) {
    int j = int (upper_bound (d, d + n * T, arr[i]) - d);
    if (d[j-1] <= arr[i] && arr[i] < d[j])
      d[j] = arr[i];
    d1[i] = j;
    // cout << d1[i] << "  ";
  }
  // cout << endl;

  d[0] = -inf;
  for (int i = 1; i <= n * T; ++i)
    d[i] = inf;
   
  for (int i = 0; i < n * T; i++) {
    int j = int (upper_bound (d, d + n * T, -arr[n * T - 1 - i]) - d);
    if (d[j-1] <= -arr[n * T - 1 - i] && -arr[n * T - 1 - i] < d[j])
      d[j] = -arr[n * T - 1 - i];
    d2[n * T - 1 - i] = j;
    // cout << d1[i] << "  ";
  }
  // cout << endl;

  // for (int i = 0; i < n * T; ++i)
  //   cout << d[i] << " ";
  // cout << endl;

  int cnt[302] = {0};
  for (int i = n - 1; i >= 0; --i) {
    where[arr[i]] = i;
    cnt[arr[i]]++;
  }

  int ans = 0;
  for (int i = 0; i < n * T; ++i) {
    ans = max(ans, d1[i] + left * cnt[arr[i]]);
    int pos = (i / n + 1) * n + where[arr[i]];
    int cur = d1[i] + left * cnt[arr[i]];
    if (pos <  n * T) {
       cur += d2[pos];
    }
    // cout << i << "  " << pos << " " << cur << endl;
    ans = max(ans, cur);
  }
  cout << ans << endl;

  return 0;
}