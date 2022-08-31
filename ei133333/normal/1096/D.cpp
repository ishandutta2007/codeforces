#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 58;

int N;
string S;
int A[100000];
int64 dp[100000][1 << 3];

int64 rec(int idx, int bit) {
  if(idx == N) return 0;
  if(~dp[idx][bit]) return dp[idx][bit];
  int64 ret = INF;

  int nxtbit = bit;
  if(S[idx] == 'h') nxtbit |= 1;
  if((bit & 1) && S[idx] == 'a') nxtbit |= 2;
  if((bit & 2) && S[idx] == 'r') nxtbit |= 4;
  if((bit & 4) && S[idx] == 'd') nxtbit |= 8;
  if(!(nxtbit & 8)) {
    ret = min(ret, rec(idx + 1, nxtbit));
  }

  ret = min(ret, rec(idx + 1, bit) + A[idx]);
  return dp[idx][bit] = ret;
}

int main() {
  cin >> N;
  cin >> S;
  for(int i = 0; i < N; i++) cin >> A[i];
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << endl;
}