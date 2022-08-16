#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

// 

int main() {
  int N, M, A[100000], X[100000];
  map< int, int > mp;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &X[i]);
    mp[A[i]] = X[i];
  }
  int64 ret = 0;
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    ret += max(mp[a], b);
    mp[a] = 0;
  }
  for(auto& p : mp) ret += p.second;
  printf("%lld\n", ret);
}