#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] += i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++)
    a[i] -= i;
  for (int i = 0; i + 1 < n; i++)
    if (a[i] > a[i + 1]) {
      cout << ":(";
      return 0;
    }
  for (auto &now : a)
    cout << now << ' ';
  return 0;
}