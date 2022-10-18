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

char a[22], b[22];

int main(int argc, char *argv[]) {
  scanf("%s", a);
  scanf("%s", b);
  int N = strlen(a), D = 0;
  REP(i, N / 2) {
    if (a[2 * i] == '8' && b[2 * i] == '[') D++;
    if (a[2 * i] == '[' && b[2 * i] == '8') D--;

    if (a[2 * i] == '[' && b[2 * i] == '(') D++;
    if (a[2 * i] == '(' && b[2 * i] == '[') D--;

    if (a[2 * i] == '(' && b[2 * i] == '8') D++;
    if (a[2 * i] == '8' && b[2 * i] == '(') D--;
  }
  if (D == 0) printf("TIE\n");
  else if (D > 0) printf("TEAM 1 WINS\n");
  else printf("TEAM 2 WINS\n");
  
  return 0;
}