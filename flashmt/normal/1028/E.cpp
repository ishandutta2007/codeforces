#include <bits/stdc++.h>
using namespace std;

int n, b[200200];

void solve(int id)
{
  vector<long long> a(n);
  a[id] = b[id];
  int i = id, isGreater = 0;
  while (1)
  {
    i = (i + n - 1) % n;
    if (i == id)
      break;
    if (b[i] || isGreater)
    {
      a[i] = b[i] + a[(i + 1) % n];
      isGreater = 1;
    }
    else
    {
      a[i] = a[(i + 1) % n] * 2;
      isGreater = 1;
    }
  }

  cout << "YES\n";
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  int maxB = *max_element(b, b + n);
  if (!maxB)
  {
    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << 1 << " \n"[i == n - 1];
    return 0;
  }

  for (int i = 0; i < n; i++)
    if (b[i] == maxB && b[(i + n - 1) % n] != maxB)
      solve(i);

  cout << "NO\n";
}