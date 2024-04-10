/* Written by Filip Hlasek 2017 */
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

#define MAXN 111
int N;
long long K;
int A[MAXN];

set<long long> ds;

bool valid(long long d) {
  long long sum = 0;
  REP(i, N) {
    long long tmp = A[i] % d;
    sum += tmp ? d - tmp : 0;
  }
  return sum <= K;
}

int main(int argc, char *argv[]) {
  cin >> N >> K;
  REP(i, N) scanf("%d", A + i);
  ds.insert(K + A[0]);
  ds.insert(K + A[0] + 1);
  REP(i, 100000) ds.insert(i + 1);
  REP(i, N) REP(j, min(10000, A[i])) {
    ds.insert(A[i] / (j + 1));
    ds.insert(A[i] / (j + 1) + 1);
  }
  long long l = 1;
  long long r = 1;
  for(set<long long>::iterator it = ds.begin(); it != ds.end(); ++it) {
    if (valid(*it)) {
      l = *it;
      set<long long>::iterator nit = it;
      ++nit;
      r = *nit;
    }
  }

  while (l < r) {
    long long m = (l + r + 1) / 2;
    if (valid(m)) l = m;
    else r = m - 1;
  }
  cout << l << endl;

  return 0;
}