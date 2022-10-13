#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 2; i <= 60; i++)
    for (int j = 0; j + 1 < i; j++) 
    {
      long long x = (1LL << i) - 1 - (1LL << j);
      if (a <= x && x <= b) 
        ans++;
    }
  cout << ans << endl;
}