#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;
const int mod = 1e9 + 7;

int main()
{
  int N, A[100000];
  int64 K;

  scanf("%d %lld", &N, &K);
  int64 all = 0;
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    all += A[i];
  }

  if(all < K) {
    cout << -1 << endl;
    return (0);
  }

  auto check = [&](int times)
  {
    int64 ret = 0;
    for(int i = 0; i < N; i++) {
      ret += min(times, A[i]);
    }
    return (ret <= K);
  };

  int ok = 0, ng = 1 << 30;
  while(ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }

  queue< int > que;
  for(int i = 0; i < N; i++) {
    K -= min(ok, A[i]);
    A[i] -= min(ok, A[i]);
    if(A[i] > 0) que.emplace(i);
  }

  while(K > 0) {
    int p = que.front();
    que.pop();
    --A[p];
    --K;
    if(A[p] > 0) que.push(p);
  }

  while(!que.empty()) {
    int p = que.front();
    que.pop();
    cout << p + 1 << " ";
  }
  cout << endl;
}