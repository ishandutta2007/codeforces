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

bool is_palim(const string &s) {
  int n = s.size();
  for (int i = 0, j = n - 1; i < j; ++i, --j)
    if (s[i] != s[j])
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  int result;

  if (n % 2 == 0 && s == string(s.size(), s[0])) {
    result = -1;
  } else if (n % 2 == 1 && s.substr(0, (s.size() - 1) / 2) == string((s.size() - 1) / 2, s[0])) {
    result = -1;
  } else {
    result = 2;
    for (int i = 1; i < n; ++i) {
      string left = s.substr(0, i);
      string right = s.substr(i);
      string news = right + left;
      if (news != s && is_palim(news)) {
        result = 1;
        break;
      }
    }
  }

  if (result == -1) printf("Impossible\n");
  else printf("%d\n", result);

  return 0;
}