#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const long long MOD = 999999999999989;
const int N = 100;
const int HALF = 15;

int n, magic, a[N];

int solve() {
  std::map<long long, int> low_map;
  for (int low = 0; low < 1 << HALF; ++low) {
    long long h = 0;
    for (int i = n; i--;) {
      int c = __builtin_popcount((a[i] ^ low) & ((1 << HALF) - 1));
      h = (h * magic + c) % MOD;
    }
    low_map[h] = low;
  }
  long long oh = 0;
  for (int i = n; i--;) {
    oh = (oh * magic + 1) % MOD;
  }
  for (int high = 0; high < 1 << HALF; ++high) {
    long long h = 0;
    for (int i = n; i--;) {
      int c = __builtin_popcount((a[i] >> HALF) ^ high);
      h = (h * magic + c) % MOD;
    }
    for (int o = 0; o <= (HALF + HALF); ++o) {
      long long t = (oh * o + MOD - h) % MOD;
      auto iterator = low_map.find(t);
      if (iterator != low_map.end()) {
        int low = iterator->second;
        return high << HALF | low;
      }
    }
  }
  return -1;
}

int main() {
  std::mt19937 gen{std::random_device{}()};
  magic = std::uniform_int_distribution<int>(1000, 9999)(gen);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int result = solve();
  printf("%d\n", result);
}