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

#define MAXN 333333

map<int, pair<int, int> > m;
int A[MAXN], N;

vector<pair<int, int> > v;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    m.clear();
    v.clear();
    scanf("%d", &N);
    REP(i, N) scanf("%d", A + i);
    REP(i, N) {
      pair<int, int> cur = m[A[i]];
      m[A[i]] = make_pair(i + 1, max(cur.second, (i + 1) - cur.first));
    }

    for (map<int, pair<int, int> >::iterator it = m.begin(); it != m.end(); ++it) {
      v.push_back(make_pair(max(it->second.second, N + 1 - it->second.first), it->first));
    }

    sort(v.begin(), v.end());

    int ans = N + 1, k = 0;
    FOR(g, 1, N) {
      while (k < (int)v.size() && g == v[k].first) ans = min(ans, v[k++].second);
      if (g > 1) printf(" ");
      printf("%d", ans == N + 1 ? -1 : ans);
    }
    printf("\n");
  }
  return 0;
}