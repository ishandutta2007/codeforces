#include <cassert>
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
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int n;
int mp[256];
int a[N], fw[3][N];
set<int> st[3];
char s[N];

int lowBit(int k) { return k & -k; }

int qry(int* fw, int k) {
  int ret = 0;
  for (; k; k -= lowBit(k))
    ret += fw[k];
  return ret;
}

void ch(int* fw, int k, int x) {
  for (; k <= n; k += lowBit(k))
    fw[k] += x;
}

void ins(int k, int x) {
  st[x].insert(k);
  ch(fw[x], k, 1);
}

int qry(const pair<int, int>& rg, int k) {
  return qry(fw[k], rg.second) - qry(fw[k], rg.first - 1);
}

bool good(const pair<int, int>& rg) { return rg.first <= rg.second; }

int qans() {
  int ret = n;
  for (int i = 0; i < 3; ++i) {
    int scare = (i + 1) % 3, help = (i + 2) % 3;
    if (st[scare].empty())
      continue;
    int fst = *st[scare].begin(), lst = *st[scare].rbegin();
    pair<int, int> r1, r2;
    r1.first = fst;
    r2.second = lst;
    if (st[help].empty()) {
      ret -= st[i].size();
      continue;
    } else {
      r1.second = *st[help].begin();
      r2.first = *st[help].rbegin();
    }
    if (good(r1))
      ret -= qry(r1, i);
    if (good(r2))
      ret -= qry(r2, i);
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  mp['R'] = 0;
  mp['P'] = 1;
  mp['S'] = 2;

  int q;
  scanf("%d%d%s", &n, &q, s + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = mp[s[i]];
    ins(i, a[i]);
  }
  printf("%d\n", qans());
  while (q--) {
    int pos;
    char c;
    int v;
    scanf("%d %c", &pos, &c);
    v = mp[c];
    st[a[pos]].erase(pos);
    ch(fw[a[pos]], pos, -1);
    ins(pos, a[pos] = v);
    printf("%d\n", qans());
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}