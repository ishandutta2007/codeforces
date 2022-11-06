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

bool solve(int n, vector<int> from, vector<int> to) {
  vector<int> credit(n + 1, 0);

  int last_seen = -1;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (credit[to[i]] > 0 && last_seen == to[i]) {
      credit[to[i]] -= 1;
      continue;
    }

    while (j < n && from[j] != to[i]) {
      credit[from[j]] += 1;
      ++j;
    }

    if (j < n && from[j] == to[i]) {
      last_seen = to[i];
      ++j;
      continue;
    }

    return false;
  }

  return true;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> from(n), to(n);;
    for (int i = 0; i < n; ++i)
      scanf("%d", &from[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &to[i]);
    if (solve(n, from, to)) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}