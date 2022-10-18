#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long mod = (long long) (4 * 1e+18) + 777;

long long arr[200002];
int init[200002];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) {
    scanf("%d", &init[i]);
    arr[i] = init[i];
  }
  int pw = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] % 2 == 0) {
      arr[i + 1] += arr[i] / 2;
      arr[i] = 0;
      ++pw;
    } else {
      break;
    }
  }

  // cout << pw << endl;

  long long val = 0;
  for (int i = n; i >= pw; --i) {
    val *= 2;
    val += arr[i];
    if (abs(val) > mod) {
      puts("0");
      return 0;
    }
  }
  
  int ans = 0;
  for (int i = pw; i >= 0; --i) {
    if (abs(val) > 1e+12) break;

    long long cur = init[i] - val;
    // cout << cur << endl;
    if (abs(cur) <= k && (i != n || cur != 0)) ++ans;
    val *= 2;
  }
  printf("%d\n", ans);

  return 0;
}