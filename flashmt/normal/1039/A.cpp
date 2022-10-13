#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 62;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x[200200];
  long long t, a[200200], b[200200], maxB[200200];

  cin >> n >> t;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[i] = a[i] + t;
    maxB[i] = oo;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
    x[i]--;
  }

  x[n] = n;
  for (int i = 0; i < n; i++)
    if (x[i] < i || x[i] > x[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }


  for (int i = 0, j = 0; i < n; i++)
  {
    // ensure x[i] is valid
    if (x[i] > i) // update b[i] to b[x[i] - 1]
    {
      j = max(j, i);
      while (j < x[i])
      {
        b[j] = a[j + 1] + t;
        j++;
      }
    }
    // ensure x[i] can't be increased
    if (x[i] + 1 < n)
      maxB[x[i]] = min(maxB[x[i]], a[x[i] + 1] + t - 1);
  }

  for (int i = 0; i < n; i++)
  {
    if (i)
      b[i] = max(b[i], b[i - 1] + 1);
    if (b[i] > maxB[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  for (int i = 0; i < n; i++)
    cout << b[i] << ' ';
}