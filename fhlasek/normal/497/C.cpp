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
int N, M;
vector<pair<pair<int, int>, pair<int, int> > > actor;
vector<pair<pair<int, int>, int> > part;

int ans[MAXN];

set< pair<int, int> > s;

bool solve() {
  sort(part.begin(), part.end());
  sort(actor.begin(), actor.end());
  int pos = 0;
  REP(i, part.size()) {
    while (pos < M && actor[pos].first.first <= part[i].first.first) {
      s.insert(make_pair(actor[pos].first.second, pos));
      pos++;
    }
    set< pair<int, int> >::iterator it = s.lower_bound(make_pair(part[i].first.second, 0));
    if (it == s.end()) return false;
    int a = it->second;
    if (--actor[a].second.first == 0) s.erase(it);
    ans[part[i].second] = actor[a].second.second;
  }
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) {
    int a, b;
    scanf("%d%d", &a, &b);
    part.push_back(make_pair(make_pair(a, b), i));
  }
  scanf("%d", &M);
  REP(i, M) {
    int c, d, k;
    scanf("%d%d%d", &c, &d, &k);
    actor.push_back(make_pair(make_pair(c, d), make_pair(k, i)));
  }

  if (solve()) {
    printf("YES\n");
    REP(i, N) {
      if (i) printf(" ");
      printf("%d", ans[i] + 1);
    }
    printf("\n");
  }
  else printf("NO\n");
  return 0;
}