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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, nq;
  cin >> n >> nq;
  string s;
  cin >> s;

  const string target = "abc";

  vector<int> is_match(n, 0);
  int nmatch = 0;
  for (int i = 0; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < (int)target.size(); ++j) {
      if (!(i + j < n && s[i + j] == target[j])) {
        ok = false;
        break;
      }
    }
    if (ok) {
      is_match[i] = 1;
      nmatch += 1;
    }
  }

  for (int q = 0; q < nq; ++q) {
    int pos;
    char new_c;
    cin >> pos; --pos;
    cin >> new_c;

    int from = max(pos - (int)target.size() - 1, 0);
    int to = pos;

    for (int i = from; i <= to; ++i) {
      nmatch -= is_match[i];
      is_match[i] = 0;
    }

    s[pos] = new_c;

    for (int i = from; i <= to; ++i) {
      bool ok = true;
      for (int j = 0; j < (int)target.size(); ++j) {
        if (!(i + j < n && s[i + j] == target[j])) {
          ok = false;
          break;
        }
      }
      if (ok) {
        is_match[i] = 1;
        nmatch += 1;
      }
    }

    printf("%d\n", nmatch);
  }

  return 0;
}