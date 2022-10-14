#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Item {
  int key() const { return std::max(hp - dmg, 0); }

  int hp, dmg;
};

bool operator<(const Item &a, const Item &b) { return a.key() > b.key(); }

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  std::vector<Item> items(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &items[i].hp, &items[i].dmg);
  }
  std::sort(items.begin(), items.end());
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += items[i].dmg;
    if (i < b) {
      sum += items[i].key();
    }
  }
  long long result = sum;
  if (b) {
    for (int i = 0; i < n; ++i) {
      if (i < b) {
        result =
            std::max(result, sum - items[i].dmg - items[i].key() +
                                 (static_cast<long long>(items[i].hp) << a));
      } else {
        result =
            std::max(result, sum - items[i].dmg - items[b - 1].key() +
                                 (static_cast<long long>(items[i].hp) << a));
      }
    }
  }
  printf("%lld\n", result);
}