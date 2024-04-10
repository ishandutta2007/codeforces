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

#define MAXN 1000000
int father[MAXN], Rank[MAXN], l[MAXN];

int root(int x) { return father[x] == -1 ? x : (father[x] = root(father[x])); }

int N, A[MAXN];
vector< pair<int, int> > v;
int ans[MAXN];

bool done[MAXN];

bool DFU(int a, int b, int _ans) {
  int ca = root(a), cb = root(b);
  if (ca != cb) {
    // printf("joining: %d %d, %d %d\n", ca, l[ca], cb, l[cb]);
    if (Rank[ca] < Rank[cb]) {
      father[ca] = cb;
      l[cb] += l[ca];
      ans[l[cb]] = max(ans[l[cb]], _ans);
    }
    else if (Rank[cb] < Rank[ca]) {
      father[cb] = ca;
      l[ca] += l[cb];
      ans[l[ca]] = max(ans[l[ca]], _ans);
    }
    else {
      Rank[ca]++;
      father[cb] = ca;
      l[ca] += l[cb];
      ans[l[ca]] = max(ans[l[ca]], _ans);
    }
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
  REP(i, N) { father[i] = -1; Rank[i] = 0; l[i] = 1; }
  REP(i, N) v.push_back(make_pair(A[i], i));
  sort(v.begin(), v.end()); reverse(v.begin(), v.end());
  REP(i, N) {
    int x = v[i].second;
    done[x] = true;
    ans[1] = max(ans[1], v[i].first);
    if (x && done[x - 1]) DFU(x, x - 1, v[i].first);
    if (done[x + 1])      DFU(x, x + 1, v[i].first);
  }
  FORD(i, N - 1, 1) ans[i] = max(ans[i], ans[i + 1]);
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i + 1]);
  }
  printf("\n");
  return 0;
}