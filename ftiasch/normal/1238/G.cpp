#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, cap, cur;
    scanf("%d%d%d%d", &n, &m, &cap, &cur);
    std::vector<std::pair<int, std::pair<int, int>>> friends(n);
    for (int i = 0; i < n; ++i) {
      int t, a, w;
      scanf("%d%d%d", &t, &a, &w);
      friends[i] = {t, {a, w}};
    }
    std::sort(friends.begin(), friends.end());
    std::map<int, int> tank;
    tank[0] = cur;
    long long result = 0;
    auto next_friend = friends.begin();
    for (int day = 0; day < m && ~result;) {
      while (next_friend != friends.end() && next_friend->first == day) {
        auto [a, w] = (next_friend++)->second;
        cur += a;
        tank[w] += a;
        while (cur > cap) {
          auto worst = std::prev(tank.end());
          int t = std::min(cur - cap, worst->second);
          cur -= t;
          worst->second -= t;
          if (!worst->second) {
            tank.erase(worst);
          }
        }
      }
      if (tank.empty()) {
        result = -1;
      } else {
        auto best = tank.begin();
        int next_day = std::min(m, day + best->second);
        if (next_friend != friends.end()) {
          next_day = std::min(next_day, next_friend->first);
        }
        int len = next_day - day;
        result += 1LL * best->first * len;
        cur -= len;
        best->second -= len;
        if (!best->second) {
          tank.erase(best);
        }
        day = next_day;
      }
    }
    printf("%lld\n", result);
  }
}