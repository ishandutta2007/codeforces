#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <int> a(k);
    for (int i = 0; i < k; i++)
      a[i] = i + 1;
    reverse(a.begin() + 2 * k - n - 1, a.end());
    for (auto &now : a)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}