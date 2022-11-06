#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <ctime>
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

vector<lint> cand_mods = {
  1000000000108174411LL,
  1000000000108174427LL,
  1000000000108174433LL,
  1000010000005470301LL,
  1000010000005470329LL,
  1000010000005470341LL,
};
lint mod;

int main() {
  srand(time(NULL));
  mod = cand_mods[rand() % (int)cand_mods.size()];

  int n, nq;
  scanf("%d %d", &n, &nq);
  vector<vector<int>> adds(n), dels(n);
  for (int q = 0; q < nq; ++q) {
    int l, r, delta;
    scanf("%d %d %d", &l, &r, &delta), --l, --r;
    adds[l].push_back(delta);
    dels[r].push_back(delta);
  }

  vector<bool> possible(n + 1, false);
  vector<lint> nway(n + 1, 0);
  nway[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int d : adds[i]) {
      for (int j = n; j >= d; --j) {
        nway[j] += nway[j - d];
        if (nway[j] >= mod) nway[j] -= mod;
      }
    }
    for (int j = 0; j <= n; ++j)
      if (nway[j] != 0)
        possible[j] = true;
    for (int d : dels[i]) {
      for (int j = d; j <= n; ++j) {
        nway[j] -= nway[j - d];
        if (nway[j] < 0) nway[j] += mod;
      }
    }
  }
  vector<int> result;
  for (int j = 1; j <= n; ++j)
    if (possible[j])
      result.push_back(j);
  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}