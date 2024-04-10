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

#define MAXN 7777
#define MAXPOWER 211111
vector<int> _left[MAXN], _right[MAXN], _value[MAXN];
int N, M;

bool power[MAXPOWER];
int less_powers[MAXPOWER];

int ans[MAXN], A;

int main(int argc, char *argv[]) {
  for (int i = 0; (1 << i) < MAXPOWER; i++) power[1 << i] = true;
  REP(i, MAXPOWER - 1) less_powers[i + 1] = less_powers[i] + power[i];

  scanf("%d%d", &N, &M);
  while(M--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int level, l, r, x;
      scanf("%d%d%d%d", &level, &l, &r, &x);
      _left[level].push_back(l);
      _right[level].push_back(r);
      _value[level].push_back(x);
    }
    else {
      int level, l, r;
      A = 0;
      scanf("%d%d", &level, &l);
      r = l;
      for (; level <= N; ++level) {
        // printf("level: %d l: %d r: %d\n", level, l, r);
        REP(i, _left[level].size()) if (_left[level][i] <= r && _right[level][i] >= l)
          ans[A++] = _value[level][i];

        l += less_powers[l];
        r += less_powers[r + 1];
      }
      sort(ans, ans + A);
      int cnt = 0;
      REP(i, A) if (!(i && ans[i-1] == ans[i])) cnt++;
      printf("%d\n", cnt);
    }
  }
  return 0;
}