#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int N; cin >> N;
  ll weights[5] = {0, 1, 1, 1, 0}; cin >> weights[2];
  ll dp[5] = {0,0,0,0,0};
  for (int i = 0; i < N; i++) {
    ll v; cin >> v;
    for (int z = 0; z < 5; z++) dp[z] += weights[z] * v;
    for (int z = 0; z+1 < 5; z++) dp[z+1] = max(dp[z+1], dp[z]);
  }
  cout << dp[4] << '\n';
}