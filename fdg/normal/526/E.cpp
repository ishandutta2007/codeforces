#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[1000006];

pair<int, long long> tmp[1000006];
pair<int, long long> tmp2[1000006];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  while (q--) {
    long long b;
    scanf("%I64d", &b);
    int ans = 0;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
      if (cur + arr[i] > b) {
        ++ans;
        cur = 0;
      }
      cur += arr[i];
    }
    if (cur > 0) ++ans;

    int p = n - 1;
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
      cur += arr[i];
      while (cur > b) {
        cur -= arr[p];
        --p;
      }
      if (p == n - 1) {
        tmp[i] = {0, cur};
      } else {
        tmp[i] = {1 + tmp[p + 1].first, tmp[p + 1].second};
      }
      // cout << tmp[i].first << " " << tmp[i].second << endl;
    }

    p = 0;
    cur = 0;
    for (int i = 0; i < n; ++i) {
      cur += arr[i];
      while (cur > b) {
        cur -= arr[p];
        ++p;
      }
      if (p == 0) {
        tmp2[i] = {0, cur};
      } else {
        tmp2[i] = {1 + tmp2[p - 1].first, tmp2[p - 1].second};
      }
      // cout << tmp[i].first << " " << tmp[i].second << endl;
    }

    for (int i = 0; i < n; ++i) {
      int val = tmp[i].first;
      cur = tmp[i].second;
      if (i) val += tmp2[i - 1].first, cur += tmp2[i - 1].second;
      val += (cur + b - 1) / b;
      ans = min(ans, val);
    }

    printf("%d\n", ans);
  }
  return 0;
}