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

const int maxn = 100, nlet = 26;

struct edge_t {
  int other, value;
};
vector<edge_t> adj[maxn];
int win[maxn][maxn][nlet];

int get_win(int a, int b, int min_let) {
  int &res = win[a][b][min_let];
  if (res != -1) return res;
  for (const edge_t &ed : adj[a])
    if (ed.value >= min_let && !get_win(b, ed.other, ed.value))
      return res = 1;
  return res = 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    char let;
    scanf("%d %d %c", &a, &b, &let), --a, --b;
    int value = let - 'a';
    adj[a].push_back({b, value});
  }
  memset(win, -1, sizeof(win));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      putchar(get_win(i, j, 0) ? 'A' : 'B');
    putchar('\n');
  }
  return 0;
}