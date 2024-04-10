#include <algorithm>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  vector<string> good12, good24;

  for (int h = 1; h <= 12; ++h)
    for (int m = 0; m < 60; ++m) {
      char buf[32];
      snprintf(buf, 32, "%02d:%02d", h, m);
      good12.push_back(string(buf));
    }

  for (int h = 0; h < 24; ++h)
    for (int m = 0; m < 60; ++m) {
      char buf[32];
      snprintf(buf, 32, "%02d:%02d", h, m);
      good24.push_back(string(buf));
    }

  int kind;
  string str;
  cin >> kind >> str;

  vector<string> &good = (kind == 12 ? good12 : good24);
  int result = INT_MAX;
  string resultstr;

  for (const string &cand : good) {
    int ndiff = 0;
    for (int i = 0; i < (int)str.size(); ++i)
      ndiff += (str[i] != cand[i]);
    if (ndiff < result) {
      result = ndiff;
      resultstr = cand;
    }
  }

  cout << resultstr << endl;

  return 0;
}