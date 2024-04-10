#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int G[] = {0, 1, 0, 1, 2};

int grundy(int x)
{
  if (x <= 4)
    return G[x];
  if (x % 2)
    return 0;
  return grundy(x / 2) == 1 ? 2 : 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  if (k % 2 == 0)
  {
    for (int x : a)
      if (x == 1) ans ^= 1;
      else if (x == 2) ans ^= 2;
      else ans ^= x % 2 ^ 1;
  }
  else
  {
    for (int x : a)
      ans ^= grundy(x);
  }

  cout << (ans ? "Kevin" : "Nicky") << endl;
}