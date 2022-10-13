#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x, a[1000100] = {0};
  cin >> n;
  while (n--)
  {
    cin >> x;
    a[x]++;
  }  

  int ans = 0;
  for (int i = 0; i <= 1000050; i++)
  {
    a[i + 1] += a[i] / 2;
    a[i] %= 2;
    ans += a[i];
  }
  cout << ans << endl;
}