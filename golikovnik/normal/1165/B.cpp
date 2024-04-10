#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::string;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  std::vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  std::sort(a.begin(), a.end());
  int days = 0;
  int i = 0;
  for (; i < n; i++) {
    while (i < n && a[i] <= days) {
      i++;
    }
    if (i == n) {
      break;
    }
    days++;
  }
  cout << days << "\n";
  return 0;
}