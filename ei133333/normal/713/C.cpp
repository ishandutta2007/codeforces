#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

#define int long long

const int inf = (int)1e18;
int N, M, A[3048];
int dp[3048][3048];
int dp2[3048][3048];
int ans;
int unzip[3048];

signed main(){
  scanf("%lld", &N);
  vector<int> tmp;
  for(int i = 0; i < N; i++){
    scanf("%lld", A+i);
    A[i] -= i;
    tmp.push_back(A[i]);
  }
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  M = tmp.size();
  for(int i = 0; i < M; i++) unzip[i] = tmp[i];

  for(int i = 0; i < M; i++){
    dp[0][i] = abs(A[0] - unzip[i]);
    dp2[0][i] = dp[0][i];
    if(i) dp2[0][i] = min(dp2[0][i], dp2[0][i-1]);
  }
  for(int i = 1; i < N; i++)
    for(int j = 0; j < M; j++){
      dp[i][j] = dp2[i-1][j] + abs(A[i] - unzip[j]);
      dp2[i][j] = dp[i][j];
      if(j) dp2[i][j] = min(dp2[i][j], dp2[i][j-1]);
    }
  ans = dp2[N-1][M-1];
  printf("%lld\n", ans);
  return 0;
}