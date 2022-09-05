#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct Prev {
  int index;
  int dir;
  int turn;
};

struct Solution {
  int n, s;

  std::vector<std::vector<int>> groups;
  std::vector<std::vector<int>> dyn;
  std::vector<std::vector<Prev>> prev;

  void group(const std::vector<std::pair<int, int>>& as) {
    groups.push_back(std::vector<int>{s});
    dyn.push_back(std::vector<int>(1));
    prev.push_back(std::vector<Prev>(1));
    int start = 0;
    for (int i = 1; i < n; i++) {
      if (as[i].first != as[start].first) {
        std::vector<int> group(i - start);
        for (int j = start; j < i; j++) {
          group[j - start] = as[j].second;
        }
        groups.push_back(group);
        dyn.push_back(std::vector<int>(group.size()));
        prev.push_back(std::vector<Prev>(group.size()));
        start = i;
      }
    }
    std::vector<int> group(n - start);
    for (int j = start; j < n; j++) {
      group[j - start] = as[j].second;
    }
    groups.push_back(group);
    dyn.push_back(std::vector<int>(group.size()));
    prev.push_back(std::vector<Prev>(group.size()));
  }

  void step(size_t gprev, size_t gcur) {
    std::fill(dyn[gcur].begin(), dyn[gcur].end(), 1000000000);
    for (size_t i = 0; i < groups[gprev].size(); i++) {
      int pos = groups[gprev][i];
      int dynBefore = dyn[gprev][i];
      for (size_t turn = 0; turn < groups[gcur].size(); turn++) {
        size_t before = (turn + groups[gcur].size() - 1) % groups[gcur].size();
        int dist = dynBefore + (pos - groups[gcur][turn] + n) % n + (groups[gcur][before] + n - groups[gcur][turn]) % n;
        if (dyn[gcur][before] > dist) {
          dyn[gcur][before] = dist;
          prev[gcur][before].index = i;
          prev[gcur][before].dir = -1;
          prev[gcur][before].turn = turn;
        }
      }
      for (size_t turn = 0; turn < groups[gcur].size(); turn++) {
        size_t next = (turn + 1) % groups[gcur].size();
        int dist = dynBefore + (groups[gcur][turn] - pos + n) % n + (groups[gcur][turn] - groups[gcur][next] + n) % n;
        if (dyn[gcur][next] > dist) {
          dyn[gcur][next] = dist;
          prev[gcur][next].index = i;
          prev[gcur][next].dir = 1;
          prev[gcur][next].turn = turn;
        }
      }
      size_t j = 0;
      while (j < groups[gcur].size() && groups[gcur][j] <= pos) {
        j++;
      }
      j %= groups[gcur].size();
      size_t prev_j = (j + groups[gcur].size() - 1) % groups[gcur].size();
      {
        int dist = dynBefore + (pos - groups[gcur][j] + n) % n;
        if (dyn[gcur][j] > dist) {
          dyn[gcur][j] = dist;
          prev[gcur][j].index = i;
          prev[gcur][j].dir = -1;
          prev[gcur][j].turn = -1;
        }
      }
      {
        int dist = dynBefore + (groups[gcur][prev_j] - pos + n - 1) % n + 1;
        if (dyn[gcur][prev_j] > dist) {
          dyn[gcur][prev_j] = dist;
          prev[gcur][prev_j].index = i;
          prev[gcur][prev_j].dir = 1;
          prev[gcur][prev_j].turn = -1;
        }
      }
    }

  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> s;
    s--;
    std::vector<std::pair<int, int>> as(n);
    for (int i = 0; i < n; i++) {
      in >> as[i].first;
      as[i].first--;
      as[i].second = i;
    }
    std::sort(as.begin(), as.end());
    group(as);
    for (size_t g = 1; g < groups.size(); g++) {
      step(g - 1, g);
    }
    size_t curG = groups.size() - 1;
    size_t curIndex = 0;
    int ans = dyn[curG][curIndex];
    for (size_t i = 1; i < dyn[curG].size(); i++) {
      if (dyn[curG][i] < ans) {
        ans = dyn[curG][i];
        curIndex = i;
      }
    }
    out << ans << std::endl;
    std::vector<std::pair<int, int>> answer;
    for (; curG > 0; curG--) {
      Prev info = prev[curG][curIndex];
      int pos = groups[curG - 1][info.index];
      std::vector<std::pair<int, int>> local;
      int firstIndex;
      int dir;
      if (info.dir == -1) {
        if (info.turn == -1) {
          int j = 0;
          while (j < groups[curG].size() && groups[curG][j] <= pos) j++;
          j = (j + groups[curG].size() - 1) % groups[curG].size();
          firstIndex = j;
          dir = -1;
          local.emplace_back(-1, (pos - groups[curG][j] + n) % n);
        } else {
          firstIndex = info.turn;
          local.emplace_back(-1, (pos - groups[curG][firstIndex] + n) % n);
          dir = 1;
        }
      } else {
        if (info.turn == -1) {
          int j = 0;
          while (j < groups[curG].size() && groups[curG][j] <= pos) j++;
          firstIndex = j;
          dir = 1;
          local.emplace_back(1, (groups[curG][j] - pos + n - 1) % n + 1);
        } else {
          firstIndex = info.turn;
          local.emplace_back(1, (groups[curG][firstIndex] - pos + n) % n);
          dir = -1;
        }
      }
      for (int j = 1; j < static_cast<int>(groups[curG].size()); j++) {
        int cur = (firstIndex + j * dir + groups[curG].size()) % groups[curG].size();
        int prev = (firstIndex + (j - 1) * dir + groups[curG].size()) % groups[curG].size();
        local.emplace_back(dir, ((groups[curG][cur] - groups[curG][prev]) * dir + n) % n);
      }
      std::reverse(local.begin(), local.end());
      answer.insert(answer.end(), local.begin(), local.end());
      curIndex = info.index;
    }
    std::reverse(answer.begin(), answer.end());
    for (std::pair<int, int> move : answer) {
      if (move.first == 1) {
        out << "+";
      } else {
        out << "-";
      }
      out << move.second << "\n";
    }
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}