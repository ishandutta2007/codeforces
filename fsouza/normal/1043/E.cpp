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

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  struct guy_t {
    int x, y;
    int orig_id;
    lint result = 0LL;
    int sort_key() const { return x - y; }
  };
  vector<guy_t> guys(n);
  for (int i = 0; i < n; ++i) {
    guy_t &guy = guys[i];
    scanf("%d %d", &guy.x, &guy.y);
    guy.orig_id = i;
  }
  sort(guys.begin(), guys.end(), [](const guy_t &lhs, const guy_t &rhs) {
      return lhs.sort_key() < rhs.sort_key();
    });
  vector<lint> acc_x(n + 1, 0LL), acc_y(n + 1, 0LL);
  for (int i = 0; i < n; ++i) {
    acc_x[i + 1] = acc_x[i] + guys[i].x;
    acc_y[i + 1] = acc_y[i] + guys[i].y;
  }
  for (int i = 0; i < n; ++i) {
    guy_t &guy = guys[i];
    guy.result += (lint)(n - i - 1) * guy.x;
    guy.result += acc_y[n] - acc_y[i + 1];
    guy.result += (lint)i * guy.y;
    guy.result += acc_x[i];
  }
  sort(guys.begin(), guys.end(), [](const guy_t &lhs, const guy_t &rhs) {
      return lhs.orig_id < rhs.orig_id;
    });
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    int score = min(guys[a].x + guys[b].y, guys[b].x + guys[a].y);
    guys[a].result -= score;
    guys[b].result -= score;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%lld", guys[i].result);
  }
  printf("\n");
  return 0;
}