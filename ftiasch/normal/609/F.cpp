#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> position(n), eaten(n);
  std::vector<long long> length(n);
  for (int i = 0, l; i < n; ++i) {
    scanf("%d%d", &position[i], &l);
    length[i] = l;
  }
  std::map<long long, int> frogs;
  auto add_frog = [&](int i) {
    long long r = position[i] + length[i];
    while (true) {
      auto iterator = frogs.upper_bound(r);
      if (iterator == frogs.begin()) {
        break;
      }
      iterator--;
      if (position[iterator->second] < position[i]) {
        break;
      }
      frogs.erase(iterator);
    }
    frogs[r] = i;
  };
  {
    std::vector<std::pair<int, int>> order(n);
    for (int i = 0; i < n; ++i) {
      order[i] = {length[i], i};
    }
    std::sort(order.begin(), order.end());
    for (auto [_, i] : order) {
      add_frog(i);
    }
  }
  std::multimap<int, long long> pending;
  while (m--) {
    int x, size;
    scanf("%d%d", &x, &size);
    auto iterator = frogs.lower_bound(x);
    if (iterator != frogs.end() && position[iterator->second] <= x) {
      int i = iterator->second;
      eaten[i]++;
      length[i] += size;
      frogs.erase(iterator);
      while (true) {
        auto iterator = pending.lower_bound(position[i]);
        if (iterator == pending.end() ||
            position[i] + length[i] < iterator->first) {
          break;
        }
        eaten[i]++;
        length[i] += iterator->second;
        pending.erase(iterator);
      }
      add_frog(i);
    } else {
      pending.emplace(x, size);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %lld\n", eaten[i], length[i]);
  }
}