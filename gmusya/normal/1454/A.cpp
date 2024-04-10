#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    iota(a.begin(), a.end(), 1);
    rotate(a.begin(), a.begin() + 1, a.end());
    for (auto &now : a)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}