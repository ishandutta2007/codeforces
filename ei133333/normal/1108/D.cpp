#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;
string U = "RGB";


int N;
string S;
int dp[200000][4];

int rec(int idx, int pv) {
  if(idx == N) return 0;
  if(~dp[idx][pv]) return dp[idx][pv];
  int ret = INF;
  for(int i = 0; i < 3; i++) {
    if(i == pv) continue;
    ret = min(ret, rec(idx + 1, i) + (S[idx] != U[i]));
  }
  return dp[idx][pv] = ret;
}

void rec2(int idx, int pv) {
  if(idx == N) return;
  int ret = dp[idx][pv];
  for(int i = 0; i < 3; i++) {
    if(i == pv) continue;
    if(rec(idx + 1, i) + (S[idx] != U[i]) == ret) {
      cout << U[i];
      rec2(idx + 1, i);
      return;
    }
  }
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> N;
  cin >> S;
  cout << rec(0, 3)<< endl;
  rec2(0, 3);
  cout << endl;
}