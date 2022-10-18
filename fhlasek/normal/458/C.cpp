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
vector<int> cost[MAXN];
int o[MAXN];

priority_queue<int> min_heap, max_heap;

bool cmp(int a, int b) { return cost[a].size() > cost[b].size(); }

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);

  int total = 0;
  REP(i, N) {
    int a, b;
    scanf("%d%d", &a, &b);
    cost[a].push_back(b);
    total += b;
  }
  REP(i, MAXN) sort(cost[i].begin(), cost[i].end());
  REP(i, MAXN - 1) o[i] = i + 1;
  sort(o, o + MAXN - 1, cmp);

  int best = total, voters = N;

  FOR(max_others, 1, N) {
    REP(ii, MAXN - 1) {
      int i = o[ii];
      if (cost[i].size() < max_others) break;
      voters--;
      int val = cost[i][cost[i].size() - max_others];
      total -= val;
      min_heap.push(-val);
    }
    // printf("voters: %d total: %d\n", voters, total);
    while (!min_heap.empty() && !max_heap.empty() && -min_heap.top() < max_heap.top()) {
      int a = -min_heap.top(), b = max_heap.top();
      min_heap.pop(); max_heap.pop();
      total -= b - a;
      min_heap.push(-b); max_heap.push(a);
    }
    while (!min_heap.empty() && voters <= max_others) {
      int a = -min_heap.top(); min_heap.pop();
      voters++;
      total += a;
      max_heap.push(a);
    }
    // printf("max_others: %d voters: %d total: %d\n", max_others, voters, total);
    if (voters > max_others) best = min(best, total);
  }

  printf("%d\n", best);

  return 0;
}