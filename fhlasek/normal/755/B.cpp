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

char input[1111];

set<string> a;

int main(int argc, char *argv[]) {
  int N, M;
  scanf("%d%d", &N, &M);
  REP(i, N) {
    scanf("%s", input);
    a.insert(string(input));
  }
  int common = 0;
  REP(i, M) {
    scanf("%s", input);
    common += a.count(string(input));
  }
  N -= common; M -= common;
  N += (common + 1) / 2;
  M += (common) / 2;
  printf(N > M ? "YES\n" : "NO\n");
  return 0;
}