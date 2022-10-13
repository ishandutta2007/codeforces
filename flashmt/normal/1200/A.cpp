#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, rooms[10] = {0};
  string s;
  cin >> n >> s;
  for (char c : s)
    if (c == 'L')
    {
      for (int i = 0; i < 10; i++)
        if (!rooms[i])
        {
          rooms[i] = 1;
          break;
        }
    }
    else if (c == 'R')
    {
      for (int i = 9; i >= 0; i--)
        if (!rooms[i])
        {
          rooms[i] = 1;
          break;
        }
    }
    else rooms[c - '0'] = 0;
  for (int i = 0; i < 10; i++)
    cout << rooms[i];
}