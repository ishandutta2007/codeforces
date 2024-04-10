#include <bits/stdc++.h>

const int N = 200000;

int n;
std::pair<int, int> a[N];

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i].first);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i].second);
    }
    std::sort(a, a + n);
    long long result = 0, sum = 0;
    std::priority_queue<int> pq;
    int x = 0, i = 0;
    while (!pq.empty() || i < n) {
      if (pq.empty()) {
        x = a[i].first;
      }
      while (i < n && a[i].first == x) {
        sum += a[i].second;
        pq.push(a[i++].second);
      }
      sum -= pq.top();
      pq.pop();
      result += sum;
      x++;
    }
    printf("%lld\n", result);
  }
}