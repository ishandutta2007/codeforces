#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100], b[100];
  string s;

  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];

  int ans = 0;
  for (int i = 0; i <= 1000; i++)
  {
    for (int j = 0; j < n; j++)
      if (i >= b[j] && (i - b[j]) % a[j] == 0)
        s[j] = s[j] ^ '0' ^ '1';

    int cnt = 0;
    for (char c : s)
      cnt += c - '0';
    ans = max(ans, cnt);
  }

  cout << ans << endl;
}