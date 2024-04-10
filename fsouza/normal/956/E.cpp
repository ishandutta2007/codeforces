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

const lint mod = 1000000186000008673LL;

int main() {
  int n, l, r;
  scanf("%d %d %d", &n, &l, &r);
  struct box_t {
    int size;
    bool important;
  };
  vector<box_t> boxes(n);
  {
    vector<int> sizes(n), importances(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &sizes[i]);
    for (int i = 0; i < n; ++i)
      scanf("%d", &importances[i]);
    for (int i = 0; i < n; ++i)
      boxes[i] = {sizes[i], importances[i] == 1};
  }
  sort(boxes.begin(), boxes.end(),
       [](const box_t &a, const box_t &b) {
         if (a.important != b.important)
           return a.important;
         return a.size < b.size;
       });
  vector<int> acc_sum(n + 1, 0);
  for (int i = 0; i < n; ++i)
    acc_sum[i + 1] = acc_sum[i] + boxes[i].size;
  const int total_size = acc_sum[n];

  vector<lint> nway(total_size + 1, 0);
  nway[0] = 1;
  vector<lint> nway2(total_size + 1, 0);
  nway2[0] = 1;

  int result = 0;
  for (int pref = n; pref >= 1; --pref) {
    if (boxes[pref - 1].important) {
      int imp_total = acc_sum[pref], last = boxes[pref - 1].size;

      for (int start = l; start <= total_size; ++start)
        if (nway[start]) {
          if (start + (imp_total - last) <= r) {
            result = max(result, pref);
          }
          if (start + imp_total <= r && nway[start] != nway2[start]) {
            result = max(result, pref + 1);
          }
        }
    }

    int value = boxes[pref - 1].size;
    for (int s = total_size - value; s >= 0; --s) {
      nway[s + value] += nway[s];
      if (nway[s + value] >= mod)
        nway[s + value] -= mod;
    }

    if (!boxes[pref - 1].important) {
      for (int s = total_size - value; s >= 0; --s) {
        nway2[s + value] += nway2[s];
        if (nway2[s + value] >= mod)
          nway2[s + value] -= mod;
      }
    } else {
      for (int s = total_size; s >= value; --s)
        nway2[s] = nway2[s - value];
      for (int s = 0; s < value; ++s)
        nway2[s] = 0;
    }
  }

  for (int start = l; start <= r; ++start)
    if (start <= total_size && nway[start] != nway2[start])
      result = max(result, 1);

  printf("%d\n", result);

  return 0;
}