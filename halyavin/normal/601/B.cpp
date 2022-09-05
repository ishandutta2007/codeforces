#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <stack>

int64_t getAnswer(std::vector<int> a, int left, int right) {
  if (left == right) {
    return 0;
  }
  std::vector<int> rightBound(right - left);
  std::vector<int> leftBound(right - left);
  std::stack<std::pair<int, int>, std::vector<std::pair<int, int>>> stack;
  for (int i = left; i < right; i++) {
    int current = a[i];
    if (stack.empty() || stack.top().first > current) {
      stack.emplace(current, i - left);
    } else {
      while (!stack.empty() && stack.top().first <= current) {
        leftBound[stack.top().second] = i - left;
        stack.pop();
      }
      stack.emplace(current, i - left);
    }
  }
  while (!stack.empty()) {
    leftBound[stack.top().second] = right - left;
    stack.pop();
  }
  for (int i = right - 1; i >= left; i--) {
    int current = a[i];
    if (stack.empty() || stack.top().first >= current) {
      stack.emplace(current, i - left);
    } else {
      while (!stack.empty() && stack.top().first < current) {
        rightBound[stack.top().second] = i - left;
        stack.pop();
      }
      stack.emplace(current, i - left);
    }
  }
  while (!stack.empty()) {
   rightBound[stack.top().second] = -1;
   stack.pop();
  }
  int64_t sum = 0;
  for (int i = 0; i < right - left; i++) {
    sum += int64_t(i - rightBound[i]) * int64_t(leftBound[i] - i) * int64_t(a[i + left]);
  }
  return sum;
}

void run(std::istream &in, std::ostream &out) {
  int n, q;
  in >> n >> q;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    in >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    a[i] = std::abs(a[i + 1] - a[i]);
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    in >> l >> r;
    l--; r--;
    int64_t ans = getAnswer(a, l, r);
    out << ans << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}