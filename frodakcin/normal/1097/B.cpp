#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MN = 15 + 5;
const int MV = MN * 180 * 5;

bool dp[2][MV<<1], c;
int N;

int main() {
  scanf("%d", &N);
  c = 0;
  
  for(int i = 0;i < MV;i++) dp[not c][i] = false;
  dp[not c][MV] = true;
  for(int i = 0, a;i < N;i++, c = not c) {
    scanf("%d", &a);
    for(int j = 0;j < MV<<1;j++) {
      dp[c][j] = (j - a >= 0 ? dp[not c][j - a] : false) or (j + 1 < MV<<1 ? dp[not c][j + a] : false);
    }
  }
  c = not c;
  
  bool f = 0;
  
  for(int i = MV;i < MV<<1;i+=360) f |= dp[c][i];
  for(int i = MV;i >= 0;i -= 360) f |= dp[c][i];
  
  if(f) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}