#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int N, A[50], B[51];
int dp[50][2];

int rec1(int);

int rec2(int idx)
{
  if(idx == N) return (0);
  if(~dp[idx][1]) return (dp[idx][0]);
  int ret = -INF;
  ret = max(ret, B[idx + 1] - rec1(idx + 1) + A[idx]);
  ret = max(ret, rec2(idx + 1));
  return (dp[idx][1] = ret);
}

int rec1(int idx)
{
  if(idx == N) return (0);
  if(~dp[idx][0]) return (dp[idx][0]);
  int ret = -INF;
  ret = max(ret, B[idx + 1] - rec2(idx + 1) + A[idx]);
  ret = max(ret, rec1(idx + 1));
  return (dp[idx][0] = ret);
}

int main()
{
  memset(dp, -1, sizeof(dp));

  cin >> N;
  int all = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    all += A[i];
  }
  for(int i = N - 1; i >= 0; i--) {
    B[i] = A[i] + B[i + 1];
  }

  cout << all - rec1(0) << " " << rec1(0) << endl;
}