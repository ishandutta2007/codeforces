#include <bits/stdc++.h>

using namespace std;


int main(){
  int n, m;
  scanf("%d %d",&n,&m);
  int num_votes[105][105];
  int city_winner[105];
  int num_wins[105];
  for (int i = 0; i < m; i++) {
    int best = 0;
    for (int j = 0; j < n; j++) {
      scanf("%d",&num_votes[i][j]);
      if (num_votes[i][j] > best) {
        city_winner[i] = j;
        best = num_votes[i][j];
      }
    }
    num_wins[city_winner[i]]++;
  }
  
  int winner = 0;
  int best = 0;
  for (int i = 0; i < n; i++) {
    if (num_wins[i] > best) {
      best = num_wins[i];
      winner = i;
    }
  }
  
  printf("%d\n",winner+1);
}