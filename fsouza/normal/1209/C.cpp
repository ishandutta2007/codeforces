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

bool sorted(const string &s) {
  for (int i = 0; i + 1 < (int)s.size(); ++i)
    if (s[i] > s[i + 1])
      return false;
  return true;
}

string solve(const string &seq, int d) {
  int n = seq.size();
  int max_less = -1;
  int min_greater = n;
  for (int i = 0; i < n; ++i) {
    if (seq[i] - '0' < d) {
      max_less = max(max_less, i);
    } else if (seq[i] - '0' > d) {
      min_greater = min(min_greater, i);
    }
  }
  string res(n, '_');
  for (int i = 0; i < n; ++i) {
    if (seq[i] - '0' < d) {
      res[i] = '1';
    } else if (seq[i] - '0' > d) {
      res[i] = '2';
    } else {
      if (i <= max_less && i >= min_greater)
        return "";
      if (i <= max_less)
        res[i] = '2';
      else
        res[i] = '1';
    }
  }
  string values1, values2;
  for (int i = 0; i < n; ++i) {
    if (res[i] == '1') values1 += string(1, seq[i]);
    else values2 += string(1, seq[i]);
  }
  if (!sorted(values1) || !sorted(values2))
    return "";
  return res;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    string seq(n, ' ');
    scanf(" %s", &seq[0]);
    string result = "-";
    for (int d = 0; d < 10; ++d) {
      string res = solve(seq, d);
      if (!res.empty()) {
        result = res;
        break;
      }
    }
    printf("%s\n", result.c_str());
  }
  return 0;
}