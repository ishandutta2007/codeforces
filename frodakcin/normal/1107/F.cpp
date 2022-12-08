#include <iostream>
#include <cstdio>

#include <array>
#include <algorithm>

using namespace std;

template<class T> void mx(T& a, const T& b) {if(a < b) a = b;}

const int MN = 5e2 + 100;

using ll = long long;
#define tl(X) static_cast<ll>(X)
int N;

ll f, v;
ll dp[MN];
using i3 = array<int, 3>;
i3 c[MN];

int main() {
  scanf("%d", &N);
  for(int i = 0;i < N;i++) scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2]);
  sort(c, c + N, [](i3 a, i3 b){return a[1] > b[1];});
  
  for(int i = 0;i <= N;i++) dp[i] = 0LL;
  
  for(int i = 0;i < N;i++) {
    v = c[i][0] - 1LL*c[i][1]*c[i][2];
    if(v > 0LL) for(int j = c[i][2] + 1;j <= N;j++) dp[j] += v;
    for(int j = min(c[i][2] - 1, N - 1);j >= 0;j--) mx(dp[j+1], max(dp[j+1] + v, dp[j] + c[i][0] - 1LL*j*c[i][1]));
    if(v > 0LL) dp[0] += v;
  }
  
  f = 0LL;
  for(int i = 0;i <= N;i++) mx(f, dp[i]);
  printf("%lld\n", f);
  
  return 0;
}