#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAXK = 30;
const int mod = 1000000007;

int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (llint)a * b % mod; }

llint N; int K;

struct Matrix { 
  int m[MAXK + 1][MAXK + 1]; 
};

void gen_id(Matrix &M) {
  REP(i, K + 1) REP(j, K + 1) M.m[i][j] = 0;
  REP(i, K + 1) M.m[i][i] = 1;
}

void gen_matrix(Matrix &M, int r) {
  gen_id(M);
  REP(i, K + 1) M.m[i][r] = 1;
}

void output(Matrix &M) {
  REP(i, K + 1) {
    REP(j, K + 1) printf("%d ", M.m[i][j]);
    puts("");
  }
}

Matrix tmp;
void mule(Matrix &a, const Matrix &b) {
  REP(i, K + 1) REP(j, K + 1) tmp.m[i][j] = 0;
  REP(i, K + 1) REP(j, K + 1) REP(k, K + 1)
    tmp.m[i][j] = add(tmp.m[i][j], mul(a.m[i][k], b.m[k][j]));
  a = tmp;
}

void rot(Matrix &M, int r) {
  REP(i, K + 1) REP(j, K)
    tmp.m[i][j] = M.m[i][(j + r) % K];
  REP(i, K + 1) tmp.m[i][K] = M.m[i][K];
  M = tmp;
  REP(j, K) REP(i, K)
    tmp.m[i][j] = M.m[(i + r) % K][j];
  M = tmp;
}

const int MAXPOS = 61;
int len, x[MAXPOS];

Matrix memo[MAXPOS];
int bio[MAXPOS];

Matrix solve(bool dira, int pos) {
  if (pos == len) {
    Matrix ret;
    if (dira) 
      gen_id(ret);
    else 
      gen_matrix(ret, 0);
    return ret;
  }

  if (!dira && bio[pos])
    return memo[pos];

  Matrix ret; gen_id(ret);

  int lo = 0, hi = dira ? x[pos] : K - 1;
  for (int d = lo; d <= hi; ++d) {
    Matrix now = solve(dira && d == hi, pos + 1);
    rot(now, d);
    mule(ret, now);
  }

  if (!dira) {
    bio[pos] = true;
    memo[pos] = ret;
  }

  return ret;
}

int main(void)
{
  scanf("%I64d%d", &N, &K);

  len = 0;
  while (N) {
    x[len] = N % K;
    N /= K;
    ++len;
  }

  reverse(x, x + len);

  int sol = 0;
  Matrix ret = solve(true, 0);
  REP(i, K + 1) sol = add(sol, ret.m[K][i]);

  printf("%d\n", sol);
  
  return 0;
}