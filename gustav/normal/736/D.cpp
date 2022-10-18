#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 2000;
const int MAXM = 500000;

int N, M;
int x[MAXM];
int y[MAXM];
bitset< 2 * MAXN > A[MAXN];

int main(void) 
{
  scanf("%d%d", &N, &M);

  REP(i, M) {
    scanf("%d%d", &x[i], &y[i]); --x[i]; --y[i];
    A[x[i]][y[i]] = 1;
  }

  REP(i, N) A[i][i + N] = 1;

  REP(i, N) {
    if (A[i][i] == 0) {
      int good = i;
      FOR(j, i + 1, N) {
	if (A[j][i]) {
	  good = j;
	  break;
	}
      }
      assert(good > i);
      swap(A[good], A[i]);
    }

    REP(j, N) {
      if (j == i) continue;
      if (A[j][i] == 0) continue;
      A[j] ^= A[i];
    }
  }

  REP(i, M)
    puts(A[y[i]][x[i] + N] ? "NO" : "YES");

  return 0;
}