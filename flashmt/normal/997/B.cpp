#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> flag(49);
  long long ans = 0;
  for (int i = 0; i < 49; i++)
    for (int j = 0; j < 9; j++)
    {
      int x = i * 9 + j * 4;
      if (!flag[x % 49] && i + j <= n)
      {
        flag[x % 49] = 1;
        ans += n - i - j + 1;
      }
    }
  cout << ans << endl;
}