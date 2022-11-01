#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <int> b;
  for (int i = 0; i + 1 < n; i++)
    b.push_back(a[i + 1] - a[i]);
  sort(b.begin(), b.end());
  int sum = 0;
  for (int i = 0; i < n - k; i++)
    sum += b[i];
  cout << sum + k;
  return 0;
}