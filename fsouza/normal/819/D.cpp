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

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int egcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  } else {
    int x0, x1;
    int g = egcd(b % a, a, x0, x1);
    x = x1 - x0 * (b/a), y = x0;
    return g;
  }
}

int main() {
  int T, n;
  scanf("%d %d", &T, &n);
  vector<int> dist(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &dist[i]);
  lint shift = 0;
  for (int i = 0; i < n; ++i)
    shift += dist[i];
  shift %= T;
  const int nblock = gcd(shift, T), blocksize = T / nblock;
  struct guy_t {
    int block;
    int pos_in_block;
    int id;
  };
  vector<guy_t> guys;
  set<int> taken;
  lint pos = 0;
  int x, _unused;
  int g = egcd(shift, T, x, _unused);
  for (int i = 0; i < n; ++i) {
    if (taken.find(pos) == taken.end()) {
      taken.insert(pos);
      int block = pos % nblock;
      assert((pos - pos % nblock) % g == 0);
      int pos_in_block = (lint)x * ((pos - pos % nblock) / g) % blocksize;
      guys.push_back((guy_t){block, pos_in_block, i});
    }
    pos = (pos + dist[(i + 1) % n]) % T;
  }
  vector<int> result(n, 0);
  sort(guys.begin(), guys.end(), [](const guy_t &a, const guy_t &b) {
      if (a.block != b.block) return a.block < b.block;
      return a.pos_in_block < b.pos_in_block;
    });
  for (int j = 0, i = j; i < (int)guys.size(); i = j) {
    while (j < (int)guys.size() && guys[j].block == guys[i].block) ++j;
    for (int k = i; k < j; ++k) {
      int res;
      if (k + 1 < j) res = guys[k + 1].pos_in_block - guys[k].pos_in_block;
      else res = blocksize - (guys[k].pos_in_block - guys[i].pos_in_block);
      result[guys[k].id] = res;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");
  return 0;
}