#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iomanip>
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

#define MAXN 300

using namespace std;

typedef long long lint;
typedef long double ldouble;

const int lim = 100000;
ldouble logfact[lim+1];
ldouble logbinom(int a, int b) { return logfact[a] - logfact[b] - logfact[a-b]; }

int main() {
  int n, many, chosen;
  scanf("%d %d %d", &n, &many, &chosen);

  logfact[0] = 0;
  for (int v = 1; v <= lim; ++v) logfact[v] = logfact[v-1] + logl(v);

  ldouble result = 0;

  for (int nr = n; nr >= 0; --nr)
    for (int nc = n; nc >= 0; --nc) {
      int need = n * (nr+nc) - nr*nc;
      if (chosen >= need) {
	ldouble logp = logbinom(many - need, chosen - need) - logbinom(many, chosen);
	logp += logbinom(n, nr);
	logp += logbinom(n, nc);
	result += expl(logp);
      }
    }

  if (!isfinite((double)result) || result > powl(10, 99)) printf("1e99\n");
  else cout << setprecision(11) << (double)max(ldouble(0), result) << "\n";


  return 0;
}