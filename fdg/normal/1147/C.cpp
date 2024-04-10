#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

void go(int who) {
  cout << (who ? "Alice" : "Bob") << endl;
  exit(0);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  for (int x = 1; x <= 55; ++x) {
    int cnt = 0;
    for (int a : v)
      if (a == x) ++cnt;
    if (cnt > n / 2) go(0);
    else if (cnt > 0) go(1);
  }
  return 0;
}