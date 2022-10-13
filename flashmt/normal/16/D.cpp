#include <bits/stdc++.h>
using namespace std;

int getTime(string s)
{
  int h = (s[0] - '0') * 10 + s[1] - '0';
  int m = (s[3] - '0') * 10 + s[4] - '0';
  h %= 12;
  if (s.back() == 'p')
    h += 12;
  return h * 60 + m;
}

int main()
{
  int n;
  string s;
  cin >> n;
  getline(cin, s);

  int last = -1, ans = 1, cnt = 0;
  while (n--)
  {
    string s;
    getline(cin, s);
    int t = getTime(s.substr(1, 7));
    if (t > last) cnt = 1;
    else if (t == last && cnt < 10) cnt++;
    else
    {
      cnt = 1;
      ans++;
    }
    last = t;
  }

  cout << ans << endl;
}