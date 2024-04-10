/* Written by Filip Hlasek 2020 */
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

int N, K;
char s[333333];

bool solve() {
  REP(i, K) {
    char c = 0;
    for (int j = i; j < N; j += K) if (s[j] != '?') {
      if (!c) {
        c = s[j];
      } else {
        if (c != s[j]) return false;
      }
    }
    if (c) for (int j = i; j < N; j += K) if (s[j] == '?') s[j] = c;
  }
  int c0 = 0, c1 = 0;
  REP(i, K) {
    if (s[i] == '0') c0++;
    if (s[i] == '1') c1++;
  }
  return c0 <= K / 2 && c1 <= K / 2;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &K);
    scanf("%s", s);
    printf("%s\n", solve() ? "YES" : "NO");
  }
	
	return 0;
}