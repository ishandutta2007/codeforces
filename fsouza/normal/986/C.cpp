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

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  vector<bool> contains(1<<k, false), marked(1<<k, false);
  for (int i = 0; i < n; ++i) {
    int value;
    scanf("%d", &value);
    contains[value] = true;
  }
  const int full_mask = (1<<k) - 1;
  int result = 0;
  for (int mask = 0; mask < (1<<k); ++mask) {
    if (contains[mask] && !marked[mask]) {
      ++result;

      queue<int> q;
      marked[full_mask ^ mask] = true;
      q.push(full_mask ^ mask);
      while (!q.empty()) {
        int v = q.front(); q.pop();
        if (contains[v] && !marked[full_mask ^ v]) {
          marked[full_mask ^ v] = true;
          q.push(full_mask ^ v);
        }
        for (int i = 0; i < k; ++i)
          if ((v & (1<<i)) && !marked[v ^ (1<<i)]) {
            marked[v ^ (1<<i)] = true;
            q.push(v ^ (1<<i));
          }
      }
    }
  }
  printf("%d\n", result);
  return 0;
}