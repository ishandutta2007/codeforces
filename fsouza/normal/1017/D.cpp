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

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int read_s() {
  string s = read_string();
  int result = 0;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] == '1')
      result |= 1<<i;
  return result;
}

int main() {
  int len, ns, nq;
  scanf("%d %d %d", &len, &ns, &nq);
  vector<int> w(len);
  for (int i = 0; i < len; ++i) {
    scanf("%d", &w[i]);
  }
  vector<int> count(1<<len);
  for (int i = 0; i < ns; ++i)
    count[read_s()] += 1;
  vector<int> mask_weight(1<<len);
  for (int s = 0; s < (1<<len); ++s)
    for (int i = 0; i < len; ++i)
      if (s & (1<<i))
        mask_weight[s] += w[i];
  const int max_k = 100;
  vector<vector<int>> mask_ans(1<<len, vector<int>(max_k + 1));
  for (int s = 0; s < (1<<len); ++s)
    for (int s2 = 0; s2 < (1<<len); ++s2) {
      int eq_mask = (s & s2) | (((1<<len) - 1) & (~s & ~s2));
      int mw = mask_weight[eq_mask];
      if (mw <= max_k)
        mask_ans[s][mw] += count[s2];
    }
  for (int q = 0; q < nq; ++q) {
    int s = read_s();
    int k;
    scanf("%d", &k);
    int result = 0;
    for (int i = 0; i <= k; ++i)
      result += mask_ans[s][i];
    printf("%d\n", result);
  }
  return 0;
}