#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int t[500005], v[500005];
vector<int> g[500005];

const int MAXP = 40;
const int N = MAXP;

struct SegmentTree {
  SegmentTree(int _n = 0) : n(_n) {
    init(_n);
  }

  void init(int _n) {
    n = _n;
    tree = vector<vector<double>>(n + 1, vector<double>(N, 1.0));

    // tree[n + 1] = vector<double>(N, 0);
    // tree[n + 1][0] = 1.0;
  }

  void update(int pos, double val, int where) {
    // for (int i = 1; i < v.size(); ++i)
    //   v[i] += v[i - 1];

    // for (int i = 0; i < tree[pos].size(); ++i) {
    //   tree[n][i] /= tree[pos][i];
    // }
    // for (int i = 0; i < v.size(); ++i) {
    //   tree[n][i] *= v[i];
    // }

    tree[n][where] = tree[n][where] / tree[pos][where] * val;

    // for (int i = 0; i < N; ++i) {
    //   tree[n + 1][i] = tree[n][i] - (i > 0 ? tree[n][i - 1] : 0);
    // }
    tree[pos][where] = val;
  }

  vector<double>& get() {
    return tree[n];
  }

  int n;
  vector<vector<double>> tree;
};

SegmentTree Q[500005];

int par[500005], POS[500005];

int main() {
  // Q[0].init(500000);
  int q;
  scanf("%d", &q);
  int cnt = 1;
  memset(par, -1, sizeof(par));
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &t[i], &v[i]); --v[i];
    if (t[i] == 1) {
      POS[cnt] = g[v[i]].size();
      g[v[i]].push_back(cnt);
      par[cnt] = v[i];
      ++cnt;
    }
  }

  for (int i = 0; i < cnt; ++i) {
    Q[i].init(g[i].size());
  }

  cnt = 1;
  for (int i = 0; i < q; ++i) {
    if (t[i] == 1) {
      vector<double> cur(N, 1.0);
      cur[0] = 0.5; cur[1] = 1.0;
      int x = cnt, it = 0, where = 0;
      while (par[x] != -1 && it < N) {
        ++it;
        // cout << x << "  " << par[x] << "  " << POS[x] << endl;
        Q[par[x]].update(POS[x], cur[where], where); ++where;
        x = par[x];
        // cur = Q[x].get();
        if (where < N)
          cur[where] = Q[x].get()[where - 1] * 0.5 + 0.5;
        // vector<double> tmp(1, 0.5);
        // for (int i = 0; i < cur.size() && i < N; ++i) {
        //   tmp.push_back(0.5 * cur[i] + 0.5);
        // }
        // cur = tmp;
      }
      ++cnt;
    } else {
      double ans = 0;
      vector<double> X = Q[v[i]].get();
      for (int j = 1; j < X.size(); ++j) {
        ans += j * (X[j] - X[j - 1]);
      }
      printf("%.10lf\n", ans);
    }
  }

  // {
  //   int N = 1000, C = 1;
  //   cout << N << endl;
  //   for (int i = 0; i < N; ++i) {
  //     int T = (rand() & 1) + 1;
  //     cout << T << " " << (rand() % C) + 1 << endl;
  //     if (T == 1) ++C;
  //   }
  // }

  return 0;
}