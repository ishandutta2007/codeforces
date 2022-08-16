#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int INF = 1 << 30;

int N, M;
string S[18];
int latte[18], malta[18];
int dp[18][110];

int rec(int floor, int pos)
{
  if(floor + 1 == N) {
    if(pos == 0) return (malta[floor]);
    else return (M + 1 - latte[floor]);
  }
  int &memo = dp[floor][pos];
  if(~memo) return (memo);
  int ret = INF;
  if(pos == 0) {
    ret = min(ret, rec(floor + 1, M + 1) + M + 2);
    ret = min(ret, rec(floor + 1, 0) + malta[floor] * 2 + 1);
  } else {
    ret = min(ret, rec(floor + 1, 0) + M + 2);
    ret = min(ret, rec(floor + 1, M + 1) + (M + 1 - latte[floor]) * 2 + 1);
  }
  return (memo = ret);
}

int main()
{


  cin >> N >> M;
  fill_n(latte, 18, M + 1);
  int height = 0;

  for(int i = 0; i < N; i++) cin >> S[N - i - 1];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < S[i].size(); j++) {
      if(S[i][j] == '1') {
        latte[i] = min(latte[i], j);
        malta[i] = max(malta[i], j);
        height = i;
      }
    }
  }
  N = height + 1;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << endl;
}