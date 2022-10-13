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
    string ans = "NO";
    for (int i = 2; i <= 4; i += 2)
    {
      int t = int(sqrt(n / i));
      if (t * t * i == n)
        ans = "YES";
    }
    cout << ans << '\n';
  }
}