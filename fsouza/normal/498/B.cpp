#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, maxt;

  scanf("%d %d", &n, &maxt);

  double result = 0.0;

  vector<double> dp(maxt+1, 0.0), delta(maxt+1), add(maxt+1);
  dp[0] = 1.0;

  for (int i = 0; i < n; i++) {
    int pi, ti;
    scanf("%d %d", &pi, &ti);

    double p = pi / 100.0;
    double notp = 1 - p;

    fill(delta.begin(), delta.end(), 0.0);
    fill(add.begin(), add.end(), 0.0);

    if (pi == 0) {
      for (int t = 0; t+ti <= maxt; t++)
	add[t+ti] += dp[t];
    } else if (pi == 100) {
      for (int t = 0; t+1 <= maxt; t++)
	add[t+1] += dp[t];
    } else {
      double pnpti1 = pow(notp, ti-1);

      for (int t = 0; t+1 <= maxt; t++) {
	delta[t+1] += dp[t] * p;
      
	if (t+ti <= maxt) {
	  delta[t+ti] -= dp[t] * p * pnpti1;
	  add[t+ti] += dp[t] * (1.0 - p * (1 - pnpti1)/(1 - notp));
	}
      }
    }
    
    double acc = 0.0;
    for (int t = 0; t <= maxt; t++) {
      acc *= notp;
      acc += delta[t];
      dp[t] = acc + add[t];
      result += dp[t];
    }
  }

  printf("%.10f\n", result);

  return 0;
}