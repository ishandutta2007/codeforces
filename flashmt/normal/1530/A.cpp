#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    int ans = 0;
    while (n)
    {
      ans = max(ans, n % 10);
      n /= 10;
    }
    cout << ans << endl;
  }
}