#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const llint mod = 1e9 + 7;

llint add(llint a, llint b) { return (a + b) % mod; }
llint mul(llint a, llint b) { return (llint)a * b % mod; }

const int MAXN = 1000005; 

int n, k;
llint l;

int a[MAXN];

void pref_sum(map< llint, llint > &m) {
  llint sum = 0;
  for (auto &it : m) {
    sum = add(sum, it.second);
    it.second = sum;
  }
}

int main(void) 
{
  scanf("%d%lld%d", &n, &l, &k);
  REP(i, n) scanf("%d", a + i);

  llint B = l / n;

  map< llint, llint > cnt;
  REP(i, n) ++cnt[a[i]];

  map< llint, llint > seq_cnt = cnt;

  llint sol = l % mod;

  REP(i, k - 1) {
    pref_sum(seq_cnt);
    llint count;
    
    if (l % n) {
      count = 0;
      REP(j, l % n) {
	count = add(count, seq_cnt[a[j]]);
      }

      if (B >= i + 1)
	sol = add(sol, count);
    }

    count = 0;
    for (auto it : cnt) {
      seq_cnt[it.first] = mul(seq_cnt[it.first], it.second);
      count = add(count, seq_cnt[it.first]);
    }

    if (B >= i + 2)
      sol = add(sol, mul(count, (B - i - 1) % mod));
  }

  printf("%lld\n", sol);

  return 0;
}