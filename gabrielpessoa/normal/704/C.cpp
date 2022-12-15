#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n, m;
vector<int> g[ms];
vector<int> ele[ms];
int used[ms];
int order[ms];
int prev1[ms], prev2[ms];
int goprev1[ms], goprev2[ms];
int dp[ms][2][2][2];

int solve(int pp, int b1, int b2, int b) {
  if(pp == n) {
    return b;
  }
  int &ans = dp[pp][b1][b2][b];
  if(~ans) return ans;
  ans = 0;
  int p = order[pp];
  int go1 = 0, go2 = 0;
  int e1 = ele[p][0];
  int e2 = ele[p].size() > 1 ? ele[p][1] : 0;
  for(int i = 0; i < 2; i++) {
    int k1 = i;
    if(e1 < 0) k1 = !i;
    if(prev1[p] == abs(e1)) {
      if(b1 != k1) continue;
    }
    if(prev2[p] == abs(e1)) {
      if(b2 != k1) continue;
    }
    for(int j = 0; j < 2; j++) {
      int k2 = j;
      if(e2 < 0) k2 = !j;
      if(abs(e2) == abs(e1) && k1 != k2) continue;
      if(e2 && prev1[p] == abs(e2)) {
        if(b1 != k2) continue;
      }
      if(e2 && prev2[p] == abs(e2)) {
        if(b2 != k2) continue;
      }
      if(!e2 && j) continue;
      if(goprev1[p] == abs(e1)) {
        go1 = k1;
      }
      if(goprev2[p] == abs(e1)) {
        go2 = k1;
      }
      if(goprev1[p] == abs(e2)) {
        go1 = k2;
      }
      if(goprev2[p] == abs(e2)) {
        go2 = k2;
      }
      if(goprev1[p] == prev2[p]) {
        go1 = b2;
      }
      ans = (ans + solve(pp+1, go1, go2, b ^ (i | j))) % mod;
      go1 = 0;
      go2 = 0;
    }
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> m;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while(k--) {
      int x;
      cin >> x;
      ele[i].emplace_back(x);
      g[abs(x)].emplace_back(i);
    }
  }
  int p1 = 0, p2 = 0;
  int idx = 0;
  for(int i = 0; i < n; i++) {
    if(used[i]) continue;
    int p = i;
    do {
      order[idx++] = p;
      prev1[p] = p1; prev2[p] = p2;
      used[p] = 1;
      p1 = p2;
      p2 = 0;
      for(int a : ele[p]) {
        if(p1 == abs(a)) p1 = 0;
      }
      for(int a : ele[p]) {
        for(int b : g[abs(a)]) {
          if(!used[b]) {
            if(p1 == 0) p1 = abs(a);
            else p2 = abs(a);
            break;
          }
        }
      }
      goprev1[p] = p1;
      goprev2[p] = p2;
      //cout << p << ' ' << goprev1[p] << ' ' << goprev2[p] << ' ' << prev1[p] << ' '<< prev2[p] << '\n';
      p = -1;
      for(int a : g[p1]) {
        if(!used[a]) p = a;
      }
    } while(p != -1);
  }
  int ans = solve(0, 0, 0, 0);
  //cout << ans << '\n';
  for(int i = 1; i <= m; i++) {
    if(g[i].size() == 0) {
      ans = (ans+ans) % mod;
    }
  }
  cout << ans << '\n';
}