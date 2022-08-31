#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair< int64, int > Pi;

int main()
{
  int N, K, X;
  int64 A[200000];
  bool sign = true;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;

  scanf("%d %d %d", &N, &K, &X);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
    que.emplace(max(A[i], -A[i]), i);
    sign ^= A[i] < 0;
  }

  while(K--) {
    auto p = que.top();
    que.pop();
    if(A[p.second] < 0) sign ^= 1;
    if(sign) A[p.second] -= X;
    else A[p.second] += X;
    if(A[p.second] < 0) sign ^= 1;
    que.emplace(max(A[p.second], -A[p.second]), p.second);
  }

  for(int i = 0; i < N; i++) {
    printf("%lld ", A[i]);
  }
}