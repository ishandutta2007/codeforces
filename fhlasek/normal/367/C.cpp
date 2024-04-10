/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
int w[MAXN];

int main(int argc, char *argv[]) {
  int N, M, q;
  scanf("%d%d", &N, &M);
  REP(i, M) scanf("%d%d", &q, w + i);
  sort(w, w + M);
  int best = 0;
  FOR(m, 1, M) {
    long long tmp = (long long)m * (m - 1) / 2 + 1;
    if(m % 2 == 0) tmp += m / 2 - 1;
    if(tmp <= N) best = m;
  }
  long long sum = 0;
  REP(i, best) sum += w[M - i - 1];
  cout << sum << endl;

  return 0;
}