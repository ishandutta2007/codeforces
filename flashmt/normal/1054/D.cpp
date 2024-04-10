#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, a = 0;
  map<int, int> m;
  m[0] = 1;
  cin >> n >> k;
  int maxA = (1 << k) - 1;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a ^= x;
    m[min(a, maxA ^ a)]++;
  }

  long long ans = n * (n + 1LL) / 2;
  for (auto [_, cnt] : m)
  {
    int x = cnt / 2, y = cnt - x;
    ans -= x * (x - 1LL) / 2 + y * (y - 1LL) / 2;
  }
  cout << ans << endl;
}