#include <bits/stdc++.h>
using namespace std;

map <int, int> g;

int grundy(int mask)
{
  if (!mask)
    return 0;
  if (g.count(mask))
    return g[mask];

  set <int> flag;
  for (int i = 0; i < 30; i++)
    if (1 << i <= mask)
    {
      int newMask = (mask >> i + 1) | (mask & (1 << i) - 1);
      if (newMask < mask)
        flag.insert(grundy(newMask));
    }

  g[mask] = 0;
  while (flag.count(g[mask]))
    g[mask]++;

  return g[mask];
}

int main()
{
  int n, x, a[111];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int ans = 0;
  for (int prime = 2; prime < 100000; prime++)
  {
    int mask = 0;
    for (int i = 0; i < n; i++)
      if (a[i] % prime == 0)
      {
        int power = 0;
        while (a[i] % prime == 0)
        {
          a[i] /= prime;
          power++;
        }
        mask |= 1 << power - 1;
      }

    ans ^= grundy(mask);
  }  

  set <int> s;
  for (int i = 0; i < n; i++)
    if (a[i] > 1)
      s.insert(a[i]);
  ans ^= s.size() % 2;

  cout << (ans ? "Mojtaba" : "Arpa") << endl;
}