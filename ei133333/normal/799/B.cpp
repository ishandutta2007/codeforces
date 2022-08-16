#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair< int64, int > Pi;

int main()
{
  int64 N, P[200000], A[200000], B[200000], M;

  scanf("%lld", &N);
  for(int i = 0; i < N; i++) scanf("%lld", &P[i]);
  for(int i = 0; i < N; i++) scanf("%lld", &A[i]), --A[i];
  for(int i = 0; i < N; i++) scanf("%lld", &B[i]), --B[i];

  priority_queue< Pi, vector< Pi >, greater< Pi > > que[3];
  vector< bool > used(N, false);
  for(int i = 0; i < N; i++) que[A[i]].emplace(P[i], i);
  for(int i = 0; i < N; i++) que[B[i]].emplace(P[i], i);


  scanf("%lld", &M);
  for(int i = 0; i < M; i++) {
    int S;
    scanf("%d", &S);

    auto &beet = que[--S];
    while(!beet.empty() && used[beet.top().second]) beet.pop();
    if(beet.empty()) {
      printf("-1 ");
    } else {
      printf("%lld ", beet.top().first);
      used[beet.top().second] = true;
      beet.pop();
    }
  }
  puts("");
}