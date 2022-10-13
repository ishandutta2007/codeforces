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
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 1, cnt[2] = {0};
    for (int i = 0; i < k; i++)
    {
      char c = '?';
      for (int j = i; j < n; j += k)
        if (s[j] != '?')
        {
          if (c == '?') c = s[j];
          else if (s[j] != c) ans = 0;
        }

      if (c != '?')
        cnt[c - '0']++;
    }

    if (max(cnt[0], cnt[1]) > k / 2)
      ans = 0;

    cout << (ans ? "YES\n" : "NO\n");
  }
}