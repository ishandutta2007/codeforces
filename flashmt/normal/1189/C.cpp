#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, a[100001], x, q, l, r;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  
  cin >> q;
  while (q--)
  {
    cin >> l >> r;
    cout << (a[r] - a[l - 1]) / 10 << '\n';
  }
}