#include <bits/stdc++.h>
using namespace std;

int n, p;
string s;

string solve(int id)
{
  set <char> has;
  if (id) has.insert(s[id - 1]);
  if (id > 1) has.insert(s[id - 2]);
  string t = s;
  t[id]++;
  while (has.count(t[id]) && t[id] - 'a' < p) t[id]++;
  if (t[id] - 'a' == p) return "";
  
  for (int i = id + 1; i < n; i++)
  {
    int ok = 0;
    for (int ch = 0; ch < p; ch++)
    {
      char c = char('a' + ch);
      if (c != t[i - 1] && (i < 2 || c != t[i - 2]))
      {
        t[i] = c;
        ok = 1;
        break;
      }
    }
    
    if (!ok) return "";
  }
  
  return t;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> p >> s;
  for (int i = n - 1; i >= 0; i--)
  {
    string t = solve(i);
    if (t != "") 
    {
      cout << t << endl;
      return 0;
    }
  }
  
  cout << "NO" << endl;
}