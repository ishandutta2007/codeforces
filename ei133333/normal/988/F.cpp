#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 55;

int A, N, M;
int64 X[2002];
bool v[2002] = {};
int64 dp[2001][2002];

int64 rec(int pos, int umbrella) {
  if(pos == A) return 0;
  if(~dp[pos][umbrella]) return dp[pos][umbrella];
  int64 ret = INF;
  if(X[pos] < INF && umbrella != pos) {
    ret = min(ret, rec(pos, pos));
  }
  if(!v[pos]) {
    ret = min(ret, rec(pos + 1, umbrella) + X[umbrella]);
    ret = min(ret, rec(pos + 1, 2001));
  } else {
    if(umbrella != 2001) {
      ret = min(ret, rec(pos + 1, umbrella) + X[umbrella]);
    }
  }
  return dp[pos][umbrella] = ret;
}

int main() {
  fill_n(X, 2001, INF);
  memset(dp, -1, sizeof(dp));

  cin >> A >> N >> M;
  for(int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    for(int j = l; j < r; j++) v[j] = true;
  }

  for(int i = 0; i < M; i++) {
    int64 a, b;
    cin >> a >> b;
    X[a] = min(X[a], b);
  }
  X[2001] = 0;
  auto ret = rec(0, 2001);
  if(ret >= INF) cout << -1 << endl;
  else cout << ret << endl;
}