#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int v[4005], d[4005];
long long p[4005];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> arr;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%lld", &v[i], &d[i], &p[i]);
    arr.push_back(i);
  }
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < v[arr[i]] && i + 1 + j < arr.size(); ++j) {
      p[arr[i + 1 + j]] -= v[arr[i]] - j;
    }
    for (int j = i + 1; j < arr.size(); ++j) {
      if (p[arr[j]] < 0) {
        for (int t = j + 1; t < arr.size(); ++t) {
          p[arr[t]] -= d[arr[j]];
        }
        arr.erase(arr.begin() + j);
        --j;
      }
    }
  }
  printf("%d\n", (int) arr.size());
  for (int i = 0; i < arr.size(); ++i) {
    if (i) printf(" ");
    printf("%d", arr[i] + 1);
  }
  printf("\n");
  return 0;
}