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

#define MAXN 555555
int N, M, Q;
int P[MAXN];
int qtype[MAXN], qval[MAXN], qsplit[MAXN], qsplitfrom[MAXN];
int ea[MAXN], eb[MAXN], erem[MAXN];

vector< set<pair<int, int> > > group;
int groupid[MAXN];

void merge(int g1, int g2) {
  if (g1 == g2) return;
  if (group[g1].size() < group[g2].size()) return merge(g2, g1);
  for (set<pair<int, int> >::iterator it = group[g2].begin(); it != group[g2].end(); ++it) {
    groupid[it->second] = g1;
  }
  group[g1].insert(group[g2].begin(), group[g2].end());
}

int main(int argc, char *argv[]) {
  scanf("%d%d%d", &N, &M, &Q);
  REP(i, N) scanf("%d", P + i);
  REP(i, M) {
    scanf("%d%d", ea + i, eb + i);
    ea[i]--;
    eb[i]--;
  }
  REP(i, Q) {
    scanf("%d%d", qtype + i, qval + i);
    qval[i]--;
    if (qtype[i] == 2) erem[qval[i]] = true;
  }

  REP(i, N) {
    groupid[i] = group.size();
    set<pair<int, int> > s;
    s.insert(make_pair(-P[i], i));
    group.push_back(s);
  }

  REP(i, M) if (!erem[i]) merge(groupid[ea[i]], groupid[eb[i]]);

  FORD(i, Q - 1, 0) if (qtype[i] == 2) {
    int g1 = groupid[ea[qval[i]]], g2 = groupid[eb[qval[i]]];
    // printf("%d merging %d (%d) and %d (%d)\n", i, g1, (int)group[g1].size(), g2, (int)group[g2].size());
    if (g1 == g2) qsplit[i] = -1;
    else if (group[g1].size() < group[g2].size()) { qsplit[i] = g1; qsplitfrom[i] = g2; }
    else { qsplit[i] = g2; qsplitfrom[i] = g1; }
    merge(g1, g2);
  }

  /*
  REP(i, group.size()) {
    printf("Group #%d:", i);
    for (auto it : group[i]) printf(" (%d, %d)", it.first, it.second);
    printf("\n");
  }

  REP(i, N) printf("i=%d group=%d\n", i, groupid[i]);
  */

  REP(i, Q) {
    if (qtype[i] == 1) {
      int g = groupid[qval[i]];
      printf("%d\n", -group[g].begin()->first);
      int v = group[g].begin()->second;
      group[g].erase(group[g].begin());
      P[v] = 0;
      group[g].insert(make_pair(0, v));
    } else if (qsplit[i] != -1) {
      int g1 = qsplitfrom[i], g2 = qsplit[i];
      // printf("splitting: %d from %d\n", g2, g1);
      set< pair<int, int> > s;
      for (set<pair<int, int> >::iterator it = group[g2].begin(); it != group[g2].end(); ++it) {
        int v = it->second;
        s.insert(make_pair(-P[v], v));
        group[g1].erase(make_pair(-P[v], v));
        groupid[v] = g2;
      }
      group[g2] = s;
    }
  }
  return 0;
}