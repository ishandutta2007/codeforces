#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2005;

int n, a, b;
pair<double, pair<int, int>> dp[ms];
double pa[ms], pb[ms], pab[ms];

pair<double, pair<int, int>> solve(double c, double d) {
  for(int i = n-1; i >= 0; i--) {
    dp[i] = dp[i+1];
    dp[i] = max(dp[i], {dp[i+1].first + pa[i] - c, {dp[i+1].second.first+1, dp[i+1].second.second}});
    dp[i] = max(dp[i], {dp[i+1].first + pb[i] - d, {dp[i+1].second.first, dp[i+1].second.second+1}});
    dp[i] = max(dp[i], {dp[i+1].first + pab[i] - c - d, {dp[i+1].second.first+1, dp[i+1].second.second+1}});
  }
  return dp[0];
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cout << fixed << setprecision(8);
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++) {
    cin >> pa[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> pb[i];
    pab[i] = pa[i] + pb[i] - pa[i]*pb[i];
  }
  double lo1 = 0, hi1 = 1;
  double lo2 = 0, hi2 = 1;
  for(int it = 0; it < 50; it++) {
    lo2 = 0; hi2 = 1;
    double mi1 = (hi1+lo1)/2;
    for(int it2 = 0; it2 < 50; it2++) {
      double mi2 = (hi2+lo2)/2;
      if(solve(mi1, mi2).second.second > b) lo2 = mi2;
      else hi2 = mi2;
    }
    if(solve(mi1, hi2).second.first > a) lo1 = mi1;
    else hi1 = mi1;
  }
  cout << solve(hi1, hi2).first + a*hi1 + b*hi2 << '\n';
}