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
  vector <int> c;
  for (int i = 0; i < a.size(); i++) {
    b.push_back(a[i]);
    if (i + 1 != a.size()) {
      b.push_back(0);
      c.push_back(a.back());
      a.pop_back();
    }
  }
  int it;
  if (n % 2) it = n - 2;
  else it = n - 1;
  int x = 1;
  int ans = 0;
  reverse(c.begin(), c.end());
  for (int i = 0; i < c.size(); i++) {
    if (x + 1 < n && b[x - 1] > c[i] && c[i] < b[x + 1])
      b[x] = c[i], x += 2, ans++;
    else
      b[it] = c[i], it -= 2;
  }
  cout << ans << '\n';
  for (auto &now : b)
    cout << now << ' ';
  return 0;
}