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

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int main() {
  string s = read_string();

  int max_seq = 0;
  int seq = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i - 1 >= 0 && s[i] != s[i - 1]) {
      ++seq;
    } else {
      seq = 1;
    }
    max_seq = max(max_seq, seq);
  }

  int pref = 0;
  for (int i = 0; i < (int)s.size(); ++i)
    if (i - 1 < 0 || s[i] != s[i - 1]) ++pref;
    else break;

  int suf = 0;
  for (int i = (int)s.size() - 1; i >= 0; --i)
    if (i + 1 >= (int)s.size() || s[i] != s[i + 1]) ++suf;
    else break;

  int result = max_seq;
  if (s.front() != s.back())
    result = max(result, min(pref + suf, (int)s.size()));
  printf("%d\n", result);

  return 0;
}