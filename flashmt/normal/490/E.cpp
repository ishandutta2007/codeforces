#include <bits/stdc++.h>
using namespace std;

string a[100100];
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  for (int j = 0; j < int(a[0].size()); j++)
    if (a[0][j] == '?')
      a[0][j] = !j ? '1' : '0';
  
  for (int i = 1; i < n; i++)
  {
    if (a[i].size() < a[i - 1].size())
    {
      cout << "NO" << endl;
      return 0;
    }
    
    if (a[i].size() > a[i - 1].size())
    {
      for (int j = 0; j < int(a[i].size()); j++)
        if (a[i][j] == '?')
          a[i][j] = !j ? '1' : '0';
      continue;
    }
    
    int cmp = 0, id = a[i].size();
    for (int j = 0; j < int(a[i].size()); j++)
      if (a[i][j] != '?' && a[i][j] != a[i - 1][j])
      {
        if (a[i][j] < a[i - 1][j]) cmp = -1;
        else cmp = 1;
        id = j;
        break;
      }
      
    if (cmp > 0)
    {
      for (int j = 0; j < int(a[i].size()); j++)
        if (a[i][j] == '?')
        {
          if (j > id) a[i][j] = '0';
          else a[i][j] = a[i - 1][j];
        }
    }
    else if (cmp < 0)
    {
      for (int j = int(a[i].size()) - 1; j >= 0; j--)
        if (a[i][j] == '?')
        {
          if (j > id) a[i][j] = '0';
          else if (cmp > 0) a[i][j] = a[i - 1][j];
          else if (a[i - 1][j] == '9') a[i][j] = '0';
          else 
          {
            a[i][j] = a[i - 1][j] + 1;
            cmp = 1;
          }
        }
    }
    else
    {
      for (int j = int(a[i].size()) - 1; j >= 0; j--)
        if (a[i][j] == '?')
        {
          if (cmp > 0) a[i][j] = a[i - 1][j];
          else if (a[i - 1][j] == '9') a[i][j] = '0';
          else 
          {
            a[i][j] = a[i - 1][j] + 1;
            cmp = 1;
          }
        }
    }
    
    if (cmp != 1)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << a[i] << '\n';
}