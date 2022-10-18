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

#define MAXN 111111
char s[MAXN];

int main(int argc, char *argv[]) {
  scanf("%s", s);
  int S = strlen(s);
  int first_nona = 0;
  while (first_nona < S && s[first_nona] == 'a') ++first_nona;
  if (first_nona == S) {
    s[S - 1] = 'z';
    printf("%s\n", s);
    return 0;
  }
  while (first_nona < S && s[first_nona] != 'a') s[first_nona++]--;
  printf("%s\n", s);
  return 0;
}