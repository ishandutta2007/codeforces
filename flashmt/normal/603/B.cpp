#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  int p, k;
  cin >> p >> k;

  vector<int> flag(p);
  int group = 0;
  for (int i = 1; i < p; i++)
    if (!flag[i])
    {
      group++;
      long long x = i;
      while (!flag[x])
      {
        flag[x] = 1;
        x = x * k % p;
      }
    }

  if (k == 1)
    group++;
  long long ans = 1;
  for (int i = 0; i < group; i++)
    ans = ans * p % BASE;
  cout << ans << endl;
}