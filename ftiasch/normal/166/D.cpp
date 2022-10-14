#include <bits/stdc++.h>

#define SIZE first
#define PRICE second

const int N = 100001;

int n, m, count, visit[N], match[N];
std::pair<int, int> shoes[N], customers[N];
std::vector<int> graph[N];

bool find(int u) {
  if (visit[u] == count) {
    return false;
  }
  visit[u] = count;
  for (int v : graph[u]) {
    if (!match[v] || find(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  std::vector<int> order(n);
  std::map<int, int> sizes;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &shoes[i].PRICE, &shoes[i].SIZE);
    order[i - 1] = i;
    sizes[shoes[i].SIZE] = i;
  }
  std::sort(order.begin(), order.end(),
            [&](int i, int j) { return shoes[i].PRICE > shoes[j].PRICE; });
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &customers[i].PRICE, &customers[i].SIZE);
    int j = sizes[customers[i].SIZE];
    if (j && shoes[j].PRICE <= customers[i].PRICE) {
      graph[j].push_back(i);
    }
    j = sizes[customers[i].SIZE + 1];
    if (j && shoes[j].PRICE <= customers[i].PRICE) {
      graph[j].push_back(i);
    }
  }
  long long result = 0;
  memset(visit, -1, sizeof(visit));
  for (int i : order) {
    if (find(i)) {
      count++;
      result += shoes[i].PRICE;
    }
  }
  printf("%lld\n%d\n", result, count);
  for (int i = 1; i <= m; ++i) {
    if (match[i]) {
      printf("%d %d\n", i, match[i]);
    }
  }
}