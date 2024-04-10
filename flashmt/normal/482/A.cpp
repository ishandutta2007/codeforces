#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int x = k + 1, sign = -1;
  for (int i = n; i >= x; i--) cout << i << ' ';
  for (int i = k; i; i--)
  {
    x += i * sign;
    sign = -sign;
    cout << x << ' ';
  }
}