#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.rbegin(), a.rend());
  vector <int> b;
  for (int i = 0; i < a.size(); i++) {
    b.push_back(a[i]);
    if (i + 1 != a.size()) {
      b.push_back(a.back());
      a.pop_back();
    }
  }
  cout << (n - 1) / 2 << '\n';
  for (auto &now : b)
    cout << now << ' ';
  return 0;
}