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
#include <ctime>
#include <chrono>

using namespace std;

typedef long long lint;

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int n, m;
  scanf("%d %d %*d", &n, &m);
  vector<string> adj(n);
  vector<lint> mask(n);
  for (int i = 0; i < n; ++i) {
    adj[i] = string(m, ' ');
    scanf(" %s", &adj[i][0]);
    for (int j = 0; j < m; ++j)
      if (adj[i][j] == '1')
        mask[i] |= 1LL<<j;
  }

  int result = 0;
  lint result_mask = 0LL;
  for (int rep = 0; rep < 100; ++rep) {
    int first = uniform_int_distribution<int>(0, n - 1)(rng);

    vector<int> bits;
    for (int j = 0; j < m; ++j)
      if (mask[first] & (1LL<<j))
        bits.push_back(j);
    int nadj = bits.size();

    vector<int> many(1<<nadj);

    for (int i = 0; i < n; ++i) {
      lint new_mask = 0;
      for (int j = 0; j < nadj; ++j) {
        int k = bits[j];
        if (mask[i] & (1LL<<k))
          new_mask |= 1LL<<j;
      }
      ++many[new_mask];
    }

    for (int b = 0; b < nadj; ++b)
      for (int s = 0; s < (1<<nadj); ++s)
        if (s & (1<<b))
          many[s ^ (1<<b)] += many[s];

    assert(many[0] == n);

    for (int s = 0; s < (1<<nadj); ++s)
      if (many[s] >= (n + 1) / 2) {
        int many_s = __builtin_popcount(s);
        if (many_s > result) {
          result = many_s;

          result_mask = 0LL;
          for (int b = 0; b < nadj; ++b)
            if (s & (1<<b))
              result_mask |= 1LL<<bits[b];
        }
      }
  }
  //  printf("%d\n", result);
  for (int j = 0; j < m; ++j) {
    if (result_mask & (1LL<<j)) printf("1");
    else printf("0");
  }
  printf("\n");
  return 0;
}
//