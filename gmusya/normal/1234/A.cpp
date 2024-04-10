#include <iostream>
#include <vector>

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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int sum = 0;
    for (int x : a)
      sum += x;
    cout << (sum + n - 1) / n << '\n';
  }
  return 0;
}