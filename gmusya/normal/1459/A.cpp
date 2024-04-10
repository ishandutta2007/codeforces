#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      b[i] = c - '0';
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i])
        continue;
      if (a[i] < b[i])
        sum++;
      else
        sum--;
    }
    if (sum < 0)
      cout << "RED\n";
    if (sum == 0)
      cout << "EQUAL\n";
    if (sum > 0)
      cout << "BLUE\n";
  }
  return 0;
}