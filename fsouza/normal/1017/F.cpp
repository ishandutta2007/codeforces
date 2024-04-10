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

const int nm60 = 16;
const int m60s[] = {1,  7,  11, 13, 17, 19, 23, 29,
                    31, 37, 41, 43, 47, 49, 53, 59};
int id60[60];
const int maxn = 3e8 + 1;
const int nbit = (maxn + 59) / 60 * nm60;

uint64_t masks[(nbit + 63) / 64]{};

int main() {
  fill(id60, id60 + 60, -1);
  for (int i = 0; i < nm60; ++i)
    id60[m60s[i]] = i;

  int n;
  uint32_t a, b, c, d;
  scanf("%d %u %u %u %u", &n, &a, &b, &c, &d);

  uint32_t result = 0;
  auto process_prime = [&](uint32_t p) {
    uint32_t f_p = ((a * p + b) * p + c) * p + d;
    uint32_t mult_by = 0;
    for (int v = n / p; v > 0; v /= p)
      mult_by += v;
    result += mult_by * f_p;
  };

  process_prime(2);
  process_prime(3);
  process_prime(5);

  int pm60 = 7, pd60 = 0;
  for (int p = 7; p < maxn;) {
    int pid60 = id60[pm60];
    if (pid60 != -1) {
      int pid = pd60 * nm60 + pid60;
      if (!(masks[pid / 64] & (1ULL << (pid % 64)))) {
        process_prime(p);

        int km60 = pm60, kd60 = pd60;
        for (int k = 2 * p; k < maxn; k += p) {
          km60 += pm60;
          kd60 += pd60;
          if (km60 >= 60) km60 -= 60, ++kd60;

          int kid60 = id60[km60];
          if (kid60 != -1) {
            int kid = kd60 * nm60 + kid60;
            masks[kid / 64] |= 1ULL << (kid % 64);
          }
        }
      }
    }
    ++p;
    ++pm60;
    if (pm60 == 60) pm60 = 0, ++pd60;
  }

  printf("%u\n", result);

  return 0;
}