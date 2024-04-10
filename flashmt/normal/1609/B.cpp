#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;

  auto isAbc = [&](int i) -> int
  {
    if (i < 0 || i + 3 > n)
      return 0;
    return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
  };

  int cnt = 0;
  for (int i = 0; i + 3 <= n; i++)
    cnt += isAbc(i);

  while (q--)
  {
    int x;
    char c;
    cin >> x >> c;
    x--;
    for (int i = x - 2; i <= x; i++)
      cnt -= isAbc(i);
    s[x] = c;
    for (int i = x - 2; i <= x; i++)
      cnt += isAbc(i);
    cout << cnt << '\n';
  }
}