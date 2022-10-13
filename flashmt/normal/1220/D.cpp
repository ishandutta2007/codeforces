#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, cnt[66] = {0};
  long long a[200200];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    for (int j = 0; j < 60; j++)
      if (a[i] >> j & 1)
      {
        cnt[j]++;
        break;
      }
  }

  int idMax = 0;
  for (int i = 1; i < 60; i++)
    if (cnt[i] > cnt[idMax])
      idMax = i;

  cout << n - cnt[idMax] << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 60; j++)
      if (a[i] >> j & 1)
      {
        if (j != idMax)
          cout << a[i] << ' ';
        break;
      }
}