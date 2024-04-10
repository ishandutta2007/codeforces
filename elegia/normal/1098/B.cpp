#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<vector<int>> G;

const int N = 300010;

int n, m;
char s[N];
const char* imp = "ATCG";
G input;

int mp[256];

pair<int, G> solve(int n, int m, const G& in) {
  static int p[4], c[4][2];
  iota(p, p + 4, 0);
  pair<int, G> ret(n * m, G());
  do {
    if (p[0] > p[1] || p[3] > p[2])
      continue;
    int cost = n * m;
    G cur(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      memset(c, 0, sizeof(c));
      for (int j = 0; j < m; ++j)
        ++c[in[i][j]][j & 1];
      int a = p[(i & 1) << 1], b = p[(i & 1) << 1 | 1];
      if (c[a][0] + c[b][1] > c[a][1] + c[b][0]) {
        cost -= c[a][0] + c[b][1];
        for (int j = 0; j < m; ++j)
          cur[i][j] = p[(i & 1) << 1 | (j & 1)];
      } else {
        cost -= c[a][1] + c[b][0];
        for (int j = 0; j < m; ++j)
          cur[i][j] = p[(i & 1) << 1 | (~j & 1)];
      }
    }
    ret = min(ret, make_pair(cost, cur));
  } while (next_permutation(p, p + 4));
  return ret;
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  mp['A'] = 0;
  mp['T'] = 1;
  mp['C'] = 2;
  mp['G'] = 3;

  scanf("%d%d", &n, &m);
  for (int rep = 0; rep < n; ++rep) {
    vector<int> row;
    scanf("%s", s);
    transform(s, s + m, back_inserter(row), [=](char c){ return mp[c]; });
    input.push_back(row);
  }
  pair<int, G> a = solve(n, m, input);
  G inv(m, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      inv[j][i] = input[i][j];
  pair<int, G> b = solve(m, n, inv);
  inv = G(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      inv[i][j] = b.second[j][i];
  b.second = inv;
  a = min(a, b);

  LOG("%d\n", a.first);
  for (const auto& r : a.second) {
    for (int v : r)
      putchar(imp[v]);
    putchar('\n');
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}