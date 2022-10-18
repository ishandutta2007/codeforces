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

#define MAXN 1111111
int A[MAXN], B[MAXN];
char Dir[MAXN];
int C;

vector<int> ans;

bool check() {
  REP(i, C) if (A[i] >= B[i]) return false;
  return true;
}

bool solve(int root, int R) {
  // printf("root: %d R: %d\n", root, R);
  int go_right = R + 1;
  REP(i, C) if (Dir[i] == 'L' && A[i] == root && B[i] > R) return false;
  REP(i, C) if (Dir[i] == 'R' && A[i] == root) {
    if (B[i] > R) return false;
    go_right = min(go_right, B[i]);
  }
  if (R == root) {
    ans.push_back(root);
    return true;
  }
  if (go_right == R + 1) {
    bool ret = solve(root + 1, R);
    ans.push_back(root);
    return ret;
  }
  bool change = true;
  while (change) {
    change = false;
    REP(i, C) if (B[i] >= go_right && B[i] <= R && A[i] < go_right && A[i] > root) {
      go_right = A[i];
      change = true;
    }
  }
  REP(i, C) if (Dir[i] == 'L' && A[i] == root && B[i] >= go_right) return false;
  if (go_right == root + 1) {
    ans.push_back(root);
    return solve(root + 1, R);
  }
  bool ret = solve(root + 1, go_right - 1);
  ans.push_back(root);
  return ret && solve(go_right, R);
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d%d", &N, &C);
  REP(i, C) {
    char w[10];
    scanf("%d%d%s", A + i, B + i, w);
    Dir[i] = w[0];
  }
  if (check() && solve(1, N)) {
    REP(i, ans.size()) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  else printf("IMPOSSIBLE\n");
  return 0;
}