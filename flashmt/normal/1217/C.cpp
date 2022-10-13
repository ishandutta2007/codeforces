#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    vector<int> sum(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      sum[i] = sum[i - 1] + s[i] - '0';
      int value = 0;
      for (int j = i; j > 0 && i - j < LOG; j--)
      {
        if (s[j] == '1')
          value |= 1 << (i - j);
        ans += value == i - j + 1;
      }

      if (value > LOG && i >= value && sum[i - LOG] == sum[i - value])
        ans++;
    }

    cout << ans << endl;
  }
}