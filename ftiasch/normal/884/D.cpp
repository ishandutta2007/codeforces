#line 1 "sol.cpp"
#include <bits/stdc++.h>

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
  int n;
  scanf("%d", &n);
  PQ<long long> pq;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    pq.emplace(a);
  }
  while (~pq.size() & 1) {
    pq.emplace(0);
  }
  long long result = 0;
  while (pq.size() > 1) {
    long long sum = 0;
    for (int _ = 0; _ < 3; ++_) {
        sum += pq.top();
        pq.pop();
    }
    pq.emplace(sum);
    result += sum;
  }
  printf("%lld\n", result);
}