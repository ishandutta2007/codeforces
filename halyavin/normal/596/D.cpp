#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <array>

std::vector<int> getLeftFall(const std::vector<int>& x, int h) {
  std::vector<int> result(x.size());
  result[0] = 0;
  for (size_t i = 1; i < x.size(); i++) {
    if (x[i] - x[i - 1] < h) {
      result[i] = result[i - 1];
    } else {
      result[i] = i;
    }
  }
  return result;
}

std::vector<int> getRightFall(const std::vector<int>& x, int h) {
  std::vector<int> result(x.size());
  result[x.size() - 1] = x.size() - 1;
  for (size_t i = x.size() - 1; i-- > 0;) {
    if (x[i + 1] - x[i] < h) {
      result[i] = result[i + 1];
    } else {
      result[i] = i;
    }
  }
  return result;
}

void run(std::istream &in, std::ostream &out) {
  int n, h;
  in >> n >> h;
  double p;
  in >> p;
  std::vector<int> x(n);
  for (int i = 0; i < n; i++) {
    in >> x[i];
  }
  std::sort(x.begin(), x.end());
  std::vector<std::vector<std::array<double, 4>>>dyn(n);
  for (int i = 0; i < n; i++) {
    dyn[i].resize(i + 1);
  }

  std::vector<int> leftFall = getLeftFall(x, h);
  std::vector<int> rightFall = getRightFall(x, h);
  std::vector<int> rightDist0(n);
  std::vector<int> rightDist1(n);
  std::vector<int> leftDist0(n);
  std::vector<int> leftDist1(n);
  for (int i = 0; i < n - 1; i++) {
    rightDist0[i] = std::min(h, x[i + 1] - x[i]);
    rightDist1[i] = std::min(h, x[i + 1] - x[i] - h);
  }
  rightDist0[n-1] = h;
  rightDist1[n-1] = h;
  for (int i = 1; i < n; i++) {
    leftDist0[i] = std::min(h, x[i] - x[i-1]);
    leftDist1[i] = std::min(h, x[i] - x[i-1] - h);
  }
  leftDist0[0] = h;
  leftDist1[0] = h;
  for (int len = 0; len < n; len++) {
    for (int right = len; right < n; right++) {
      int left = right - len;
      std::array<double, 4>& ans = dyn[right][left];
      int rDist0 = rightDist0[right];
      int rDist1 = rightDist1[right];
      int lDist0 = leftDist0[left];
      int lDist1 = leftDist1[left];
      double add, add0, add1;
      int fallIndex;
      // left falls left
      ans[0] += lDist0 * p / 2;
      ans[1] += lDist0 * p / 2;
      ans[2] += lDist1 * p / 2;
      ans[3] += lDist1 * p / 2;

      if (right > left) {
        add0 = dyn[right][left + 1][0];
        add1 = dyn[right][left + 1][1];
        ans[0] += add0 * p / 2;
        ans[1] += add1 * p / 2;
        ans[2] += add0 * p / 2;
        ans[3] += add1 * p / 2;
      }

      // right falls right
      ans[0] += rDist0 * (1 - p) / 2;
      ans[1] += rDist1 * (1 - p) / 2;
      ans[2] += rDist0 * (1 - p) / 2;
      ans[3] += rDist1 * (1 - p) / 2;
      if (right > left) {
        add0 = dyn[right - 1][left][0];
        add1 = dyn[right - 1][left][2];
        ans[0] += add0 * (1 - p) / 2;
        ans[1] += add0 * (1 - p) / 2;
        ans[2] += add1 * (1 - p) / 2;
        ans[3] += add1 * (1 - p) / 2;
      }

      // left falls right
      fallIndex = rightFall[left];
      if (fallIndex >= right) {
        add = (x[right] - x[left]) * (1 - p) / 2;
        add0 = add + rDist0 * (1 - p) / 2;
        add1 = add + rDist1 * (1 - p) / 2;
        ans[0] += add0;
        ans[1] += add1;
        ans[2] += add0;
        ans[3] += add1;
      } else {
        add = (x[fallIndex] - x[left] + h) * (1 - p) / 2;
        add0 = add + dyn[right][fallIndex + 1][2] * (1 - p) / 2;
        add1 = add + dyn[right][fallIndex + 1][3] * (1 - p) / 2;
        ans[0] += add0;
        ans[1] += add1;
        ans[2] += add0;
        ans[3] += add1;
      }

      // right falls left
      fallIndex = leftFall[right];
      if (fallIndex <= left) {
        double add = (x[right] - x[left]) * p / 2;
        add0 = add + lDist0 * p / 2;
        add1 = add + lDist1 * p / 2;
        ans[0] += add0;
        ans[1] += add0;
        ans[2] += add1;
        ans[3] += add1;
      } else {
        add = (x[right] - x[fallIndex] + h) * p / 2;
        add0 = add + dyn[fallIndex - 1][left][1] * p / 2;
        add1 = add + dyn[fallIndex - 1][left][3] * p / 2;
        ans[0] += add0;
        ans[1] += add0;
        ans[2] += add1;
        ans[3] += add1;
      }
    }
  }
  out.precision(10);
  out << dyn[n - 1][0][0] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}