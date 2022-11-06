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

const int maxn = 1e5, maxlgn = __lg(maxn);

int n, lgn;
string s;

int next_let[maxn + 1][26], prev_let[maxn][26];
int res_left[maxn][26], res_right[maxn][26], res_blocks[maxn];

int solve(int a, int b);

int get_res_right(int i, int c) {
  int &res = res_right[i][c];
  if (res != -1) return res;
  int b = next_let[i][c] - 1;
  return res = solve(i, b);
}

int get_res_left(int i, int c) {
  int &res = res_left[i][c];
  if (res != -1) return res;
  int a = prev_let[i][c] + 1;
  return res = solve(a, i);
}

int get_res_blocks(int i) {
  int &res = res_blocks[i];
  if (res != -1) return res;
  int pi = next_let[i + 1][s[i] - 'a'];
  if (pi == n) return res = 0;
  else return res = (solve(i + 1, pi - 1) ^ get_res_blocks(pi));
}

int solve(int a, int b) {
  if (a > b) return 0;

  array<bool, 32> used{};
  for (int c = 0; c < 26; ++c) {
    int first = next_let[a][c];
    if (first > b) continue;
    int last = prev_let[b][c];

    int res = 0;
    if (first > a) res ^= get_res_right(a, c);
    if (last < b) res ^= get_res_left(b, c);
    res ^= get_res_blocks(first);
    res ^= get_res_blocks(last);
    used[res] = true;
  }

  for (int v = 0; v < 32; ++v)
    if (!used[v])
      return v;
  return 32;
}

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int main() {
  s = read_string();
  n = (int)s.size();
  lgn = __lg(n);

  for (int c = 0; c < 26; ++c)
    prev_let[0][c] = -1;
  prev_let[0][s[0] - 'a'] = 0;
  for (int i = 1; i < n; ++i) {
    for (int c = 0; c < 26; ++c)
      prev_let[i][c] = prev_let[i - 1][c];
    prev_let[i][s[i] - 'a'] = i;
  }

  for (int c = 0; c < 26; ++c)
    next_let[n][c] = n;
  for (int i = n - 1; i >= 0; --i) {
    for (int c = 0; c < 26; ++c)
      next_let[i][c] = next_let[i + 1][c];
    next_let[i][s[i] - 'a'] = i;
  }

  memset(res_left, -1, sizeof(res_left));
  memset(res_right, -1, sizeof(res_right));
  memset(res_blocks, -1, sizeof(res_blocks));

  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    if (solve(a, b)) printf("Alice\n");
    else printf("Bob\n");
  }

  return 0;
}