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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      a[x]++;
    }
    sort(a.begin(), a.end());
    int val = a.back();
    while (a[n - 1] == val)
      n--;
    cout << n / (val - 1) - 1 << '\n';
  }
  return 0;
}