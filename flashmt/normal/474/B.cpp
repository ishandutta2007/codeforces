#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x, Q, a[100100];
  
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  
  cin >> Q;
  while (Q--)
  {
    cin >> x;
    cout << lower_bound(a + 1, a + n + 1, x) - a << '\n'; 
  }
}