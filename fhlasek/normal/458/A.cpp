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

#define MAXN 111111
char num[2][MAXN];

int main(int argc, char *argv[]) {
  REP(i, 2) {
    scanf("%s", num[i]);
    reverse(num[i], num[i] + strlen(num[i]));
    int pos = MAXN - 1;
    while (pos >= 1) {
      if (num[i][pos] == '1' && num[i][pos - 1] == '1') {
        num[i][pos] = num[i][pos - 1] = 0;
        num[i][pos + 1] = '1';
        pos += 2;
      }
      else pos--;
    }
  }
  FORD(i, MAXN - 1, 0) {
    if (num[0][i] == '1' && num[1][i] != '1') { printf(">\n"); return 0; }
    if (num[0][i] != '1' && num[1][i] == '1') { printf("<\n"); return 0; }
  }
  printf("=\n");
  return 0;
}