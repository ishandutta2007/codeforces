#include <bits/stdc++.h>
#include <ios>
#include <limits>
#include <regex>

const int MOD = 1e9 + 7;

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

using Stat = std::array<int, 4>;

struct Sum {
  Sum(int count = 0, int ways = 1) : count(count), ways(ways) {}

  Sum(const Stat &stat) {
    long long dp1 = stat[1] + stat[3];
    long long dp2 = stat[2] + stat[3];
    long long dp3 =
        stat[1] * stat[2] + (stat[1] + stat[2] + stat[3] - 1) * stat[3];
    if (dp3) {
      count = 2, ways = dp3 % MOD;
    } else if (dp1 || dp2) {
      count = 1, ways = (dp1 + dp2) % MOD;
    } else {
      count = 0, ways = 1;
    }
  }

  void update_max(const Sum &o) {
    if (count < o.count) {
      count = o.count, ways = 0;
    }
    if (count == o.count) {
      ways += o.ways;
      if (ways >= MOD) {
        ways -= MOD;
      }
    }
  }

  int count, ways;
};

Sum operator+(const Sum &a, const Sum &b) {
  return Sum(a.count + b.count, 1LL * a.ways * b.ways % MOD);
}

Sum operator-(const Sum &a, const Sum &b) {
  return Sum(a.count - b.count, 1LL * a.ways * inv(b.ways) % MOD);
}

int main() {
  int n, m;
  while (scanf("%d%d", &m, &n) == 2) {
    std::vector<std::vector<int>> indices(m);
    for (int i = 0, s; i < m; ++i) {
      scanf("%d", &s);
      indices[s - 1].push_back(i);
    }
    std::vector<int> colors(n), states(n);
    std::vector<std::pair<int, int>> lefts, rights;
    for (int i = 0, h; i < n; ++i) {
      scanf("%d%d", &colors[i], &h);
      int size = indices[--colors[i]].size();
      if (h <= size) {
        lefts.emplace_back(indices[colors[i]][h - 1], i);
        rights.emplace_back(indices[colors[i]][size - h], i);
      }
    }
    std::sort(lefts.begin(), lefts.end());
    std::sort(rights.begin(), rights.end());
    Sum sum;
    std::vector<Stat> stats(m);
    auto update_stat = [&](int i, int ns) {
      auto &stat = stats[colors[i]];
      sum = sum - Sum(stat);
      stat[states[i]]--;
      stat[states[i] = ns]++;
      sum = sum + Sum(stat);
    };
    for (const auto &iterator : rights) {
      update_stat(iterator.second, 2);
    }
    Sum result = sum;
    auto jterator = rights.begin();
    for (const auto &iterator : lefts) {
      while (jterator != rights.end() && jterator->first <= iterator.first) {
        int i = (jterator++)->second;
        update_stat(i, states[i] ^ 2);
      }
      int i = iterator.second;
      const auto &stat = stats[colors[i]];
      Stat nstat{0, 1, stat[2] + stat[3] - (states[i] == 2), 0};
      result.update_max(sum - Sum(stat) + Sum(nstat));
      update_stat(i, states[i] ^ 1);
    }
    printf("%d %d\n", result.count, result.ways);
  }
}