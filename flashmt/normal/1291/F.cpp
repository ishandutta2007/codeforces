#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

char taste(int x)
{
  cout << "? " << x + 1 << endl;
  cout.flush();
  char resp;
  cin >> resp;
  return resp;
}

void reset()
{
  cout << "R" << endl;
}

int main()
{
  int n, k;
  cin >> n >> k;
  if (k > 1)
    k /= 2;
  int block = n / k;

  vector<int> flag(n, 1);
  for (int i = 0; i < n; i++)
    if (taste(i) == 'Y')
      flag[i] = 0;

  reset();

  for (int i = 0; i < block; i++)
    for (int j = i + 2; j < block; j++)
    {
      for (int u = 0; u < k; u++)
        if (flag[i * k + u])
          taste(i * k + u);
      for (int u = 0; u < k; u++)
        if (flag[j * k + u])
          if (taste(j * k + u) == 'Y')
            flag[j * k + u] = 0;

      reset();
    }

  int ans = accumulate(begin(flag), end(flag), 0);
  cout << "! " << ans << endl;
  cout.flush();
}