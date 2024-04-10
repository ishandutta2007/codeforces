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

string get_it(int M, int S) {
  string ans = "";
  REP(i, M) {
    ans.push_back(min(9, S) + '0');
    S -= min(9, S);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int M, S;
  scanf("%d%d", &M, &S);
  if (S == 0) {
    if (M == 1) printf("0 0\n");
    else printf("-1 -1\n");
    return 0;
  }
  if (S > 9 * M) { printf("-1 -1\n"); return 0; }

  if (S - 1 > 9 * (M - 1)) {
    string s = get_it(M, S);
    reverse(s.begin(), s.end());
    printf("%s", s.c_str());
  }
  else {
    printf("1");
    string s = get_it(M - 1, S - 1);
    reverse(s.begin(), s.end());
    printf("%s", s.c_str());
  }
  printf(" %s\n", get_it(M, S).c_str());
  return 0;
}