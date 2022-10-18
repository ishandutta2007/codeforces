#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

void solve() {
  char f[22];
  scanf("\nIAO'%s", f);
  string s = f;
  long long year = 1988;

  long long suf = 0, mult = 1;
  while (s.size()) {
    suf += mult * (s.back() - '0');
    mult *= 10;
    s.pop_back();

    long long l = -1, r = 1e+10;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (m * mult + suf > year) r = m;
      else l = m;
    }
    year = r * mult + suf;
  }
  cout << year << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--)
    solve();
  return 0;
}