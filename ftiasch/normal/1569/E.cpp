// #include "debug.h"

#include <bits/stdc++.h>

const int MOD = 998'244'353;

const int K = 5;
const int HALF = 1 << (K - 1);
const int M = 1 << (HALF - 1);

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int k, a, h, power[HALF + 2], rank[HALF], winner_hash[M], loser_hash[M],
    plan[1 << K];

int compute(int kk, int mask, int *rank) {
  if (kk == 0) {
    return 0;
  }
  int score = (1 << (k - kk)) + 1;
  int a = compute(kk - 1, mask, rank);
  int offset = (1 << (kk - 1));
  int b = offset + compute(kk - 1, mask >> (offset - 1), rank + offset);
  if (mask >> ((1 << kk) - 2) & 1) {
    rank[a] = score;
    return b;
  } else {
    rank[b] = score;
    return a;
  }
  // k=0 n=1
  // k=1 n=2 o
  // k=2 n=4 o|o|o
  // k=3 n=8 ooo|ooo|o
}

bool solve() {
  power[0] = 1;
  int half = 1 << (k - 1);
  for (int i = 1; i <= half + 1; ++i) {
    power[i] = 1LL * power[i - 1] * a % MOD;
  }
  int a2 = 1LL * a * a % MOD;
  std::map<int, int> winner_map, loser_map;
  for (int mask = 0; mask < 1 << (half - 1); ++mask) {
    memset(rank, -1, sizeof(rank));
    int winner = 1 + compute(k - 1, mask, rank);
    int h0 = 0, h1 = 0;
    for (int i = 0; i < half; ++i) {
      if (~rank[i]) {
        add(h0, (1LL + i) * power[rank[i]] % MOD);
        add(h1, (1LL + half + i) * power[rank[i]] % MOD);
      }
    }
    winner_map[(h0 + 1LL * winner * a) % MOD] = mask;
    loser_map[(h0 + 1LL * winner * a2) % MOD] = mask;
    winner_hash[mask] = (h1 + 1LL * (half + winner) * a) % MOD;
    loser_hash[mask] = (h1 + 1LL * (half + winner) * a2) % MOD;
  }
  for (int mask = 0; mask < 1 << (half - 1); ++mask) {
    {
      auto iterator = winner_map.find((h + MOD - loser_hash[mask]) % MOD);
      if (iterator != winner_map.end()) {
        int winner = compute(k - 1, iterator->second, plan);
        plan[winner] = 1;
        winner = compute(k - 1, mask, plan + half);
        plan[half + winner] = 2;
        return true;
      }
    }
    {
      auto iterator = loser_map.find((h + MOD - winner_hash[mask]) % MOD);
      if (iterator != loser_map.end()) {
        int winner = compute(k - 1, iterator->second, plan);
        plan[winner] = 2;
        winner = compute(k - 1, mask, plan + half);
        plan[half + winner] = 1;
        return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d%d", &k, &a, &h);
  if (solve()) {
    for (int i = 0; i < 1 << k; ++i) {
      printf("%d%c", plan[i], " \n"[i + 1 == (1 << k)]);
    }
  } else {
    puts("-1");
  }
}