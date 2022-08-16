#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 59;

int main()
{
  int N, M, C[1002][1002] = {{}};
  scanf("%d %d", &N, &M);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) scanf("%d", &C[i][j]);
  }

  // sum[(i,j)=(0,0)..(N,M)] C[i][j]*((x-i)^2+(y-j)^2)
  // sum[i=0..n] C[i][j]*(x-i)^2 + sum[j=0..m] C[i][j]*(y-j)^2

  ++N, ++M;
  ++N, ++M;
  vector< int64 > latte(N, 0LL), malta(M, 0LL);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      latte[i] += C[i][j];
      malta[j] += C[i][j];
    }
  }

  pair< int64, int64 > ret1 = {INF, INF}, ret2 = {INF, INF};
  for(int i = 0; i < N; i++) {
    int64 beet = 0LL;
    for(int j = 0; j < N; j++) beet += 1LL * latte[j] * (i * 4 - j * 4 + 2) * (i * 4 - j * 4 + 2);
    ret1 = min(ret1, {beet, i});
  }
  for(int i = 0; i < M; i++) {
    int64 beet = 0LL;
    for(int j = 0; j < M; j++) beet += 1LL * malta[j] * (i * 4 - j * 4 + 2) * (i * 4 - j * 4 + 2);
    ret2 = min(ret2, {beet, i});
  }
  cout << ret1.first + ret2.first << endl;
  cout << ret1.second  << " " << ret2.second << endl;
}