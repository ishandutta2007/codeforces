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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    int ndiff = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != sorted_s[i]) {
        ++ndiff;
      }
    }
    printf("%d\n", ndiff);
  }

  return 0;
}