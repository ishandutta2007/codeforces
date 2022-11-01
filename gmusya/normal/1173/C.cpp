#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector <int> p(n + 1);
  for (int i = 0; i < n; i++)
    p[b[i]] = i + 1;
  if (p[1]) {
    int pos = 2;
    while (pos <= n && p[pos] == p[1] + pos - 1)
      pos++;
    if (p[pos - 1] == n) {
      int i = pos;
      while (i <= n && p[i] <= i - pos)
        i++;
      if (i > n) {
        cout << n - pos + 1;
        return 0;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, p[i] + n - (i - 1));
  cout << ans;
  return 0;
}