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

#define MAXN 444444
char n[MAXN];

int main(int argc, char *argv[]) {
  int N, t;
  n[0] = '0';
  scanf("%d%d", &N, &t);
  scanf("%s", n + 1);
  int d = 0;
  while (n[d] != '.') ++d;
  ++d;
  while (d <= N && n[d] < '5') ++d;
  if (d <= N) {
    while (t--) {
      n[d] = '\0';
      d--;
      if (n[d] == '.') {
        n[d] = '\0';
        d--;
        while (true) {
          if (n[d] == '9') n[d--] = '0';
          else { n[d]++; break; }
        }
        break;
      }
      else {
        n[d]++;
        if (n[d] < '5') break;
      }
    }
  }
  if (n[0] != '0') printf("%s\n", n);
  else printf("%s\n", n + 1);
  return 0;
}