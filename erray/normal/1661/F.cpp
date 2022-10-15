// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  A.insert(A.begin(), 0);
  ++N;
  long long M;
  cin >> M;

  auto F = [&](long long x, long long y) {
    long long d = x / y;
    long long l = x % y;
    return (y - l) * (d * d) + l * (d + 1) * (d + 1);
  };

  auto G = [&](int s, long long l) {
   int low = 0, high = s - 1;
   while (low < high) {
     int mid = (low + high) >> 1;
     if (F(s, mid + 1) - F(s, mid + 2) >= l) {
       low = mid + 1;
     } else {
       high = mid;
     }
   }
   return low; 
 };


  auto Get = [&](long long x) -> pair<long long, int> {
    long long cost = 0;
    int used = 0;
    for (int i = 0; i < N - 1; ++i) { 
      int s = A[i + 1] - A[i];
      //debug(s, x + 1, G(s, x + 1));
      int add = G(s, x);
      used += add;
      cost += F(s, add + 1);
    }
    return pair{cost, used};
  };

  long long low = 1, high = (long long) 1e18;
  while (low < high) {
    long long mid = (low + high + 1) >> 1;
    auto r = Get(mid);
    debug(low, high, mid, r);
    if (r.first <= M) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  auto[c, ans] = Get(low);
  ans -= (M - c) / low;
  cout << ans << '\n';
}