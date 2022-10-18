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

char pokemon[8][20] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

char input[20];

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  scanf("%s", input);
  REP(i, 8) {
    if (N != strlen(pokemon[i])) continue;
    bool ok = true;
    REP(j, N) if (input[j] != '.' && input[j] != pokemon[i][j]) ok = false;
    if (ok) { printf("%s\n", pokemon[i]); break; }
  }
  return 0;
}