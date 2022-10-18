/* Written by Filip Hlasek 2017 */
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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

set<int> s;

int main(int argc, char *argv[]) {
  int ans = 0;
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int P;
    scanf("%d", &P); P--;
    if (P == i) ans++;
    else s.insert(P);
  }
  printf("%d\n", ans + (int)s.size() / 2);
  return 0;
}