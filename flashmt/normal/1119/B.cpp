#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, h, a[1010];
  cin >> n >> h;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0, bottles[1010];
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
      bottles[j] = a[j];
    sort(bottles, bottles + i);
    long long sumH = 0;
    for (int j = i - 1; j >= 0; j -= 2)
      sumH += bottles[j];
    if (sumH <= h)
      ans = i;
  }
  cout << ans << endl;
}