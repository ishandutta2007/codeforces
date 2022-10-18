#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

typedef vector< llint > vv;

char who[] = "LMW";

struct Group {
  llint d01, d12, a0, mask;
};

bool operator<(const Group &a, const Group &b) {
  if (a.d01 != b.d01) return a.d01 < b.d01;
  if (a.d12 != b.d12) return a.d12 < b.d12;
  return a.a0 < b.a0;
}

const int MAXN = 30;

llint L[MAXN], M[MAXN], W[MAXN];
llint p3[MAXN];

void gen(int lo, int hi, llint mask, llint l, llint m, llint w, vector< Group > &store) {
  if (lo == hi) {
    store.push_back({l - m, m - w, l, mask});
    return;
  }
  gen(lo + 1, hi, mask + p3[lo] * 0, l, m + M[lo], w + W[lo], store);
  gen(lo + 1, hi, mask + p3[lo] * 1, l + L[lo], m, w + W[lo], store);
  gen(lo + 1, hi, mask + p3[lo] * 2, l + L[lo], m + M[lo], w, store);
}


int main(void) 
{
  p3[0] = 1;
  FOR(i, 1, MAXN) p3[i] = p3[i - 1] * 3;

  int N; 
  scanf("%d", &N);
  REP(i, N) scanf("%lld%lld%lld", L+i, M+i, W+i);

  if (N == 1) {
    if (L[0] == M[0]) 
      puts("LM");
    else if (L[0] == W[0])
      puts("LW");
    else if (M[0] == W[0])
      puts("MW");
    else
      puts("Impossible");
    exit(0);
  }

  int H = (N + 1) / 2;

  vector< Group > lo; gen(0, H, 0, 0, 0, 0, lo);
  vector< Group > hi; gen(H, N, 0, 0, 0, 0, hi);
  sort(lo.begin(), lo.end());

  llint best = -inf;
  llint mask = 0;

  for (auto it : hi) {
    Group neg = {-it.d01, -it.d12, inf, inf};
    auto jt = upper_bound(lo.begin(), lo.end(), neg);
    if (jt == lo.begin()) continue;
    --jt;

    if (it.d01 + jt->d01 != 0) continue;
    if (it.d12 + jt->d12 != 0) continue;
    if (it.a0 + jt->a0 <= best) continue;

    best = it.a0 + jt->a0;
    mask = it.mask + jt->mask;
  }

  if (best == -inf)
    puts("Impossible");
  else {
    REP(i, N) {
      int c = (mask / p3[i]) % 3;
      REP(j, 3) if (j != c) printf("%c", who[j]);
      puts("");
    }
  }

  return 0;
}