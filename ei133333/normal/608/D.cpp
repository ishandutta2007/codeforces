#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int N, c[500];
int dp[500][500];

int rec(int left, int right)
{
  if(~dp[left][right]) return(dp[left][right]);
  int ret = INF / 2;
  if(c[left] == c[right]) {
    if(left + 1 >= right) return(1);
    ret = rec(left + 1, right - 1);
  }
  for(int mid = left; mid < right; mid++) {
    ret = min(ret, rec(left, mid) + rec(mid + 1, right));
  }
  return(dp[left][right] = ret);
}

int main()
{
  memset(dp, -1, sizeof(dp));

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> c[i];
  }
  cout << rec(0, N - 1) << endl;
}