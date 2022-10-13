#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  
  int ans = 0;
  for (int floor = 1; floor * (floor - 1LL) / 2 <= n; floor++)
    if ((n - floor * 2) % 3 == 0)
      if ((n - floor * 2) / 3 >= floor * (floor - 1LL) / 2)
        ans++;
  
  cout << ans << endl;
}