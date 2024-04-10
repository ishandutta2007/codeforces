#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define MAXN 100000

using namespace std;

typedef long long lint;


lint total[MAXN], mine[MAXN], yours[MAXN];
int follow[MAXN], nfollower[MAXN];
lint partial[MAXN];
multiset<lint> partials[MAXN];
multiset<lint> cands;
int candst[MAXN];

void erase_one(multiset<lint> &m, lint v) {
  m.erase(m.find(v));
}

void remove_cands(int i) {
  if (candst[i] == 0) return;
  candst[i] = 0;
  multiset<lint> &guys = partials[i];
  if (guys.empty()) {
  } else if (guys.size() == 1) {
    erase_one(cands, yours[i] + *guys.begin());
  } else {
    erase_one(cands, yours[i] + *guys.begin());
    erase_one(cands, yours[i] + *guys.rbegin());
  }
}

void add_cands(int i) {
  if (candst[i] == 1) return;
  candst[i] = 1;
  multiset<lint> &guys = partials[i];
  if (guys.empty()) {
  } else if (guys.size() == 1) {
    cands.insert(yours[i] + *guys.begin());
  } else {
    cands.insert(yours[i] + *guys.begin());
    cands.insert(yours[i] + *guys.rbegin());
  }
}

set<tuple<int, int, int>> working;

void unlink(int a, int b) {
  if (working.find(make_tuple(0, a, b)) == working.end()) {
    erase_one(partials[b], partial[a]);
    working.insert(make_tuple(0, a, b));
  }
}

void unlink2(int a, int b) {
  if (working.find(make_tuple(1, a, b)) == working.end()) {
    partial[b] -= yours[a];
    working.insert(make_tuple(1, a, b));
  }
}

void recalc(int i) {
  int npeople = 1 + 1 + nfollower[i];
  yours[i] = total[i] / npeople;
  mine[i] = total[i] - (lint)(npeople-1)*yours[i];
}

void link(int a, int b) {
  if (working.find(make_tuple(0, a, b)) == working.end()) {
    partials[b].insert(partial[a]);
    working.insert(make_tuple(0, a, b));
  }
}

void link2(int a, int b) {
  if (working.find(make_tuple(1, a, b)) == working.end()) {
    partial[b] += yours[a];
    working.insert(make_tuple(1, a, b));
  }
}

void change(int a, int c) {
  const int b = follow[a];
  if (b == c) return;

  int bb = follow[b], bbb = follow[bb];
  int cc = follow[c], ccc = follow[cc];

  remove_cands(a);
  remove_cands(b);
  remove_cands(bb);
  remove_cands(bbb);
  remove_cands(c);
  remove_cands(cc);
  remove_cands(ccc);

  {
    working.clear();
    unlink(a, b);
    unlink(b, bb);
    unlink(bb, bbb);
    unlink(c, cc);
    unlink(cc, ccc);

    unlink2(a, b);
    unlink2(b, bb);
    unlink2(bb, bbb);
    unlink2(c, cc);
    unlink2(cc, ccc);

    follow[a] = c;
    --nfollower[b];
    ++nfollower[c];

    partial[b] -= mine[b];
    partial[c] -= mine[c];

    recalc(b);
    recalc(c);

    partial[b] += mine[b];
    partial[c] += mine[c];

    working.clear();
    link2(cc, ccc);
    link2(c, cc);
    link2(bb, bbb);
    link2(b, bb);
    link2(a, c);

    link(cc, ccc);
    link(c, cc);
    link(bb, bbb);
    link(b, bb);
    link(a, c);
  }

  add_cands(a);
  add_cands(b);
  add_cands(bb);
  add_cands(bbb);
  add_cands(c);
  add_cands(cc);
  add_cands(ccc);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, nq;
  cin >> n >> nq;
  for (int i = 0; i < n; ++i) cin >> total[i];

  for (int i = 0; i < n; ++i) nfollower[i] = 0;
  for (int i = 0; i < n; ++i) {
    int f;
    cin >> f; --f;
    follow[i] = f;
    ++nfollower[f];
  }

  for (int i = 0; i < n; ++i) partial[i] = 0;

  for (int i = 0; i < n; ++i) {
    int npeople = 1 + 1 + nfollower[i];
    yours[i] = total[i] / npeople;
    mine[i] = total[i] - (lint)(npeople-1)*yours[i];
    partial[follow[i]] += yours[i];
  }

  for (int i = 0; i < n; ++i) {
    partial[i] += mine[i];
    partials[follow[i]].insert(partial[i]);
  }

  for (int i = 0; i < n; ++i) {
    multiset<lint> &guys = partials[i];
    if (guys.empty()) {
    } else if (guys.size() == 1) {
      cands.insert(yours[i] + *guys.begin());
    } else {
      cands.insert(yours[i] + *guys.begin());
      cands.insert(yours[i] + *guys.rbegin());
    }
    candst[i] = 1;
  }

  for (int q = 0; q < nq; ++q) {
    int kind;
    cin >> kind;
    if (kind == 1) {
      int a, b;
      cin >> a >> b; --a, --b;
      change(a, b);
    } else if (kind == 2) {
      int a;
      cin >> a; --a;
      lint result = partial[a] + yours[follow[a]];
      cout << result << "\n";
    } else {
      lint minv = *cands.begin();
      lint maxv = *cands.rbegin();
      cout << minv << " " << maxv << "\n";
    }
  }

  return 0;
}