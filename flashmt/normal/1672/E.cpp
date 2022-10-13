#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int ask(int w)
{
  cout << "? " << w << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp;
}

int main()
{
  int n;
  cin >> n;
  int low = n, high = n * 2000, sum = high;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (ask(mid + n - 1) == 1)
    {
      sum = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  int ans = sum + n - 1;
  vector<int> d;
  for (int i = 2; i <= n; i++)
    for (int j = sum + n - i; j < sum + n - 1; j++)
      if (j % i == 0)
        d.push_back(j / i);
  sort(begin(d), end(d));
  d.resize(unique(begin(d), end(d)) - begin(d));
  assert(size(d) <= n);
  for (int w : d)
  {
    int h = ask(w);
    if (h)
      ans = min(ans, h * w);
  }

  cout << "! " << ans << endl;
  cout.flush();
}