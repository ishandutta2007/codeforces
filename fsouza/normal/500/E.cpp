#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>

#define MAXN 200000
#define MAXLOGN 18

using namespace std;

int mylog2(int x) {return __builtin_clz(1) - __builtin_clz(x);}

struct state {
  int lastx;
  int lastguy;
  int cost;
} dp[MAXN][MAXLOGN+1];

int x[MAXN], h[MAXN];

int main() {
  int n;

  scanf("%d", &n);
  
  int lgn = mylog2(n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &h[i]);
  }

  stack<int> st;
  for (int i = n-1; i >= 0; i--) {
    dp[i][0].lastx = x[i] + h[i];
    dp[i][0].lastguy = i;
    dp[i][0].cost = 0;

    while (!st.empty() && dp[i][0].lastx >= x[st.top()]) {
      int guy = st.top();
      dp[i][0].lastx = max(dp[i][0].lastx, dp[guy][0].lastx);
      dp[i][0].lastguy = max(dp[i][0].lastguy, dp[guy][0].lastguy);
      st.pop();
    }
    st.push(i);
  }

  for (int l = 1; l <= lgn; l++) {
    for (int i = 0; i < n; i++) {
      dp[i][l] = dp[i][l-1];

      int nextguy = dp[i][l-1].lastguy+1;
      if (nextguy < n) {
	dp[i][l].cost += x[nextguy] - dp[i][l-1].lastx;

	dp[i][l].lastx = dp[nextguy][l-1].lastx;
	dp[i][l].lastguy = dp[nextguy][l-1].lastguy;
	dp[i][l].cost += dp[nextguy][l-1].cost;
      }
    }
  }

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;

    state st = dp[a][0];

    for (int l = lgn; l >= 0; l--)
      if (st.lastguy+1 < n && dp[st.lastguy+1][l].lastguy < b) {
	int nextguy = st.lastguy+1;
	
	st.cost += x[nextguy] - st.lastx;
	st.lastx = dp[nextguy][l].lastx;
	st.lastguy = dp[nextguy][l].lastguy;
	st.cost += dp[nextguy][l].cost;
      }

    if (st.lastguy < b) {
      const int l = 0;
      int nextguy = st.lastguy+1;
	
      st.cost += x[nextguy] - st.lastx;
      st.lastx = dp[nextguy][l].lastx;
      st.lastguy = dp[nextguy][l].lastguy;
      st.cost += dp[nextguy][l].cost;
    }

    printf("%d\n", st.cost);
  }

  return 0;
}