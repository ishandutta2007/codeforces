#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cctype>
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

const int ndigit = 16;

lint read_hex() {
  char str[ndigit + 1];
  scanf("%s", str);
  lint result = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    int value;
    if (isdigit(str[i])) value = str[i] - '0';
    else value = str[i] - 'a' + 10;
    result = 16 * result + value;
  }
  return result;
}

vector<int> to_hex(lint value) {
  vector<int> result(ndigit);
  for (int i = ndigit - 1; i >= 0; --i) {
    result[i] = value % 16;
    value /= 16;
  }
  return result;
}

lint solve(lint limit, int max_digit_value, int bit_on_id) {
  lint result = 0;
  if (max_digit_value < 0) return result;
  int bit_digit = ndigit - 1 - bit_on_id / 4;
  int bit_mask = 1 << (bit_on_id % 4);
  vector<int> limit_hex = to_hex(limit);
  for (int eq_until = -1; eq_until + 1 < ndigit; ++eq_until) {
    lint nway = 1;
    for (int i = 0; i <= eq_until; ++i) {
      if (limit_hex[i] > max_digit_value) nway = 0;
      if (bit_digit == i && !(limit_hex[i] & bit_mask)) nway = 0;
    }
    int mid_nway = 0;
    for (int value = 0; value < limit_hex[eq_until + 1]; ++value) {
      bool ok = true;
      if (value > max_digit_value) ok = false;
      if (bit_digit == eq_until + 1 && !(value & bit_mask)) ok = false;
      if (ok) ++mid_nway;
    }
    nway *= mid_nway;
    for (int i = eq_until + 2; i < ndigit; ++i) {
      int digit_nway = 0;
      if (bit_digit == i) {
        for (int value2 = 0; value2 <= max_digit_value; ++value2)
          if (value2 & bit_mask)
            ++digit_nway;
      } else {
        digit_nway = max_digit_value + 1;
      }
      nway *= digit_nway;
    }
    result += nway;
  }
  return result;
}

lint solve(lint limit) {
  lint result = 0;
  if (limit == 0) return result;
  for (int highest = 0; highest < 16; ++highest) {
    result += (solve(limit, highest, highest) -
               solve(limit, highest - 1, highest));
  }
  return result;
}

int main() {
  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    lint left = read_hex(), right = read_hex();
    lint result = solve(right + 1) - solve(left);
    printf("%lld\n", result);
  }
  return 0;
}