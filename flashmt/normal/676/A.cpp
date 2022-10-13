#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[111], x, y;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] == 1) 
      x = i;
    if (a[i] == n)
      y = i;
  }

  cout << max(max(x, y), n - 1 - min(x, y)) << endl;
}