/* Written by Filip Hlasek 2018 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

vector< pair<int, int> > v;
int N;
#define MAXN 333333
int dp[MAXN];

bool solve(int X1, int X2, bool order=true) {
  REP(i, N) dp[i] = 0;
  REP(i, N) {
    int val = v[i].first;
    int cnt2 = (X2 + val - 1) / val;
    if (cnt2 <= i + 1) {
      dp[i - cnt2 + 1] = cnt2;
    }
  }
  FORD(i, N - 1, 0) if (!dp[i]) dp[i] = dp[i + 1];

  FOR(cnt1, 1, N - 1) {
    if ((long long)cnt1 * v[cnt1 - 1].first < X1) {
      continue;
    }
    int cnt2 = dp[cnt1];
    if (cnt2) {
      vector<int> ans1, ans2;
      REP(i, cnt1) ans1.push_back(v[i].second);
      REP(i, cnt2) ans2.push_back(v[i + cnt1].second);

      if (!order) swap(ans1, ans2);

      printf("Yes\n");
      printf("%d %d\n", (int)ans1.size(), (int)ans2.size());
      REP(i, ans1.size()) {
        if (i) printf(" ");
        printf("%d", ans1[i] + 1);
      }
      printf("\n");

      REP(i, ans2.size()) {
        if (i) printf(" ");
        printf("%d", ans2[i] + 1);
      }
      printf("\n");

      return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  int X1, X2;
  scanf("%d%d%d", &N, &X1, &X2);
  REP(i, N) {
    int c;
    scanf("%d", &c);
    v.push_back(make_pair(c, i));
  }
  sort(v.rbegin(), v.rend());
  if (!solve(X1, X2) && !solve(X2, X1, false)) {
    printf("No\n");
  }
  return 0;
}