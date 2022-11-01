#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int m = 0, g = 0;
  for (int i = 0; i < n; i++)
    m = max(m, a[i]), g = __gcd(g, a[i]);
  int k = m / g - n;
  if (k % 2)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}