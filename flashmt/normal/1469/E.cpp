#include <bits/stdc++.h>
using namespace std;

int n, k, flag[1 << 20], cnt0[1 << 20];
string a;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cin >> n >> k >> a;
    a = " " + a;
    for (int i = 1; i <= n; i++)
      cnt0[i] = cnt0[i - 1] + (a[i] == '0');

    int suffix = min(20, k), allOne = (1 << suffix) - 1;
    for (int i = 1, mask = 0; i <= n; i++)
    {
      mask = mask * 2 + a[i] - '0';
      if (i >= k && cnt0[i - suffix] == cnt0[i - k])
        flag[allOne ^ mask] = iTest;
      mask &= (1 << suffix - 1) - 1;
    }

    int ans = -1;
    for (int mask = 0; mask < 1 << suffix; mask++)
      if (flag[mask] != iTest)
      {
        ans = mask;
        break;
      }

    if (ans < 0) cout << "NO\n";
    else
    {
      cout << "YES\n";
      for (int i = 0; i < k - suffix; i++)
        cout << 0;
      for (int i = suffix - 1; i >= 0; i--)
        cout << (ans >> i & 1);
      cout << '\n';
    }
  }
}