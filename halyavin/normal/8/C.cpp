#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

size_t n;
std::vector<std::vector<int>> matrix;

std::vector<int> dyn;
std::vector<std::pair<int8_t, int8_t>> prev;

int opt(int start, size_t mask) {
  if (dyn[mask] != -1) {
    return dyn[mask];
  }
  size_t orig_mask = mask;
  while ((mask & (1 << start)) == 0)
    start++;
  mask -= 1u << start;
  int start_value = matrix[0][start + 1];
  int min_value = 2 * start_value + opt(start + 1, mask);
  int prev_x = start;
  int prev_y = -1;
  for (int i = start + 1; i < n; i++) {
    if ((mask & (1u << i)) == 0)
      continue;
    int cur_value = start_value + matrix[start + 1][i + 1] + matrix[i + 1][0] +
                    opt(start + 1, mask - (1u << i));
    if (cur_value < min_value) {
      min_value = cur_value;
      prev_y = i;
    }
  }
  dyn[orig_mask] = min_value;
  prev[orig_mask].first = prev_x;
  prev[orig_mask].second = prev_y;
  return min_value;
}

void run(std::istream& in, std::ostream& out) {
  std::vector<std::array<int, 2>> stuff(1);
  in >> stuff[0][0] >> stuff[0][1];
  in >> n;
  for (int i = 0; i < n; i++) {
    std::array<int, 2> pos;
    in >> pos[0] >> pos[1];
    stuff.push_back(pos);
  }
  matrix.resize(n + 1);
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < stuff.size(); j++) {
      matrix[i].push_back(
          (stuff[i][0] - stuff[j][0]) * (stuff[i][0] - stuff[j][0]) +
          (stuff[i][1] - stuff[j][1]) * (stuff[i][1] - stuff[j][1]));
    }
  }
  dyn.resize(1u << n);
  std::fill(dyn.begin(), dyn.end(), -1);
  dyn[0] = 0;
  prev.resize(1u << n);
  out << opt(0, (1u << n) - 1) << std::endl;
  size_t mask = (1u << n) - 1;
  std::vector<int> path = {0};
  while (mask != 0) {
    std::pair<char, char> prev_move = prev[mask];
    mask -= 1u << prev_move.first;
    path.push_back(prev_move.first + 1);
    if (prev_move.second >= 0) {
      mask -= 1u << prev_move.second;
      path.push_back(prev_move.second + 1);
    }
    path.push_back(0);
  }
  for (int v : path) {
    out << v << " ";
  }
  out << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}