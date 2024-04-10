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
#include <queue>

struct Station {
  int x;
  int r;
  int f;
  Station(int x, int r, int f) : x(x), r(r), f(f) {}
};

template<class T>
struct BinTree1 {
  size_t size;
  std::vector<T> t;

  BinTree1(size_t N) :
      size(N),
      t(2 * N) {}

  BinTree1(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  T get(size_t p) {
    return t[p + size];
  }

  void modify(size_t p, T value) {
    p += size;
    t[p] += value;
    while (p > 1) {
      p = p / 2;
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    }
  }

  T query(size_t l, size_t r) {
    l += size;
    r += size;
    T left = init();
    T right = init();
    while (l < r) {
      if (l & 1) {
        left = combine(left, t[l]);
        l++;
      }
      if (r & 1) {
        r--;
        right = combine(t[r], right);
      }
      l = l / 2;
      r = r / 2;
    }
    return combine(left, right);
  }

 private:
  T combine(T left, T right) {
    return left + right;
  }

  T init() {
    return T();
  }
};

struct Solution {
  int n, k;
  std::vector<Station> stations;
  static constexpr int MaxFreq = 10001;
  std::vector<std::vector<int>> freqSets;
  std::vector<BinTree1<int>> freqTrees;
  using FreqQueue = std::priority_queue<
      std::pair<int, int>,
      std::vector<std::pair<int, int>>,
      std::greater<std::pair<int, int>>
  >;
  std::vector<FreqQueue> freqQueues;

  void calcFreqSet() {
    freqSets.assign(MaxFreq, std::vector<int>());
    for (int i = 0; i < n; i++) {
      for (int j = -k; j <= k; j++) {
        int ff = stations[i].f + j;
        if (ff >= 1 && ff < MaxFreq) {
          freqSets[ff].push_back(stations[i].x);
        }
      }
    }
    for (std::vector<int>& freqSet : freqSets) {
      std::sort(freqSet.begin(), freqSet.end());
    }
    freqTrees.clear();
    for (size_t i = 0; i < freqSets.size(); i++) {
      freqTrees.emplace_back(freqSets[i].size());
    }
    freqQueues.clear();
    for (size_t i = 0; i < freqSets.size(); i++) {
      freqQueues.emplace_back();
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> k;
    stations.clear();
    for (int i = 0; i < n; i++) {
      int x, r, f;
      in >> x >> r >> f;
      stations.emplace_back(x, r, f);
    }
    calcFreqSet();
    std::vector<std::pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
      intervals.emplace_back(stations[i].x, i);
    }
    std::sort(intervals.begin(), intervals.end());
    int64_t answer = 0;
    for (std::pair<int, int>& interval : intervals) {
      Station& station = stations[interval.second];
      {
        FreqQueue& queue = freqQueues[station.f];
        auto& tree = freqTrees[station.f];
        while (!queue.empty() && queue.top().first < station.x) {
          tree.modify(queue.top().second, -1);
          queue.pop();
        }
        auto& freqSet = freqSets[station.f];
        int lBound = station.x - station.r;
        size_t lIndex = std::lower_bound(freqSet.begin(), freqSet.end(), lBound) - freqSet.begin();
        answer += tree.query(lIndex, tree.size);
      }

      for (int i = -k; i <= k; i++) {
        int ff = station.f + i;
        if (ff >= 1 && ff < MaxFreq) {
          auto& freqSet = freqSets[ff];
          int idx = std::lower_bound(freqSet.begin(), freqSet.end(), station.x) - freqSet.begin();
          freqQueues[ff].emplace(station.x + station.r, idx);
          freqTrees[ff].modify(idx, 1);
        }
      }
    }
    out << answer << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}