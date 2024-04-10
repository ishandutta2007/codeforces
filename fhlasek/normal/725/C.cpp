/* Written by Filip Hlasek 2016 */
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

int cnt[33];
char input[33];
char ans[2][33];

int main(int argc, char *argv[]) {
  scanf("%s", input);
  REP(i, 27) cnt[input[i] - 'A']++;
  int x;
  REP(i, 26) if (cnt[i] == 2) x = i;
  int pos1 = -1, pos2 = -1;
  REP(i, 27) if (input[i] - 'A' == x) {
    if (pos1 != -1) pos2 = i;
    else pos1 = i;
  }
  if (pos1 + 1 == pos2) { printf("Impossible\n"); return 0; }

  x = 0;
  int y = (pos1 + 26 - pos2) / 2;
  for (int i = pos1; i < pos2; ++i) {
    ans[x][y] = input[i];
    if (x == 0) {
      if (y < 12) ++y;
      else x++;
    }
    else y--;
  }

  x = 0; y = (pos1 + 26 - pos2) / 2;
  for (int i = pos1; i != pos2; i = (i + 26) % 27) {
    ans[x][y] = input[i];
    if (x == 0) {
      if (y) y--;
      else x++;
    }
    else y++;
  }

  printf("%s\n%s\n", ans[0], ans[1]);
  return 0;
}