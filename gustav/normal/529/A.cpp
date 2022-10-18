#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 2000005;
const int base = 10007;
const int mod = 1000000007;

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return add(a, mod - b); }
int mul(int a, int b) { return (llint)a * b % mod; }

int p[MAXN];
int h[MAXN];

int n;
char b[MAXN];

int hf(int i, int len) {
  int ret = h[i + len - 1];
  if (i) ret = sub(ret, mul(h[i - 1], p[len]));
  return ret;
}

struct String { 
  int i, L, R; 
  int hash(int len) { return hf(i, len); }
  int get(int j) { return b[i + j]; }
};

bool operator<(String a, String b) {
  int lo = 0, hi = n, mid;
  while (lo < hi) {
    mid = (lo + hi + 1) / 2;
    if (a.hash(mid) != b.hash(mid))
      hi = mid - 1;
    else
      lo = mid;
  }
  if (lo == n) return 0;
  return a.get(lo) < b.get(lo);
}

vector< String > cand;

int main(void) 
{
  scanf("%s", b);
  n = strlen(b);
  REP(i, n) b[i + n] = b[i];

  p[0] = 1;
  h[0] = b[0];
  FOR(i, 1, 2 * n) {
    p[i] = mul(p[i - 1], base);
    h[i] = add(mul(h[i - 1], base), b[i]);
  }

  int sum = 0;
  int shift = 0;
  multiset< int > pq;

  REP(i, n) {
    sum += (b[i] == '(') ? +1 : -1;
    pq.insert(sum);
  }

  int best = 5 * n;
  String sol = {-1, -1, -1};

  REP(i, n) {
    int now = n;
    int minv = *pq.begin() + shift;
    int L = (minv < 0) ? -minv : 0;
    int R = (sum > 0) ? sum : 0;
    now += L;
    now += R;

    if (now < best) {
      best = now;
      sol = {i, L, R};
    } else if (now == best) {
      String cur = {i, L, R};
      if (cur < sol)
	sol = cur;
    }

    int val = (b[i] == '(') ? +1 : -1;
    pq.erase(pq.find((val - shift)));
    shift -= val;
    pq.insert(sum - shift);
  }

  REP(i, sol.L) putchar('(');
  REP(i, n) putchar(b[i + sol.i]);
  REP(i, sol.R) putchar(')');
  puts("");

  return 0;
}