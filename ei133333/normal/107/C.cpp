#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 N, Y, M;
int bad[16];
int64 dp[1 << 16];
bool graph[16][16];

int64 rec(int bit)
{
  if(~dp[bit]) return (dp[bit]);
  if(bit == (1 << N) - 1) return (dp[bit] = 1);
  int64 ret = 0, dep = __builtin_popcount(bit);
  for(int i = 0; i < N; i++) {
    if((bit >> i) & 1) continue;
    if(bad[i] & bit) continue;
    if(!graph[i][dep]) continue;
    ret += rec(bit | (1 << i));
  }
  return (dp[bit] = ret);
}


int main()
{
  cin >> N >> Y >> M;
  Y -= 2001;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    bad[--a] |= 1 << --b;
  }
  memset(graph, true, sizeof(graph));
  memset(dp, -1, sizeof(dp));
  if(Y >= rec(0)) {
    cout << "The times have changed" << endl;
  } else {
    for(int i = 0; i < N; i++) {
      int low = 0, high = N;
      while(high - low > 1) {
        int mid = (low + high) >> 1;
        for(int j = 0; j < N; j++) graph[i][j] = j < mid;
        memset(dp, -1, sizeof(dp));
        if(Y < rec(0)) high = mid;
        else low = mid;
      }
      for(int j = 0; j < N; j++) graph[i][j] = j < low;
      memset(dp, -1, sizeof(dp));
      Y -= rec(0);
      for(int j = 0; j < N; j++) graph[i][j] = j == low;

      cout << low + 1 << " ";
    }

    cout << endl;
  }

}