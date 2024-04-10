#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n, a[100], b[100];
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  cout << *max_element(a, a + m) << ' ' << *max_element(b, b + n) << endl;
}