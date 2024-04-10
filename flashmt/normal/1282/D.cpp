#include <bits/stdc++.h>
using namespace std;

int ask(string s)
{
  cout << s << endl;
  cout.flush();
  int resp;
  cin >> resp;
  if (!resp)
    exit(0);
  return resp;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a = 300 - ask(string(300, 'a'));
  int b = 300 - ask(string(300, 'b'));
  int lastResp = a;
  string ans;
  while (a && b)
  {
    string s = ans + "a" + string(b, 'b');
    int resp = ask(s);
    if (resp < lastResp)
    {
      ans += 'a';
      a--;
      lastResp = resp;
    }
    else
    {
      ans += 'b';
      b--;
    }
  }
  while (a--)
    ans += 'a';
  while (b--)
    ans += 'b';
  ask(ans);
}