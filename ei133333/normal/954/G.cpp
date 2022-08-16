#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {

  int64 N, R, K, A[500001];
  int64 preadd[500001];

  scanf("%lld %lld %lld", &N, &R, &K);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &A[i + 1]);
    A[i + 1] += A[i];
  }

  auto check = [&](int64 v) {
    memset(preadd, 0, sizeof(preadd));
    int64 pending = 0;
    int64 used = 0;
    for(int64 i = 0; i < N; i++) {
      int64 hightarget = min(i + R, N - 1);
      int64 lowtarget = max(0LL, i - R);
      int64 currsum = A[hightarget + 1] - A[lowtarget];
      currsum += pending;
      if(currsum < v) {
        int64 rest = v - currsum;
        preadd[hightarget] += rest;
        pending += rest;
        used += rest;
        if(used > K) return false;
      }
      pending -= preadd[lowtarget];
    }
    return true;
  };
  int64 ok = 0, ng = 1LL << 61;
  while(ng - ok > 1) {
    int64 mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  printf("%lld\n", ok);
}