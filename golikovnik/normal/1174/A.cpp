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
  n *= 2;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  std::sort(a.begin(), a.end());
  if (a[0] == a[n - 1]) {
    cout << "-1\n";
    return 0;
  }
  for (int x : a) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}