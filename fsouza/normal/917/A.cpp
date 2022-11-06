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
  string s;
  cin >> s;
  int result = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    int closed_question = 0, delta = 0;
    for (int j = i; j < (int)s.size(); ++j) {
      if (s[j] == '(') ++delta;
      else if (s[j] == ')') --delta;
      else {
        ++closed_question;
        --delta;
      }
      while (delta < 0 && closed_question > 0) {
        --closed_question;
        delta += 2;
      }
      if (delta < 0) break;
      if (delta == 0) ++result;
    }
  }
  printf("%d\n", result);
  return 0;
}