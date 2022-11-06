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

int get_block(lint v) {
  lint p2 = 1, lg2 = 0;
  while (2 * p2 <= v) {
    p2 *= 2;
    ++lg2;
  }
  if (v == p2) return 2 * lg2;
  else return 2 * lg2 + 1;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> many;
  for (int i = 0; i < n; ++i) {
    lint value;
    scanf("%lld", &value);
    int block = get_block(value);
    if (block >= (int)many.size())
      many.resize(block + 1);
    ++many[block];
  }
  vector<int> result;
  for (int init_cap = (many[0] + 1) / 2; init_cap <= many[0]; ++init_cap) {
    int cap = init_cap, buffer = cap;
    bool ok = true;
    for (int i = 0; i < (int)many.size(); ++i) {
      int amount = many[i];
      if (i % 2 == 0) {
        if (amount <= cap) {
          cap = amount;
          buffer = min(buffer, cap);
        } else {
          int extra = amount - cap;
          if (buffer >= extra) {
            buffer -= extra;
          } else {
            ok = false;
            break;
          }
        }
      } else {
        if (buffer >= amount) {
          buffer -= amount;
        } else {
          ok = false;
          break;
        }
      }
    }
    if (ok) result.push_back(init_cap);
  }

  if (result.empty()) printf("-1\n");
  else {
    for (int i = 0; i < (int)result.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i]);
    }
    printf("\n");
  }

  return 0;
}