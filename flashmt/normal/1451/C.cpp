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
    int n, k, cnt[26] = {0};
    string a, b;
    cin >> n >> k >> a >> b;
    for (char c : a)
      cnt[c - 'a']--;
    for (char c : b)
      cnt[c - 'a']++;

    int has = 0;
    string ans = "Yes";
    for (int i = 0; i < 26; i++)
      if (cnt[i] % k)
      {
        ans = "No";
        break;
      }
      else if (has < cnt[i])
      {
        ans = "No";
        break;
      }
      else has -= cnt[i];

    cout << ans << '\n';
  }
}