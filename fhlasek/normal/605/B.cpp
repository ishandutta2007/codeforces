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

int N, M;
vector<pair<int, pair<int, int> > > v;

int K = 1;
queue<int> ex, ey;

#define MAXN 111111
int ansX[MAXN], ansY[MAXN];

bool solve() {
  REP(i, M) {
    int id = v[i].second.second;
    if (v[i].second.first) {
      REP(i, K - 1) {
        if (ex.size() > MAXN) break;
        ex.push(i + 1); ey.push(K);
      }
      ansX[id] = 0;
      ansY[id] = K;
      K++;
    }
    else {
      if (ex.empty()) return false;
      ansX[id] = ex.front(); ex.pop();
      ansY[id] = ey.front(); ey.pop();
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &M);
  REP(i, M) {
    int a, b;
    scanf("%d%d", &a, &b);
    v.push_back(make_pair(a, make_pair(-b, i)));
  }
  sort(v.begin(), v.end());

  if (solve()) REP(i, M) printf("%d %d\n", ansX[i] + 1, ansY[i] + 1);
  else printf("-1\n");

  return 0;
}