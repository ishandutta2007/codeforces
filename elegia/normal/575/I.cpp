#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int N = 5010, Q = 100010;

int n, q, ac;

int a[N][N * 2];
int ans[Q];

vector<pair<pair<int, int>, pair<int, int>>> seq;

void ch(int j, int k, int x) {
  for (; j <= n; j += j & -j)
    for (int l = k; l <= n * 2; l += l & -l)
      a[j][l] += x;
}

int qry(int j, int k) {
  int ret = 0;
  for (; j; j &= j - 1)
    for (int l = k; l; l &= l - 1)
      ret += a[j][l];
  return ret;
}

void add1(int j, int k, int x) {
  seq.emplace_back(make_pair(j, k), make_pair(1, x));
}

void add2(int j, int k, int x) {
  seq.emplace_back(make_pair(j, k + j), make_pair(2, x));
}

void add3(int j, int k, int x) {
  seq.emplace_back(make_pair(j, k - j + n), make_pair(3, x));
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &q);
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int d, x, y, l;
      scanf("%d%d%d%d", &d, &x, &y, &l);
      if (d == 1) {
        add1(x, y, 1);
        add2(x, y + l + 1, -1);
        add2(x + l + 1, y, 1);
        add1(x + l + 1, y, -1);
      } else if (d == 2) {
        add3(x, y - l, 1);
        add1(x, y + 1, -1);
        add1(x + l + 1, y + 1, 1);
        add3(x + l + 1, y + 1, -1);
      } else if (d == 3) {
        add1(x - l, y, 1);
        add3(x - l, y + 1, -1);
        add1(x + 1, y, -1);
        add3(x + 1, y + l + 2, 1);
      } else {
        add2(x - l, y, 1);
        add1(x - l, y + 1, -1);
        add2(x + 1, y - l - 1, -1);
        add1(x + 1, y + 1, 1);
      }
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      ++ac;
      seq.emplace_back(make_pair(x, y), make_pair(-1, ac));
      seq.emplace_back(make_pair(x, y + x), make_pair(-2, ac));
      seq.emplace_back(make_pair(x, y - x + n), make_pair(-3, ac));
    }
  }
  for (int id = 1; id <= 3; ++id) {
    memset(a, 0, sizeof(a));
    for (const auto& pr : seq)
      if (pr.second.first == id)
        ch(pr.first.first, pr.first.second, pr.second.second);
      else if (pr.second.first == -id)
        ans[pr.second.second] += qry(pr.first.first, pr.first.second);
  }
  for (int i = 1; i <= ac; ++i)
    printf("%d\n", ans[i]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}