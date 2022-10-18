#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[500005];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  {
    long long p = n - 1, val = arr[n - 1], have = 0;
    while (have < k) {
      if (val == 0) {
        cout << (have % n == 0 ? 0 : 1) << endl;
        return 0;
      }

      while (p > 0 && arr[p - 1] == val) --p;
      long long can = val - (p > 0 ? arr[p - 1] : 0);
      if (1LL * can * (n - p) + have < k) {
        have += can * (n - p);
        val -= can;
        continue;
      }

      long long full = (k - have) / (n - p);
      have += full * (n - p); val -= full;
      // cout << full << " " << p << endl;
      for (int i = p; i < n; ++i) {
        arr[i] = val;
      }
      for (int i = 0; have < k; ++i) {
        arr[n - 1 - i]--;
        ++have; 
      }
    }
    sort(arr, arr + n);
    // for (int i = 0; i < n; ++i) {
    //   cout << arr[i] << " ";
    // }
    // cout << endl;
  }

  long long p = 0, val = arr[0], have = k;
  while (have > 0) {
    while (p + 1 < n && arr[p + 1] == val) ++p;
    long long can = (p + 1 < n ? arr[p + 1] : 1.1e+9) - val;
    if (1LL * can * (p + 1) < have) {
      have -= can * (p + 1);
      val += can;
      continue;
    }

    long long full = (have) / (p + 1);
    have -= full * (p + 1); val += full;
    for (int i = 0; i <= p; ++i) {
      arr[i] = val;
    }
    for (int i = 0; have > 0; ++i) {
      arr[i]++;
      --have; 
    }
  }
  sort(arr, arr + n);
  cout << arr[n - 1] - arr[0] << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << arr[i] << " ";
  // }
  // cout << endl;
  return 0;
}