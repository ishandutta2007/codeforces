// #include "debug.h"

#include <bits/stdc++.h>

using u64 = uint64_t;

int main() {
  std::mt19937_64 gen{0};
  int n;
  scanf("%d", &n);
  std::vector<int> primes;
  std::vector<bool> removed(n + 1);
  std::vector<u64> hashes(n + 1);
  for (int d = 2; d <= n; ++d) {
    if (!removed[d]) {
      primes.push_back(d);
      hashes[d] = gen();
    }
    for (int p : primes) {
      if (d * p > n) {
        break;
      }
      removed[d * p] = true;
      hashes[d * p] = hashes[d] ^ hashes[p];
      if (d % p == 0) {
        break;
      }
    }
  }
  std::map<u64, int> lookup;
  u64 target = 0;
  for (int d = 2; d <= n; ++d) {
    hashes[d] ^= hashes[d - 1];
    target ^= hashes[d];
    lookup[hashes[d]] = d;
  }
  //   std::cout << KV(primes) << KV(hashes) << std::endl;
  bool ok = target == 0;
  std::fill(removed.begin(), removed.end(), false);
  if (!ok) {
    for (int i = 1; i <= n && !ok; ++i) {
      if (hashes[i] == target) {
        ok = removed[i] = true;
      }
    }
  }
  if (!ok) {
    for (int i = 1; i <= n && !ok; ++i) {
      auto iterator = lookup.find(target ^ hashes[i]);
      if (iterator != lookup.end()) {
        ok = removed[i] = removed[iterator->second] = true;
      }
    }
  }
  if (!ok) {
    assert(n % 2 == 1);
    removed[2] = removed[(n - 1) >> 1] = removed[n] = true;
  }
  int m = n - std::count(removed.begin(), removed.end(), true);
  printf("%d\n", m);
  for (int i = 1; i <= n; ++i) {
    if (!removed[i]) {
      printf("%d ", i);
    }
  }
  puts("");
}