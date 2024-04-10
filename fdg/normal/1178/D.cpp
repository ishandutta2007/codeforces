#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}

vector<pair<int, int>> solve(int n) {
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    v.push_back({i, (i + 1) % n});
  }

  int ptr = 2;
  while (!isPrime(v.size())) {
    if (ptr >= n) return vector<pair<int, int>>();
    v.push_back({ptr - 2, ptr});
    if (ptr % 2 == 0) ++ptr;
    else ptr += 3;
  }
  return v;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> ret = solve(n);
  cout << ret.size() << endl;
  for (pair<int, int> p : ret) {
    cout << p.first + 1 << " " << p.second + 1 << endl;
  }

  // for (int t = 3; t <= 1000; ++t)
  //   if (solve(t).size() == 0)
  //     cout << "Fail " << t << endl;
  return 0;
}