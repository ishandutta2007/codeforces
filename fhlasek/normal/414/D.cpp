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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111111
#define MAXM MAXN
#define LOG 20

int start[MAXN], n[2 * MAXM], tmp[MAXN], eA[MAXM], eB[MAXM], N, M, _stack[MAXN], S;
int father[MAXN], depth[MAXN], root;
class Graph{
  public:
    void buildFromEdges(int _N, int _M) {
      N = _N;
      M = _M;
      REP(i, N) tmp[i] = 0;
      REP(i, M) {
        tmp[eA[i]]++;
        tmp[eB[i]]++; // comment if only one direction
      }
      REP(i, N) start[i+1] = start[i] + tmp[i];
      REP(i, M) {
        int a = start[eA[i]] + (--tmp[eA[i]]), b = start[eB[i]] + (--tmp[eB[i]]);
        n[a] = eB[i];
        n[b] = eA[i];
      }
    }
};
class Tree : public Graph{
  public:
    void buildFromEdges(int _N) {
      Graph::buildFromEdges(_N, _N - 1);
      root = 0;
      father[root] = root;
      depth[root] = 0;
      S = 0;
      _stack[S++] = root;
      while(S) {
        int x = _stack[--S];
        for(int i = start[x]; i < start[x+1]; i++) {
          if(n[i] != father[x]) {
            father[n[i]] = x;
            depth[n[i]] = depth[x] + 1;
            _stack[S++] = n[i];
          }
        }
      }
    }
};

vector<int> d[MAXN];
queue<int> q;

Tree t;
int main(int argc, char *argv[]) {
  int N, K, P;
  scanf("%d%d%d", &N, &K, &P);
  REP(i, N-1) {
    scanf("%d%d", eA+i, eB+i);
    eA[i]--; eB[i]--; // 1-indexed
  }
  t.buildFromEdges(N);

  REP(i, N) d[depth[i]].push_back(i);

  int best = 0, cost = 0;

  FOR(i, 1, N + 1) {
    cost += q.size();
    REP(j, d[i].size()) q.push(d[i][j]);
    while (cost > P || q.size() > K) {
      int n = q.front(); q.pop();
      cost -= i - depth[n];
    }
    best = max(best, (int)q.size());
  }

  printf("%d\n", best);

  return 0;
}