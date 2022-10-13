#include <bits/stdc++.h>
using namespace std;

string a[111];
int n, b[26][26], charRank[26], order[26];

int cmp(string s, string t)
{
  for (int i = 0; i < s.size() && i < t.size(); i++)
    if (s[i] != t[i])
    {
      if (charRank[s[i] - 'a'] < charRank[t[i] - 'a']) return 1;
      return 0;
    }
  return s.size() <= t.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = 0; k < a[i].size() && k < a[j].size(); k++)
        if (a[i][k] != a[j][k])
        {
          b[a[i][k] - 'a'][a[j][k] - 'a'] = 1;
          break;
        }
        
  memset(charRank, -1, sizeof charRank);
  for (int i = 0; i < 26; i++)
  {
    int id = -1;
    for (int c = 0; c < 26; c++)
    {
      int ok = 1;
      if (charRank[c] >= 0) continue;
      for (int cc = 0; cc < 26; cc++)
        if (charRank[cc] < 0 && b[cc][c])
          ok = 0;
      
      if (ok) 
      {
        id = c;
        break;
      }
    }
    
    if (id < 0)
    {
      cout << "Impossible\n";
      return 0;
    }
    
    charRank[id] = i;
    order[i] = id;
  }
  
  for (int i = 0; i + 1 < n; i++)
    if (!cmp(a[i], a[i + 1]))
    {
      cout << "Impossible\n";
      return 0;
    }
    
  for (int i = 0; i < 26; i++) cout << char('a' + order[i]);
}