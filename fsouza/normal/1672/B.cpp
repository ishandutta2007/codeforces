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

  int nt;
  cin >> nt;
  for (int t = 0; t < nt; ++t) {
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    int score = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A') ++score;
      else --score;
      if (score < 0) {
        ok = false;
        break;
      }
    }
    if (n < 2 || s.back() != 'B') ok = false;
    if (ok) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}