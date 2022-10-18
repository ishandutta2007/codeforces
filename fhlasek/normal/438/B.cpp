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

#define MAXN 222222
vector<int> graph[MAXN];
vector<pair<int, int> > v;
int N, M, A[MAXN];
bool used[MAXN];

int father[MAXN], sz[MAXN], rank[MAXN];
int root(int x) { return father[x] == -1 ? x : (father[x] = root(father[x])); }

long long DFU(int a, int b) {
  int ca = root(a), cb = root(b);
  if (ca == cb) return 0;

  long long ans = (long long)sz[ca] * sz[cb];

  if (rank[ca] < rank[cb]) {
    father[ca] = cb;
    sz[cb] += sz[ca];
  }
  else if (rank[cb] < rank[ca]) {
    father[cb] = ca;
    sz[ca] += sz[cb];
  }
  else {
    rank[ca]++;
    father[cb] = ca;
    sz[ca] += sz[cb];
  }

  return ans;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, N) {
    scanf("%d", A + i);
    v.push_back(make_pair(A[i], i));
  }
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  REP(i, N) { father[i] = -1; rank[i] = 0; sz[i] = 1; }
  sort(v.begin(), v.end());

  long long ans = 0;
  FORD(i, N - 1, 0) {
    int x = v[i].second;
    REP(j, graph[x].size()) if (used[graph[x][j]]) {
      ans += A[x] * DFU(x, graph[x][j]);
    }
    used[x] = true;
  }
  printf("%.15lf\n", (double)2 * ans / N / (N - 1));

  return 0;
}