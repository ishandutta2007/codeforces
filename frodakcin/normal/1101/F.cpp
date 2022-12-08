#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 401;

template<class T> void rph(T& a, const T& b) {if(a < b) a = b;}

using ll = long long;
#define tl(X) static_cast<ll>(X)

int N, M;
int a[MN];
int dp[MN][MN][MN];

ll V;
int s, f, c, r;

void wk() {
  scanf("%d%d%d%d", &s, &f, &c, &r);
  rph(V, tl(c) * dp[s][f][r]);
}

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 1;i <= N;i++) scanf("%d", a + i);
  
  for(int i = 0;i <= N;i++) for(int j = 0;j <= N;j++) for(int k = 0;k <= N;k++) dp[i][j][k] = -1;
  for(int i = 1;i <= N;i++) for(int j = i;j <= N;j++) dp[i][j][0] = a[j] - a[i];
  for(int i = 0;i <= N;i++) for(int j = 0;j <= N;j++) dp[i][i][j] = 0;
  for(int i = 1;i <= N;i++) {
    for(int j = i + 1;j <= N;j++) {
      for(int k = 1, l = i + 1;k <= N;k++) {
        for(;l < j and dp[i][l][k-1] < a[j] - a[l];l++);   //partition into i..l and l..j. as k++, l++
        dp[i][j][k] = min(max(dp[i][l-1][k-1], a[j] - a[l-1]), max(dp[i][l][k-1], a[j] - a[l]));
      }
    }
  }
  
  V = 0LL;
  for(int i = 0;i < M;i++) wk();
  printf("%lld\n", V);
  
  return 0;
}