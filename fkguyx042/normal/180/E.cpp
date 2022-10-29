#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

vector<int> pos[1000010];

int solve(vector<int> ps, int k) {
  int n = ps.size();
  int j = 0, d = 0, r = 0;

  // [ps[i], ps[j]]
  rep (i, n) {
    j = max(j, i);
    while (j + 1 < n) {
      int td = (ps[j + 1] - ps[i] + 1) - ((j + 1) - i + 1);
      if (td <= k) {
        ++j;
        d = td;
      } else {
        break;
      }
    }
    // printf("[%d, %d] %d\n", ps[i], ps[j], d);
    r = max(r, j - i + 1);
  }
  return r;
}

int main() {
  int N, M, K;
  while (3 == scanf("%d%d%d", &N, &M, &K)) {
    rep (i, M) pos[i].clear();

    rep (i, N) {
      int a;
      scanf("%d", &a);
      --a;
      pos[a].pb(i);
    }

    int ans = 0;
    rep (i, M) ans = max(ans, solve(pos[i], K));
    printf("%d\n", ans);
  }

  return 0;
}