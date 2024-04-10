#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<long long> divs;

int lft = 100000;

void out() {
  --lft;
  if (lft == 0) {
    cout << endl;
    exit(0);
  }
}

void go(long long x, int k) {
  if (x == 1 || k == 0) {
    cout << x << " ";
    out();
    return;
  }
  for (int i = 0; i < divs.size() && divs[i] <= x; ++i)
    if (x % divs[i] == 0)
      go(divs[i], k - 1);
}

int main() {
  ios::sync_with_stdio(false);
  long long x, k;
  cin >> x >> k;
  if (x == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (k >= 100001) {
    for (int i = 0; i < 100000; ++i)
      cout << 1 << " ";
    cout << endl;
    return 0;
  }
  for (int i = 1; 1LL * i * i <= x; ++i)
    if (x % i == 0) {
      divs.push_back(i);
      if (1LL * i * i != x)
        divs.push_back(x / i);
    }
  sort(divs.begin(), divs.end());
  go(x, k);
  cout << endl;
  return 0;
}