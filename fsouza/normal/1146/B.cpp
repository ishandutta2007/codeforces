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

void impossible() {
  printf(":(\n");
  exit(0);
}

int main() {
  string s;
  cin >> s;
  string non_a;
  for (char c : s)
    if (c != 'a')
      non_a += string(1, c);

  if (non_a.size() % 2 != 0)
    impossible();

  string non_a_h1 = non_a.substr(0, non_a.size() / 2);
  string non_a_h2 = non_a.substr(non_a.size() / 2, non_a.size() / 2);
  if (non_a_h1 != non_a_h2)
    impossible();

  if (non_a.size() == 0) {
    cout << s << "\n";
    return 0;
  }

  int start = -1;
  int remain = non_a.size() / 2;
  for (int i = 0; i < (int)s.size(); ++i)
    if (s[i] != 'a') {
      --remain;
      if (remain == -1) {
        start = i;
        break;
      }
    }
  assert(start != -1);

  for (int i = start; i < (int)s.size(); ++i)
    if (s[i] == 'a')
      impossible();

  string result = s.substr(0, start);
  cout << result << "\n";

  return 0;
}