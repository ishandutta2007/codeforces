#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int CNT[7002];

struct seg {
  seg(int  _l, int _r, int _val) : l(_l), r(_r), val(_val) {};
  int l, r, val;
};

vector<seg> q[7002];

int pw2[200002];

int up(int lev, int pos) {
  int l = 0, r = 200000;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (m + pw2[m] >= pos) r = m;
    else l = m;
  }
  return r;
}

int down_l(int lev, int pos) {
  return pos - 1 + pw2[pos - 1] + 1;
}

int down_r(int lev, int pos) {
  return pos + pw2[pos];
}

int find(int lev, int pos) {
  set<int> ret;
  int l = pos, r = pos;
  for (; lev <= 7000; ++lev) {
    for (int j = 0; j < q[lev].size(); ++j) {
      if (q[lev][j].r < l || q[lev][j].l > r);
      else {
        ret.insert(q[lev][j].val);
      }
    }
    l = down_l(lev, l); r = down_r(lev, r);
  }
  return ret.size();
}

int main() {
  for (int i = 0;(1<<i) <= 200000; ++i) {
    pw2[1<<i] = 1;
  }
  for (int i = 1; i <= 200000; ++i) {
    pw2[i] += pw2[i - 1];
  }
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt = 1, total = 1;
  CNT[1] = 1;
  for (int i = 2; i <= n; ++i) {
    int my = 0, pw = 1;
    while (pw <= cnt) {
      ++my;
      pw <<= 1;
    }
    cnt = 2 * my + cnt - my;
    total += cnt;
    CNT[i] = cnt;
  }
  // cout << cnt << endl;
  // cout << total << endl;
  // for (int pos = 1; pos <= 7; ++pos) {
  //   cout << up(4, pos) << endl;
  // }
  // return 0;
  for (int i = 0; i < m; ++i) {
    int t, lev, l, r, x, pos;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d%d", &lev, &l, &r, &x);
      q[lev].push_back(seg(l, r, x));
    } else {
      scanf("%d%d", &lev, &pos);
      printf("%d\n", find(lev, pos));
    }
  }
  return 0;
}