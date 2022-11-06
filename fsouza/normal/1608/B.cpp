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

vector<int> solve(int n, int nmax, int nmin) {
  if (nmax == nmin) {
    vector<int> result;
    int next = 0;
    result.push_back(next++);
    vector<int> lows, highs, highers;
    for (int i = 0; i < nmax; ++i)
      lows.push_back(next++);
    for (int i = 0; i < nmax; ++i)
      highs.push_back(next++);
    while (next < n)
      highers.push_back(next++);
    for (int i = 0; i < nmax; ++i) {
      result.push_back(highs.back());
      highs.pop_back();
      result.push_back(lows.back());
      lows.pop_back();
    }
    result.insert(result.end(), highers.begin(), highers.end());
    return result;
  } else {
    vector<int> highers, highs, lows;
    int next = n - 1;
    for (int i = 0; i < nmax; ++i)
      highers.push_back(next--);
    for (int i = 0; i < nmin; ++i)
      highs.push_back(next--);
    while (next >= 0)
      lows.push_back(next--);
    vector<int> result;
    result.push_back(lows.back());
    lows.pop_back();
    for (int i = 0; i < nmax; ++i) {
      result.push_back(highers.back());
      highers.pop_back();
      if (i < nmin) {
        result.push_back(highs.back());
        highs.pop_back();
      }
    }
    result.insert(result.end(), lows.begin(), lows.end());
    return result;
  }
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n, nmax, nmin;
    scanf("%d %d %d", &n, &nmax, &nmin);
    vector<int> result;
    if (abs(nmax - nmin) <= 1 && nmax + nmin <= n - 2) {
      if (nmax >= nmin) result = solve(n, nmax, nmin);
      else {
        result = solve(n, nmin, nmax);
        if (result[0] != -1) {
          for (int i = 0; i < n; ++i)
            result[i] = n - 1 - result[i];
        }
      }
    } else {
      result = {-1};
    }
    for (int i = 0; i < (int)result.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i] == -1 ? -1 : result[i] + 1);
    }
    printf("\n");
  }
  return 0;
}