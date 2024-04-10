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

const int p = 51123987;

struct string_view {
  const std::string& str;
  size_t left;
  size_t right;

  string_view(const std::string& str, size_t left, size_t right) :
      str(str), left(left), right(right) { }

  string_view(const string_view& view, size_t left, size_t right) :
      str(view.str), left(view.left + left), right(view.left + right) { }

  size_t size() const { return right - left; }

  char operator[](size_t idx) const { return str[left + idx]; }
};

struct Solution {

  std::vector<size_t> selfZ;
  std::vector<size_t> commonZ;

  void getSelfZ(const string_view& view) {
    size_t n = view.size();
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
  }

  void getZ(const string_view& view, size_t maxn, const string_view& pattern) {
    size_t n = view.size();
    size_t m = pattern.size();
    size_t right_bound = 0;
    size_t offset = 0;
    for (size_t i = 0; i < maxn; i++) {
      if (i >= right_bound || selfZ[i - offset] + i >= right_bound) {
        size_t start = std::max(i, right_bound);
        for (; start < std::min(n, m + i) && view[start] == pattern[start - i]; start++) {
        }
        commonZ[i] = start - i;
        right_bound = start;
        offset = i;
      } else {
        commonZ[i] = selfZ[i - offset];
      }
    }
  }

  void getPalindromes(const string_view& view, const string_view& rview, std::vector<size_t>& maxLen) {
    if (view.size() <= 3) {
      for (size_t i = 0; i < view.size(); i++) {
        for (size_t j = i; j < view.size(); j++) {
          bool good = true;
          for (size_t k = i, l = j; k < l; k++, l--) {
            if (view[k] != view[l]) {
              good = false;
              break;
            }
          }
          if (good) {
            maxLen[i + j + view.left * 2] = std::max(maxLen[i + j + view.left * 2], j - i + 1);
          }
        }
      }
      return;
    }
    size_t middle = view.size() / 2;
    size_t revMiddle = view.size() - middle;
    string_view viewHalf(view, middle, view.size());
    getSelfZ(viewHalf);
    getZ(rview, revMiddle, viewHalf);
    for (size_t i = 0; i < revMiddle; i++) {
      size_t rightPos = i + commonZ[i];
      if (rightPos > revMiddle) {
        size_t left = view.right - rightPos;
        size_t right = view.left + middle + commonZ[i] - 1;
        maxLen[left + right] = std::max(maxLen[left + right], right - left + 1);
      }
    }
    string_view viewHalf2(rview, revMiddle, rview.size());
    getSelfZ(viewHalf2);
    getZ(view, middle + 1, viewHalf2);
    for (size_t i = 0; i <= middle; i++) {
      size_t rightPos = i + commonZ[i];
      if (rightPos > middle) {
        size_t left = view.left + middle - commonZ[i];
        size_t right = view.left + rightPos - 1;
        maxLen[left + right] = std::max(maxLen[left + right], right - left + 1);
      }
    }
    getPalindromes(string_view(view, 0, middle), string_view(rview, revMiddle, rview.size()), maxLen);
    getPalindromes(string_view(view, middle, view.size()), string_view(rview, 0, revMiddle), maxLen);
  }

  static int mul32(int x, int y, int p) {
    return int(int64_t(x) * y % p);
  }

  void run(std::istream& in, std::ostream& out) {
    size_t n;
    in >> n;
    std::string s;
    in >> s;
    std::string r = s;
    std::reverse(r.begin(), r.end());
    std::vector<size_t> maxLen(2 * n - 1);
    selfZ.resize(n);
    commonZ.resize(n);
    getPalindromes(string_view(s, 0, n), string_view(r, 0, n), maxLen);
    std::vector<int> leftBounds(n);
    std::vector<int> allPalindromes(n);
    for (size_t i = 0; i < maxLen.size(); i++) {
      if (maxLen[i] == 0) continue;
      size_t left = (i + 1 - maxLen[i]) / 2;
      size_t middle = left + (maxLen[i] + 1) / 2;
      leftBounds[left]++;
      if (middle < n) leftBounds[middle]--;
    }
    for (size_t i = 1; i < leftBounds.size(); i++) {
      leftBounds[i] += leftBounds[i - 1];
    }
    for (size_t i = 0; i < maxLen.size(); i++) {
      if (maxLen[i] == 0) continue;
      size_t left = (i + 1 - maxLen[i]) / 2;
      size_t middle1 = left + (maxLen[i] + 1) / 2;
      size_t middle2 = left + (maxLen[i] + 2) / 2;
      size_t right = left + maxLen[i] + 1;
      allPalindromes[left]++;
      if (middle1 < n) allPalindromes[middle1]--;
      if (middle2 < n) allPalindromes[middle2]--;
      if (right < n) allPalindromes[right]++;
    }
    for (size_t i = 1; i < allPalindromes.size(); i++) {
      allPalindromes[i] = (allPalindromes[i] + allPalindromes[i - 1]) % p;
    }
    for (size_t i = 1; i < allPalindromes.size(); i++) {
      allPalindromes[i] = (allPalindromes[i] + allPalindromes[i - 1]) % p;
    }
    int res = 0;
    for (size_t i = 0; i < allPalindromes.size(); i++) {
      res += mul32(allPalindromes[i] - leftBounds[i], leftBounds[i], p);
      if (leftBounds[i] & 1) {
        res += mul32((leftBounds[i] - 1) / 2, leftBounds[i], p);
      } else {
        res += mul32(leftBounds[i] - 1, leftBounds[i] / 2, p);
      }
      res = res % p;
    }
    if (res < 0) res += p;
    out << res << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}