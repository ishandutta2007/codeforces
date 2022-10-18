/* Written by Filip Hlasek 2015 */
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

vector<pair<int, int> > v;
priority_queue< pair<int, int> > pq;

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  while (N--) {
    int x, w;
    scanf("%d%d", &x, &w);
    v.push_back(make_pair(x - w, x + w));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  REP(i, v.size()) {
    while (!pq.empty() && -pq.top().first <= v[i].first) {
      ans = max(ans, pq.top().second);
      pq.pop();
    }
    pq.push(make_pair(-v[i].second, ans + 1));
  }
  while (!pq.empty()) {
    ans = max(ans, pq.top().second);
    pq.pop();
  }
  printf("%d\n", ans);
  return 0;
}