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

int getMaxIdx(std::vector<int>& skills, int A, int64_t& left) {
  for (size_t i = skills.size(); i-- > 0;) {
    if (A - skills[i] <= left) {
      left -= A - skills[i];
    } else {
      return i;
    }
  }
  return -1;
}

void run(std::istream& in, std::ostream& out) {
  int n;
  int A;
  int64_t cf;
  int64_t cm;
  int64_t m;
  in >> n >> A >> cf >> cm >> m;
  std::vector<int> skills(n);
  for (int i = 0; i < n; i++) {
    in >> skills[i];
  }
  std::vector<int> id(n);
  std::iota(id.begin(), id.end(), 0);
  std::sort(id.begin(), id.end(), [&skills](int left, int right) { return skills[left] < skills[right]; });
  std::vector<int> sorted_skills(n);
  for (int i = 0; i < n; i++) {
    sorted_skills[i] = skills[id[i]];
  }
  int64_t left = m;
  int idx = getMaxIdx(sorted_skills, A, left);
  if (idx < 0) {
    out << (cf * n + cm * A) << std::endl;
    for (int i = 0; i < n; i++) {
      out << A << " ";
    }
    out << std::endl;
    return;
  }
  int64_t ans = 0;
  int ans_max = 0;
  int ans_min = 0;
  int ans_limit = 0;
  int cur_max = idx + 1;
  int cur_limit = sorted_skills[0];
  int cur_min = 1;
  while (left >= cur_min && cur_min <= idx) {
    int add = left / cur_min;
    int next = sorted_skills[cur_min] - cur_limit;
    int step = std::min(add, next);
    cur_limit += step;
    left -= step * cur_min;
    if (next > add) {
      break;
    } else {
      cur_min++;
    }
  }
  if (cur_min > idx) {
    int add = left/cur_min;
    left -= add * cur_min;
    cur_limit += add;
  }
  int64_t cur_ans = cur_limit * cm + (n - idx - 1) * cf;
  ans = cur_ans;
  ans_max = idx + 1;
  ans_min = cur_min;
  ans_limit = cur_limit;
  for(;idx < n - 1;) {
    left += A - sorted_skills[idx + 1];
    if (cur_min == idx + 1 && cur_limit >= sorted_skills[idx + 1]) {
      int sub = cur_limit - sorted_skills[idx + 1];
      left += sub * cur_min;
      cur_limit -= sub;
    }
    idx++;
    while (left >= cur_min && cur_min <= idx) {
      int add = left / cur_min;
      int next = sorted_skills[cur_min] - cur_limit;
      int step = std::min(add, next);
      cur_limit += step;
      left -= step * cur_min;
      if (next > add) {
        break;
      } else {
        cur_min++;
      }
    }
    if (cur_min > idx) {
      int add = left/cur_min;
      left -= add * cur_min;
      cur_limit += add;
    }
    cur_ans = cur_limit * cm + (n - idx - 1) * cf;
    if (cur_ans > ans) {
      ans = cur_ans;
      ans_max = idx + 1;
      ans_min = cur_min;
      ans_limit = cur_limit;
    }
  }
  out << ans << std::endl;
  std::vector<int> fskills = skills;
  for (int i = 0; i < ans_min; i++) {
    fskills[id[i]] = ans_limit;
  }
  for (int i = ans_max; i < n; i++) {
    fskills[id[i]] = A;
  }
  for (int i = 0; i < n;i++) {
    out << fskills[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}