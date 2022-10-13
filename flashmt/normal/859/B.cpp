#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ans = 1 << 30;
  cin >> n;
  for (int i = 1; i <= n; i++)
    ans = min(ans, i + (n + i - 1) / i);
  cout << ans * 2 << endl;
}