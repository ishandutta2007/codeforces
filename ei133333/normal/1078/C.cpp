#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

int N;
vector< int > g[300000];
int64 dp[300000][3];
int64 pre[300000], nxt[300000];

void rec(int idx, int par) {
  for(auto &to : g[idx]) {
    if(to == par) continue;
    rec(to, idx);
  }
  int64 ways = 1;
  for(int i = 0; i < g[idx].size(); i++) {
    int to = g[idx][i];
    if(to == par) {
      pre[i] = ways;
      continue;
    }
    (ways *= (dp[to][1] * 2 % mod + dp[to][2] % mod) % mod) %= mod;
    pre[i] = ways;
  }
  ways = 1;
  for(int i = (int) g[idx].size() - 1; i >= 0; i--) {
    int to = g[idx][i];
    if(to == par) {
      nxt[i] = ways;
      continue;
    }
    (ways *= (dp[to][1] * 2 % mod + dp[to][2] % mod) % mod) %= mod;
    nxt[i] = ways;
  }

  for(int i = 0; i < g[idx].size(); i++) {
    int to = g[idx][i];
    if(to == par) continue;
    int64 add = 1LL;
    if(i > 0) (add *= pre[i - 1]) %= mod;
    if(i + 1 < g[idx].size()) (add *= nxt[i + 1]) %= mod;
    (dp[idx][1] += (dp[to][0] + dp[to][2]) % mod * add) %= mod;
  }

  // 
  ways = 1;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    (ways *= (dp[to][1] + dp[to][2]) % mod) %= mod;
  }
  dp[idx][2] = ways;


  ways = 1;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    (ways *= (dp[to][1] * 2 + dp[to][2] % mod) % mod) %= mod;
  }
  dp[idx][0] = ways;
  // 
  ways = 1;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    (ways *= (dp[to][1] + dp[to][2]) % mod) %= mod;
  }
  (dp[idx][0] += mod - ways) %= mod;
}


int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  rec(0, -1);
  cout << (dp[0][2] + dp[0][1]) % mod << endl;
}