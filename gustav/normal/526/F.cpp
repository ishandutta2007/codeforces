#include <cstdio>
#include <cassert>
#include <cstring>
#include <stack>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 300005;
const int off = 1 << 19;

#define L(i) (2 * (i))
#define R(i) (L(i) + 1)

struct Node {
  int min;
  int pro;
  int cnt;
  void add(int x) {
    min += x;
    pro += x;
  }
};

Node t[off << 1];

void push(int i) {
  t[L(i)].add(t[i].pro);
  t[R(i)].add(t[i].pro);
  t[i].pro = 0;
}

void inc(int l, int r, int x, int lo = 0, int hi = off, int i = 1) {
  if (lo >= r || hi <= l) return;
  if (lo >= l && hi <= r) {
    t[i].add(x);
    return;
  }

  push(i);
  inc(l, r, x, lo, (lo + hi) / 2, L(i));
  inc(l, r, x, (lo + hi) / 2, hi, R(i));

  t[i].min = min(t[L(i)].min, t[R(i)].min);
  t[i].cnt = 0;
  if (t[L(i)].min == t[i].min) t[i].cnt += t[L(i)].cnt;
  if (t[R(i)].min == t[i].min) t[i].cnt += t[R(i)].cnt;
}

pair< int, int > cnt(int l, int r, int lo = 0, int hi = off, int i = 1) {
  if (lo >= r || hi <= l) return {MAXN, 0};
  if (lo >= l && hi <= r) return {t[i].min, t[i].cnt};

  push(i);
  auto ll = cnt(l, r, lo, (lo + hi) / 2, L(i));
  auto rr = cnt(l, r, (lo + hi) / 2, hi, R(i));
  
  pair< int, int > ret = {min(ll.first, rr.first), 0};
  if (ll.first == ret.first) ret.second += ll.second;
  if (rr.first == ret.first) ret.second += rr.second;

  return ret;
}

int a[MAXN];

int main(void) 
{
  int n;
  scanf("%d", &n);

  a[0] = 0;
  a[1] = MAXN;
  REP(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x + 1] = y;
  }

  for (int i = 2 * off - 1; i >= 0; --i) {
    if (i >= off) t[i].cnt = 1;
    else t[i].cnt = t[L(i)].cnt + t[R(i)].cnt;
  }

  stack< int > stk_min; stk_min.push(0); stk_min.push(1);
  stack< int > stk_max; stk_max.push(1);

  llint sol = 0;
  FOR(i, 2, n + 2) {
    while (a[i] < a[stk_min.top()]) {
      int t = stk_min.top(); stk_min.pop();
      inc(stk_min.top() + 1, i, min(a[t] - a[stk_min.top()], a[t] - a[i]));
    }
    stk_min.push(i);
    while (a[i] > a[stk_max.top()]) {
      int t = stk_max.top(); stk_max.pop();
      inc(stk_max.top() + 1, i, min(a[stk_max.top()] - a[t], a[i] - a[t]));
    }
    stk_max.push(i);
    inc(0, i, -1);
    sol += cnt(2, i + 1).second;
  }

  printf("%lld\n", sol);

  return 0;
}