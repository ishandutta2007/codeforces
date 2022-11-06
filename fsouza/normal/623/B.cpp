#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

void fact(int v, vector<int> &primes) {
  for (int p = 2; p*p <= v; ++p)
    if (v%p == 0) {
      primes.push_back(p);
      while (v%p == 0) v /= p;
    }
  if (v != 1) primes.push_back(v);
}

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  vector<int> val(n);
  for (int i = 0; i < n; ++i) scanf("%d", &val[i]);

  vector<int> cand;
  for (int d = -1; d <= 1; ++d) {
    fact(val[0]+d, cand);
    fact(val[n-1]+d, cand);
  }
  sort(cand.begin(), cand.end());
  cand.resize(unique(cand.begin(), cand.end())-cand.begin());

  const lint BIG = 1000000000000000000LL;

  vector<lint> cost(n), rightcostsum(n);
  vector<lint> dp(n+1);
  
  lint result = BIG;
  for (int p : cand) {
    for (int i = 0; i < n; ++i)
      if (val[i]%p == 0) cost[i] = 0;
      else if ((val[i]-1)%p == 0) cost[i] = b;
      else if ((val[i]+1)%p == 0) cost[i] = b;
      else cost[i] = BIG;

    rightcostsum[n-1] = cost[n-1];
    for (int i = n-2; i >= 0; --i)
      rightcostsum[i] = min(BIG, rightcostsum[i+1] + cost[i]);

    dp[n] = 0;
    for (int i = n-1; i >= 0; --i) {
      dp[i] = min(a + dp[i+1], rightcostsum[i]);
    }

    result = min(result, dp[0]);
    
    lint leftcostsum = 0;
    for (int i = 0; i < n; ++i) {
      leftcostsum = min(BIG, leftcostsum + cost[i]);
      result = min(result, leftcostsum + dp[i+1]);
    }
  }

  cout << result << endl;
  
  return 0;
}