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

char input[111][11];
char color[10] = "RGBYW";

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%s", input[i]);

  int ans = 10;
  REP(mask, 1 << 10) {
    bool ok = true;
    int cnt = 0;
    vector<int> v;
    REP(i, 10) if (mask & (1 << i)) v.push_back(i);
    if (v.size() >= ans) continue;
    REP(i, N) REP(j, i) {
      if (input[i][0] == input[j][0] && input[i][1] == input[j][1]) continue;
      bool same = true;
      REP(k, v.size()) {
        int t = v[k];
        if (t < 5) {
          if ((color[t] == input[i][0]) ^ (color[t] == input[j][0])) {
            same = false;
            break;
          }
        }
        else {
          if ((t - 5 == input[i][1] - '1') ^ (t - 5 == input[j][1] - '1')) {
            same = false;
            break;
          }
        }
      }
      if (same) { ok = false; break; }
    }
    if (ok) ans = v.size();
  }
  printf("%d\n", ans);

  return 0;
}