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

#define MAXN 333333
pair<long long, long long> team[MAXN];
priority_queue<long long> better;

long long B, b, w;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  N--;

  scanf("%I64d%I64d", &B, &w);
  REP(i, N) {
    scanf("%I64d%I64d", &b, &w);
    team[i] = make_pair(-b, w);
  }
  sort(team, team + N);
  int pos = 0;
  while (pos < N && -team[pos].first > B) {
    better.push(-(team[pos].second - (-team[pos].first)));
    pos++;
  }
  int ans = better.size();
  while (better.size()) {
    long long need = -better.top() + 1; better.pop();
    if (need > B) break;
    B -= need;
    while (pos < N && -team[pos].first > B) {
      better.push(-(team[pos].second - (-team[pos].first)));
      pos++;
    }
    ans = min(ans, (int)better.size());
  }
  printf("%d\n", ans + 1);

  return 0;
}