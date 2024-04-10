#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>
#include <unordered_set>

uint64_t hash_mult1;

uint32_t rd() {
  uint32_t res;
#ifdef __MINGW32__
  asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
  res = std::random_device()();
#endif
  return res;
}

void init_hash() {
  while ((hash_mult1 = (uint64_t(rd()) << 32) + rd()) < (1ull << 32)) ;
}

uint32_t hash(int v) {
    return (uint64_t(v) * hash_mult1) >> 32;
}

struct IHash {
  uint32_t operator() (int v) const {
    return (uint64_t(v) * hash_mult1) >> 32;
  }
};

struct Problem {
  std::vector<std::vector<int>> g;
  std::vector<int> vColor;
  std::vector<int> order;
  std::vector<int> diff;
  void rootTree(int v, int prev) {
    size_t idx = g[v].size();
    for (size_t i = 0; i < g[v].size(); i++) {
      if (g[v][i] == prev) {
        idx = i;
        continue;
      }
      rootTree(g[v][i], v);
    }
    if (idx < g[v].size()) {
      g[v][idx] = g[v][g[v].size() - 1];
      g[v].resize(g[v].size() - 1);
    }
  }

  int calcListOrder(const std::vector<int>& vs, int first, int last, int k) {
    std::array<int, 27> stat = {};
    for (int i = first; i < last; i++) {
      int v = vs[i];
      for (int edge : g[v]) {
        stat[vColor[edge]]++;
      }
    }
    int total = std::accumulate(stat.begin(), stat.end(), 0);
    std::vector<int> nextVs(total);
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      sum += stat[i];
      stat[i] = sum;
    }
    for (int i = first; i < last; i++) {
      int v = vs[i];
      for (int edge : g[v]) {
        int c = vColor[edge];
        stat[c]--;
        nextVs[stat[c]] = edge;
      }
    }
    stat[26] = total;
    for (int c = 0; c < 26; c++) {
      if (stat[c] < stat[c + 1]) {
        for (int i = stat[c]; i < stat[c + 1]; i++) {
          order[nextVs[i]] = k;
        }
        k++;
        k = calcListOrder(nextVs, stat[c], stat[c + 1], k);
      }
    }
    return k;
  }

  using set = std::unordered_set<int, IHash, std::equal_to<int>>;

  set getDiff(int v) {
    std::vector<set> sets;
    for (int edge : g[v]) {
      sets.emplace_back(getDiff(edge));
    }
    int idx = -1;
    size_t maxSize = 0;
    for (size_t i = 0; i < sets.size(); i++) {
      if (sets[i].size() > maxSize) {
        maxSize = sets[i].size();
        idx = i;
      }
    }
    set result(1);
    if (idx >= 0) {
      result = std::move(sets[idx]);
      for (size_t i = 0; i < sets.size(); i++) {
        if (i != size_t(idx)) {
          result.insert(sets[i].begin(), sets[i].end());
        }
      }
    }
    result.insert(order[v]);
    diff[v] = result.size();
    return result;
  }

  void run(std::istream &in, std::ostream &out) {
    init_hash();
    int n;
    in >> n;
    std::vector<int> cs(n);
    for (int i = 0; i < n; i++) {
      in >> cs[i];
    }
    std::string letters;
    in >> letters;
    vColor.resize(n);
    for (int i = 0; i < n; i++) {
      vColor[i] = letters[i] - 'a';
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int from, to;
      in >> from >> to;
      from--;to--;
      g[from].push_back(to);
      g[to].push_back(from);
    }
    rootTree(0, -1);
    order.resize(n);
    calcListOrder({0}, 0, 1, 1);
    diff.resize(n);
    getDiff(0);
    int maxSum = -1;
    int nMax = 0;
    for (int i = 0; i < n; i++) {
      int cur = cs[i] + diff[i];
      if (cur > maxSum) {
        maxSum = cur;
        nMax = 1;
      } else if (cur == maxSum) {
        nMax++;
      }
    }
    out << maxSum << std::endl << nMax << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Problem().run(std::cin, std::cout);
  return 0;
}