#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::string;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> have(2);
  for (int& x : a) {
    cin >> x;
    have[x % 2] = true;
  }
  if (have[0] && have[1]) {
    std::sort(a.begin(), a.end());
  }
  for (int x : a) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}