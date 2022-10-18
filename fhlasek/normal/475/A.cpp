/* Written by Filip Hlasek 2014 */
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

char ans[50][50] = {
  "+------------------------+",
  "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
  "|#.#.#.#.#.#.#.#.#.#.#.|.|",
  "|#.......................|",
  "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
  "+------------------------+"
};

int main(int argc, char *argv[]) {
  int K;
  scanf("%d", &K);
  while (K--) {
    REP(j, 25) {
      bool ok = false;
      REP(i, 6) if (ans[i][j] == '#') {
        ans[i][j] = 'O';
        ok = true;
        break;
      }
      if (ok) break;
    }
  }
  REP(i, 6) printf("%s\n", ans[i]);
  return 0;
}