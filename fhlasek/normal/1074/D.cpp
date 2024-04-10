/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

#define MAXN 555555
map<int, int> m;
int M = 0;
int parent[MAXN], diff_from_parent[MAXN];
vector<int> children[MAXN];

int get_vertex(int x) {
  if (m.find(x) == m.end()) {
    m[x] = M;
    parent[M] = M;
    children[M].push_back(M);
    diff_from_parent[M] = 0;
    M++;
  }
  return m[x];
}

void update(int l, int r, int x) {
  l = get_vertex(l - 1);
  r = get_vertex(r);
  int pl = parent[l], pr = parent[r];
  if (pl == pr) return;
  int diff = x ^ diff_from_parent[l] ^ diff_from_parent[r];
  if (children[pl].size() < children[pr].size()) { swap(pl, pr); swap(l, r); }
  REP(i, children[pr].size()) {
    int ch = children[pr][i];
    parent[ch] = pl;
    children[pl].push_back(ch);
    diff_from_parent[ch] ^= diff;
  }
  children[pr].clear();
}

int query(int l, int r) {
  l = get_vertex(l - 1);
  r = get_vertex(r);
  if (parent[l] != parent[r]) return -1;
  return diff_from_parent[l] ^ diff_from_parent[r];
}

int main(int argc, char *argv[]) {
  int Q;
  scanf("%d", &Q);
  int last = 0;
  while (Q--) {
    int t;
    scanf("%d", &t);
    if (last == -1) last = 1;
    int l, r;
    scanf("%d%d", &l, &r);
    l ^= last;
    r ^= last;
    if (l > r) swap(l, r);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      x ^= last;
      update(l, r, x);
    } else {
      printf("%d\n", last = query(l, r));
    }
  }
  return 0;
}