#include<bits/stdc++.h>

using namespace std;

int N, K[2], S[2][7000];
int deg[2][7000], dp[2][7000];

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < 2; i++) {
    scanf("%d", &K[i]);
    for(int j = 0; j < K[i]; j++) {
      scanf("%d", &S[i][j]);
    }
  }

  queue< tuple< int, int > > que;
  memset(dp, -1, sizeof(dp));
  for(int j = 0; j < 2; j++) {
    que.emplace(j, 0);
    dp[j][0] = 0;
  }
  while(!que.empty()) {
    int player, number;
    tie(player, number) = que.front();
    que.pop();

    if(dp[player][number] == 0) {
      for(int i = 0; i < K[player ^ 1]; i++) {
        int pre = (number - S[player ^ 1][i] + N) % N;
        if(~dp[player ^ 1][pre]) continue;
        dp[player ^ 1][pre] = 1;
        que.emplace(player ^ 1, pre);
      }
    } else {
      for(int i = 0; i < K[player ^ 1]; i++) {
        int pre = (number - S[player ^ 1][i] + N) % N;
        if(~dp[player ^ 1][pre]) continue;
        if(++deg[player ^ 1][pre] == K[player ^ 1]) {
          dp[player ^ 1][pre] = 0;
          que.emplace(player ^ 1, pre);
        }
      }
    }
  }

  for(int i = 0; i < 2; i++) {
    for(int j = 1; j < N; j++) {
      if(dp[i][j] == 0) printf("Lose ");
      else if(dp[i][j] == 1) printf("Win ");
      else printf("Loop ");
    }
    cout << endl;
  }
}