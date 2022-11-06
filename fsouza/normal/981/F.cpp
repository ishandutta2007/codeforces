#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

bool possible(const vector<int> &a, const vector<int> &b, int length,
              int max_dist) {
  const int n = a.size();
  static deque<int> cands; cands.clear();
  for (int i = 0; i < n; ++i) {
    cands.push_back(i);
    while (!cands.empty() && abs(a[i] - b[i - cands[0]]) > max_dist)
      cands.pop_front();
    while (!cands.empty() && abs(a[i] - b[i - cands.back()]) > max_dist)
      cands.pop_back();
  }
  cands.push_back(n);
  for (int i = 0; i < n; ++i) {
    while (!cands.empty() && cands.back() > i &&
           a[i] + length - b[n - (cands.back() - i)] > max_dist) {
      cands.pop_back();
    }
  }
  return !cands.empty();
}

int main() {
  int n, length;
  scanf("%d %d", &n, &length);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  sort(b.begin(), b.end());
  int left = 0, right = length;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (possible(a, b, length, mid) || possible(b, a, length, mid)) right = mid;
    else left = mid + 1;
  }
  int result = left;
  printf("%d\n", result);
  return 0;
}