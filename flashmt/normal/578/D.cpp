#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m;
  string s;

  cin >> n >> m >> s;
  int block = 0;
  for (int i = 0; i < n;)
  {
    int j = i + 1;
    while (j < n && s[j] == s[i]) j++;
    block++;
    i = j;
  }

  long long ans = (m - 1LL) * n * block;
  for (int i = 0; i + 1 < n;)
    if (s[i] == s[i + 1]) i++;
    else
    {
      int j = i + 2;
      while (j < n && s[j] == s[j - 2]) j++;
      ans -= (j - i) * (j - i - 1LL) / 2;
      i = j - 1;
    }

  cout << ans << endl;
}