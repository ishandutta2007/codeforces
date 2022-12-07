#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  int n, m, a[1000];
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    int q = -1;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'S') {
        if (q == -1) {
          cout << -1 << endl;
          return 0;
        } else {
          a[i] = j - q;
        }
      }
      if (s[j] == 'G') {
        q = j;
      }
    }
  }
  sort(a, a + n);
  int ans = 1;
  for (int i = 1; i < n; ++i)
    if (a[i] != a[i - 1])
      ++ans;
  cout << ans << endl;
  return 0;
}