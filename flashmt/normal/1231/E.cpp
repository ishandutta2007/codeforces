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
    string s, t;
    cin >> n >> s >> t;
    int cnt[128] = {0};
    for (char c : s)
      cnt[c]++;
    for (char c : t)
      cnt[c]--;

    int isBad = 0;
    for (char c = 'a'; c <= 'z'; c++)
      isBad |= cnt[c] != 0;
    if (isBad)
    {
      cout << -1 << endl;
      continue;
    }

    int ans = n;
    for (int i = 0; i < n; i++)
    {
      int j = i, k = 0;
      while (j < n)
      {
        while (k < n && s[k] != t[j])
          k++;
        if (k >= n)
          break;
        j++;
        k++;
      }
      ans = min(ans, n - (j - i));
    }

    cout << ans << endl;
  }
}