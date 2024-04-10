#include <cstdio>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int P = 998244353;
const int N = 101000, B = 340;

int n, b, c, kk;
int a[N], ans[N], lst[N], prv[N], tag[N];

void add(int& x, int y) {
  if ((x += y) >= P)
    x -= P;
}

//int lazy[B];
struct Block {
  int ptr, ans;
  int v[N];
  
  void set(int j) {
    if (tag[j] <= ptr)
      add(ans, ::ans[j]);
    add(v[tag[j]], ::ans[j]);
  }/*
  
  void ch(int j, int x) {
    if (tag[j] <= ptr)
      add(ans, P - ::ans[j]);
    add(v[tag[j]], P - ::ans[j]);
    tag[j] += x;
    set(j);
  }*/
  
  void mv(int x) {
    if (x == 1) {
      ++ptr;
      if (ptr >= 0)
        add(ans, v[ptr]);
    } else {
      if (ptr >= 0)
        add(ans, P - v[ptr]);
      --ptr;
    }
  }
} sum[B];

void ch(int l, int v) {
 // LOG("CH %d %d\n", l, v);
  int f = l / b;
  for (int i = f + 1; i < c; ++i)
    sum[i].mv(-v);
  int lz = kk - sum[f].ptr;
  sum[f].ptr = kk;
  sum[f].ans = 0;
  for (int j = f * b; j < (f + 1) * b; ++j)
    sum[f].v[tag[j]] = 0;
  for (int j = f * b; j < (f + 1) * b; ++j) {
    tag[j] += lz;
    if (j >= l)
      tag[j] += v;
    sum[f].set(j);
  }
}

int qry() {
  int ret = 0;
  for (int i = 0; i < c; ++i)
    add(ret, sum[i].ans);
  return ret;
}

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  int k;
  scanf("%d%d", &n, &k);
  kk = k;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  b = sqrt(n);
  c = n / b + 1;
  ans[0] = 1;
  for (int i = 0; i < c; ++i)
    sum[i].ptr = k;
  sum[0].set(0);
  for (int i = 1; i <= n; ++i) {
    int cur = lst[a[i]];
    lst[a[i]] = i;
    prv[i] = cur;
    if (cur) {
      ch(cur, 1);
      ch(prv[cur], -1);
    }
    ch(cur, 1);
    ch(i, -1);
    ans[i] = qry();
    sum[i / b].set(i);
  }
  printf("%d\n", ans[n]);

  return 0;
}