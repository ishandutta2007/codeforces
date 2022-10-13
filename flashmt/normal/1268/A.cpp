#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  string a;
  cin >> n >> k >> a;

  int isGood = 1;
  for (int i = k; i < n; i++)
    if (a[i] > a[i - k])
    {
      isGood = 0;
      break;
    }
    else if (a[i] < a[i - k])
      break;

  string prefix = a.substr(0, k);
  if (!isGood)
    for (int i = k - 1; i >= 0; i--)
    {
      if (prefix[i] < '9')
      {
        prefix[i]++;
        break;
      }
      prefix[i] = '0';
    }

  cout << n << endl;
  for (int i = 0; i < n; i++)
    cout << prefix[i % k];
  cout << endl;
}