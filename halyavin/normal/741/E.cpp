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

std::vector<int> getSelfZ(const std::string& view) {
  size_t n = view.length();
  std::vector<int> selfZ(n);
  selfZ[0] = n;
  size_t right_bound = 1;
  size_t offset = 0;
  for (size_t i = 1; i < n; i++) {
    if (i >= right_bound || selfZ[i - offset] + i >= right_bound) {
      size_t start = std::max(i, right_bound);
      for (; start < n && view[start] == view[start - i]; start++) {
      }
      selfZ[i] = start - i;
      right_bound = start;
      offset = i;
    } else {
      selfZ[i] = selfZ[i - offset];
    }
  }
  return selfZ;
}

std::vector<int> getCommonZ(const std::string& view,
                            const std::string& pattern,
                            const std::vector<int>& patternZ) {
  size_t n = view.size();
  size_t m = pattern.size();
  size_t right_bound = 0;
  size_t offset = 0;
  std::vector<int> commonZ(n);
  for (size_t i = 0; i < n; i++) {
    if (i >= right_bound || patternZ[i - offset] + i >= right_bound) {
      size_t start = std::max(i, right_bound);
      for (; start < std::min(n, m + i) && view[start] == pattern[start - i]; start++) {
      }
      commonZ[i] = start - i;
      right_bound = start;
      offset = i;
    } else {
      commonZ[i] = patternZ[i - offset];
    }
  }
  return commonZ;
}

struct Solution {
  std::string s;
  std::string t;
  std::vector<int> zs;
  std::vector<int> zt;
  std::vector<int> zshift;

  char getChar(int p, int pos) {
    if (pos < p) {
      return s[pos];
    }
    if (pos < p + (int) t.length()) {
      return t[pos - p];
    }
    return s[pos - (int) t.length()];
  }

  int compare2(int p1, int p2) {
    std::string s1 = s.substr(0, p1) + t + s.substr(p1);
    std::string s2 = s.substr(0, p2) + t + s.substr(p2);
    if (s1 < s2) return -1;
    if (s1 > s2) return 1;
    if (p1 < p2) return -1;
    if (p1 > p2) return 1;
    return 0;
  }

  int compare(int p1, int p2) {
    if (p1 == p2) return 0;
    if (p1 > p2) {
      return -compare(p2, p1);
    }
    int length1 = std::min(p2 - p1, (int) t.length());
    int common1 = std::min(length1, zs[p1]);
    int pos = p1 + common1;
    if (common1 == length1) {
      if (p2 - p1 < (int) t.length()) {
        int length2 = (int) t.length() - (p2 - p1);
        int common2 = zt[p2 - p1];
        pos += common2;
        if (common2 == length2) {
          int length3 = p2 - p1;
          int common3 = std::min(length3, zt[(int) t.length() - (p2 - p1)]);
          pos += common3;
          if (common3 == length3) {
            return -1;
          }
        }
      } else {
        int length2 = p2 - p1 - (int) t.length();
        int common2 = std::min(length2, p1 >= zshift.size() ? 0 : zshift[p1]);
        pos += common2;
        if (common2 == length2) {
          int length3 = (int) t.length();
          int common3 = zs[p2 - (int) t.length()];
          pos += common3;
          if (common3 == length3) {
            return -1;
          }
        }
      }
    }
    if (pos == (int) s.length() + (int) t.length()) {
      return -1;
    }
    char c1 = getChar(p1, pos);
    char c2 = getChar(p2, pos);
    if (c1 < c2) {
      return -1;
    } else {
      return 1;
    }
  }

  // pos -> order
  std::vector<int> order;
  // order -> pos
  std::vector<int> revOrder;

  std::vector<std::vector<int>> minOrder;

  static constexpr int switchBound = 100;

  struct PrecomputeK {
    std::vector<int> starts;
    std::vector<int> nodes;
    int n;
    PrecomputeK(int k, int n, const std::vector<int>& order) : n(n) {
      starts.resize(k + 1);
      for (int i = 0; i < k; i++) {
        starts[i + 1] = starts[i] + (n - i + k - 1) / k;
      }
      nodes.resize(2 * n);
      for (int i = 0; i < k; i++) {
        for (int j = starts[i];j < starts[i + 1]; j++) {
          nodes[n + j] = order[i + (j - starts[i]) * k];
        }
      }
      for (int i =  n - 1; i > 0; i--) {
        nodes[i] = std::min(nodes[2 * i], nodes[2 * i + 1]);
      }
    }

    int request(int mod, int from, int to) const {
      int left = from + starts[mod] + n;
      int right = to + starts[mod] + n;
      int res = n;
      while (left < right) {
        if (left & 1) {
          res = std::min(res, nodes[left]);
          left++;
        }
        if (right & 1) {
          right--;
          res = std::min(res, nodes[right]);
        }
        left >>= 1;
        right >>= 1;
      }
      return res;
    }
  };

  std::vector<PrecomputeK> precomputesK;

  void buildMinOrder() {
    minOrder.clear();
    minOrder.push_back(order);
    size_t length = 1;
    while (2 * length <= order.size()) {
      minOrder.emplace_back(order.size() - 2 * length + 1);
      std::vector<int>& before = minOrder[minOrder.size() - 2];
      std::vector<int>& after = minOrder[minOrder.size() - 1];
      for (size_t i = 0; i < after.size(); i++) {
        after[i] = std::min(before[i], before[i + length]);
      }
      length *= 2;
    }
  }

  void buildPrecomputesK() {
    precomputesK.clear();
    for (size_t k = 1; k < switchBound && k < order.size(); k++) {
      precomputesK.emplace_back(k, order.size(), order);
    }
  }

  const PrecomputeK& getPrecomputeK(int k) {
    return precomputesK[k - 1];
  }

  int getMin(int from, int to) {
    if (to <= from) return order.size();
    int length = 32 - __builtin_clz(to - from);
    length--;
    return std::min(minOrder[length][from], minOrder[length][to - (1 << length)]);
  }

  void process() {
    zt = getSelfZ(t);
    zs = getCommonZ(s, t, zt);
    if (t.length() < s.length()) {
      zshift.resize(s.length() - t.length());
      int cur = 0;
      for (size_t i = zshift.size(); i-- > 0;) {
        if (s[i] == s[i + t.length()]) {
          cur++;
        } else {
          cur = 0;
        }
        zshift[i] = cur;
      }
    }
    revOrder.resize(s.length() + 1);
    std::iota(revOrder.begin(), revOrder.end(), 0);
    std::sort(revOrder.begin(), revOrder.end(),
              [this](int left, int right) { return compare(left, right) < 0; });
    order.resize(s.length() + 1);
    for (size_t i = 0; i < revOrder.size(); i++) {
      order[revOrder[i]] = i;
    }
    buildMinOrder();
    buildPrecomputesK();
  }

  int query(int l, int r, int k, int x, int y) {
    r++;
    y++;
    if (k >= order.size() || k >= switchBound) {
      int res = order.size();
      for (int i = 0; i < (int)order.size(); i += k) {
        int left = std::max(l, i + x);
        int right = std::min(r, i + y);
        res = std::min(res, getMin(left, right));
      }
      return res == order.size() ? -1 : revOrder[res];
    }
    const PrecomputeK& precomp = getPrecomputeK(k);
    int res = order.size();
    for (int rest = x; rest < y; rest++) {
      int l1 = (l - rest + k - 1) / k;
      int r1 = (r - rest + k - 1) / k;
      res = std::min(res, precomp.request(rest, l1, r1));
    }
    return res == order.size() ? -1 : revOrder[res];
  }

  void run(std::istream& in, std::ostream& out) {
    int q;
    in >> s >> t >> q;
    process();
    for (int i = 0; i < q; i++) {
      int l, r, k, x, y;
      in >> l >> r >> k >> x >> y;
      out << query(l, r, k, x, y) << " ";
    }
    out << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}