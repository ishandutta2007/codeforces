#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 59;

int main()
{
  int N, A[100000];
  int64 dp[3] = {};
  cin >> N;
  for(int i = 1; i < N; i++) cin >> A[i];

  int64 ret = 0;
  for(int i = 1; i < N; i++) {
    int64 nextdp[3];
    nextdp[0] = max(dp[0] + A[i] / 2 * 2, dp[1] + A[i]); // ->
    nextdp[1] = max(dp[1], dp[2]) + (A[i] - 1) / 2 * 2 + 1; // <->
    nextdp[2] = dp[2] + A[i] / 2 * 2; // <-
    if(A[i] == 1) nextdp[0] = nextdp[1], nextdp[2] = 0;
    swap(dp, nextdp);
    ret = max({ret, dp[0], dp[1], dp[2]});
  }
  cout << ret << endl;
}