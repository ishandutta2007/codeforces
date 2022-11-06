#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int k;
  string s;

  cin >> k >> s;

  string part;
  bool ok = true;

  for (char c = 'a'; c <= 'z'; c++) {
    int m = count(s.begin(), s.end(), c);
    if (m % k != 0) {
      ok = false;
      break;
    }
    part += string(m/k, c);
  }

  if (!ok) {
    cout << -1 << endl;
  } else {
    string ret;
    for (int i = 0; i < k; i++) ret += part;
    cout << ret << endl;
  }

  return 0;
}