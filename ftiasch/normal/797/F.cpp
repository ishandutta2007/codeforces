#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> events(n + m);
  for (int i = 0, p; i < n; ++i) {
    scanf("%d", &p);
    events[i] = {p, -1};
  }
  int sum_c = 0;
  for (int i = 0, p, c; i < m; ++i) {
    scanf("%d%d", &p, &c);
    events[n + i] = {p, c};
    sum_c += c;
  }
  if (sum_c < n) {
    puts("-1");
    return 0;
  }
  std::sort(events.begin(), events.end());
  std::multiset<Long> mices;
  std::map<Long, int> holes;
  Long result = 0;
  holes[3'000'000'001LL] = n;
  for (auto [x, c] : events) {
    if (~c) {
      while (c && !mices.empty() && x + *mices.begin() < 0) {
        c--;
        auto iterator = mices.begin();
        Long match = x + *iterator;
        result += match;
        holes[-match - x]++;
        mices.erase(iterator);
      }
      if (c) {
        holes[-x] += c;
      }
    } else {
      auto iterator = holes.begin();
      Long match = x + iterator->first;
      result += match;
      mices.insert(-match - x);
      iterator->second--;
      if (!iterator->second) {
        holes.erase(iterator);
      }
    }
  }
  printf("%lld\n", result);
}