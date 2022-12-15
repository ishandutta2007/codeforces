#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

int T;
ii dp[60][2][2];
int vis[60][2][2];

ii solve(int bit, int loBound, int hiBound, int l, int r) {
  if(bit < 0) return {0, 0};
  ii &ans = dp[bit][loBound][hiBound];
  if(vis[bit][loBound][hiBound] == T) return ans;
  vis[bit][loBound][hiBound] = T;
  ans = {1, 0};
  if(!hiBound || (r & (1ll << bit))) {
    ii temp = solve(bit - 1, loBound && (l & (1ll << bit)), hiBound, l, r);
    temp.first--;
    temp.second += (1ll << bit);
    ans = min(ans, temp);
  }
  if(!loBound || !(l & (1ll << bit))) {
    ii temp = solve(bit - 1, loBound, hiBound && !(r & (1ll << bit)), l, r);
    ans = min(ans, temp);
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(T = 1; T <= n; T++) {
    int l, r;
    cin >> l >> r;
    cout << solve(59, 1, 1, l, r).second << '\n';
  }
}