#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

const int mod = 1e9+7;

vector<vector<int>> solvedp(vector<int> values, int K) {
  int n = values.size();
  vector<vector<int>> result(K+1, vector<int>(n));
  vector<vector<int>> resultsum(K+1, vector<int>(n));
  
  result[0][0] = 1;
  for (int i = 1; i < n; ++i) result[0][i] = 0;
  resultsum[0][0] = result[0][0];
  for (int i = 1; i < n; ++i) resultsum[0][i] = (resultsum[0][i-1] + result[0][i]) % mod;

  vector<int> upto(n);
  for (int i = 0; i < n; ++i) upto[i] = upper_bound(values.begin(), values.end(), values[i]) - values.begin() - 1;
  
  for (int k = 1; k <= K; ++k) {
    for (int i = 0; i < n; ++i) {
      result[k][i] = resultsum[k-1][upto[i]];
      resultsum[k][i] = result[k][i];
      if (i > 0) {
	resultsum[k][i] += resultsum[k][i-1];
	if (resultsum[k][i] >= mod) resultsum[k][i] -= mod;
      }
    }
  }

  return move(result);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, K;
  lint lenb;
  cin >> n >> lenb >> K;
  vector<int> values(n);
  for (int i = 0; i < n; ++i) cin >> values[i];

  vector<int> sortedvalues = values;
  sort(sortedvalues.begin(), sortedvalues.end());

  vector<vector<int>> dp = solvedp(sortedvalues, K);
  lint nblock = lenb / n;
  int rest = lenb % n;

  int result = 0;

  for (int k = 1; k <= min(nblock, (lint)K); ++k)
    for (int i = 0; i < n; ++i)
	result = (result + (lint)(nblock-k+1) % mod * dp[k][i]) % mod;  

  for (int i = 0; i < rest; ++i) {
    int id = lower_bound(sortedvalues.begin(), sortedvalues.end(), values[i]) - sortedvalues.begin();
    for (int k = 1; k <= min((lint)K, nblock+1); ++k)
      result = (result + dp[k][id]) % mod;
  }
  
  cout << result << "\n";
  
  return 0;
}