#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k, cnt[10] = {0}, ans = 0;
  string s;
  cin >> k >> s;
  for (int i = 0; i < s.size(); i++)
  {
    k -= s[i] - '0';
    cnt['9' - s[i]]++;
  }
  for (int digit = 9; digit && k > 0; digit--)
  {
    int use = min(cnt[digit], (k + digit - 1) / digit);
    k -= use * digit;
    ans += use;
  }
  cout << ans << endl;
}