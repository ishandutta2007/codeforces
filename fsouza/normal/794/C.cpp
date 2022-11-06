#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

vector<int> parse(const string &s) {
  vector<int> result(26, 0);
  for (char c : s)
    ++result[c - 'a'];
  return result;
}

int max_value(vector<int> &counts, bool pop = false) {
  for (int i = 25; i >= 0; --i)
    if (counts[i] > 0) {
      if (pop) --counts[i];
      return i;
    }
  return -1;
}

int min_value(vector<int> &counts, bool pop = false) {
  for (int i = 0; i < 26; ++i)
    if (counts[i] > 0) {
      if (pop) --counts[i];
      return i;
    }
  return 26;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string oleg_init, igor_init;
  cin >> oleg_init >> igor_init;
  int n = oleg_init.size();
  vector<int> oleg_counts = parse(oleg_init);
  vector<int> igor_counts = parse(igor_init);
  string result(n, ' ');
  int player = 0, position = 0;
  while (position < n) {
    const int mino = min_value(oleg_counts), maxo = max_value(oleg_counts);
    const int mini = min_value(igor_counts), maxi = max_value(igor_counts);
    const int remain = n - position;
    if (player == 0) {
      if (maxi > mino) {
        result[position++] = 'a' + mino;
        min_value(oleg_counts, true);
        player = 1;
        continue;
      } else {
        if (remain % 2 == 1) {
          result[position++] = 'a' + mino;
          min_value(oleg_counts, true);
          continue;
        } else {
          result[position++] = 'a' + maxi;
          max_value(igor_counts, true);
          continue;
        }
      }
    } else {
      if (mino < maxi) {
        result[position++] = 'a' + maxi;
        max_value(igor_counts, true);
        player = 0;
        continue;
      } else {
        if (remain % 2 == 1) {
          result[position++] = 'a' + maxi;
          max_value(igor_counts, true);
          continue;
        } else {
          result[position++] = 'a' + mino;
          min_value(oleg_counts, true);
          continue;
        }
      }
    }
  }
  cout << result << "\n";
  return 0;
}