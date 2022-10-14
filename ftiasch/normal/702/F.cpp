#include <bits/stdc++.h>

const int N = 200'000;
const int L = 30;

int n, m, result[N];
std::pair<int, int> tshirt[N];

using Set = std::set<std::pair<int, int>>;

struct Level {
  void sub(int lb, int c) {
    if (!set.empty()) {
      if (c <= set.begin()->first - total_c) {
        total++;
        total_c += c;
        while (!set.empty() && set.begin()->first - total_c < lb) {
          remove(0, set.begin());
        }
      } else {
        while (!set.empty() && c <= set.rbegin()->first - total_c) {
          auto iterator = std::prev(set.end());
          result[iterator->second]++;
          remove(c, iterator);
        }
      }
    }
  }

  void remove(int c, Set::iterator iterator);

  int total, total_c;
  Set set;
} level[L + 1];

int level_id(int a) { return a == 0 ? 0 : 32 - __builtin_clz(a); }

void add(int b, int i) {
  //   std::cerr << "add " << KV(b) << " " << KV(i) << " " << level_id(b)
  //             << std::endl;
  auto &l = level[level_id(b)];
  result[i] -= l.total;
  l.set.emplace(b + l.total_c, i);
}

void Level::remove(int c, Set::iterator iterator) {
  auto [b, i] = *iterator;
  set.erase(iterator);
  result[i] += total;
  add(b - c - total_c, i);
}

int main() {
  scanf("%d", &n);
  for (int i = 0, c, q; i < n; ++i) {
    scanf("%d%d", &c, &q);
    tshirt[i] = {-q, c};
  }
  std::sort(tshirt, tshirt + n);
  scanf("%d", &m);
  for (int i = 0, b; i < m; ++i) {
    scanf("%d", &b);
    add(b, i);
  }
  for (int i = 0; i < n; ++i) {
    int c = tshirt[i].second;
    // std::cerr << KV(c) << std::endl;
    for (int lid = 1; lid <= L; ++lid) {
      level[lid].sub(1 << (lid - 1), c);
    }
  }
  for (int lid = 1; lid <= L; ++lid) {
    for (auto [_, i] : level[lid].set) {
      result[i] += level[lid].total;
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == m]);
  }
}