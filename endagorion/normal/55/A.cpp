#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> used(n, false);
  used[0] = true;
  int cur = 0;
  for (int i = 1; i < n * n; ++i) {
    cur = (cur + i) % n;
    used[cur] = true;
  }
  bool good = true;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      good = false;
    }
  }
  if (good) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}