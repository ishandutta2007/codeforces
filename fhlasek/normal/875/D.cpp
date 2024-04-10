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

#define MAXN 222222
int N, A[MAXN];
int nextNumber[MAXN][30];

map< int, set<int> > m;

int getNext(int start, int n) {
  set<int> &s = m[n];
  set<int>::iterator it = s.lower_bound(start);
  if (it == s.end()) return N;
  return *it;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  REP(i, N) m[A[i]].insert(i);
  REP(i, 30) nextNumber[N][i] = N;
  FORD(i, N - 1, 0) {
    REP(bit, 30) {
      if (A[i] & (1 << bit)) nextNumber[i][bit] = i;
      else nextNumber[i][bit] = nextNumber[i + 1][bit];
    }
  }
  long long ans = 0;
  REP(start, N) {
    set<int> candidates;
    candidates.insert(N);
    REP(bit, 30) candidates.insert(nextNumber[start][bit]);
    vector<int> c(candidates.begin(), candidates.end());
    int n = 0;
    REP(i, c.size() - 1) {
      n |= A[c[i]];
      int tmp = min(c[i + 1], getNext(start, n)) - c[i];
      // printf("start: %d n: %d tmp: %d\n", start, n, tmp);
      ans += tmp;
    }
  }
  cout << ans << endl;
  return 0;
}