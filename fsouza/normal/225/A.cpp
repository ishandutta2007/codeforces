#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int n;
  int top;
  bool ok = true;

  cin >> n >> top;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == top || b == top || a == 7-top || b == 7-top) ok = false;
  }

  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}