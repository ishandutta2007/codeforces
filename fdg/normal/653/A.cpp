#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n;
  set<int> f;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    f.insert(a);
  } 
  for (int x : f) {
    if (f.count(x + 1) && f.count(x + 2)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}