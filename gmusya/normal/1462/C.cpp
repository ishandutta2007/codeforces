#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (x > 45) {
      cout << -1 << '\n';
      continue;
    }
    int cur = 9;
    vector <int> a;
    while (x > cur) {
      a.push_back(cur);
      x -= cur;
      cur--;
    }
    a.push_back(x);
    reverse(a.begin(), a.end());
    for (auto &now : a)
      cout << now;
    cout << '\n';
  }
  return 0;
}