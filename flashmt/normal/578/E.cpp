#include <bits/stdc++.h>
using namespace std;

string s;
int n, numPath;
vector <int> st[2][2];
vector <int> path[100100];

void update(int start, int c, int i)
{
  int id = st[start][c ^ 1].back();
  path[id].push_back(i);
  st[start][c].push_back(id);
  st[start][c ^ 1].pop_back();
}

void write(int start, int end)
{
  for (auto id : st[start][end])
    for (auto x : path[id])
      cout << x << ' ';
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> s;
  n = s.size();  
  
  for (int i = 0; i < n; i++)
  {
    int c = s[i] == 'R';
    if (!st[c][c ^ 1].empty()) update(c, c, i + 1);
    else if (!st[c ^ 1][c ^ 1].empty()) update(c ^ 1, c, i + 1);
    else
    {
      path[numPath].push_back(i + 1);
      st[c][c].push_back(numPath++); 
    }
  }

  cout << numPath - 1 << endl;

  if (st[0][1].size() == numPath) write(0, 1);
  else if (st[1][0].size() == numPath) write(1, 0);
  else
  {
    assert(st[0][0].size() + st[1][1].size() > 0);

    if (st[0][0].empty())
    {
      write(1, 0);
      write(1, 1);
      write(0, 1);
    }
    else if (st[1][1].empty())
    {
      write(0, 1);
      write(0, 0);
      write(1, 0);
    }
    else
    {
      for (auto id : st[0][1])
        for (auto x : path[id])
          path[st[1][1][0]].push_back(x);

      for (auto id : st[1][0])
        for (auto x : path[id])
          path[st[0][0][0]].push_back(x);

      int cur = 0;
      if (st[0][0].size() > st[1][1].size())
      {
        for (auto x : path[st[0][0].back()])
          cout << x << ' ';
        st[0][0].pop_back();
        cur = 1;
      }

      if (st[1][1].size() > st[0][0].size())
      {
        for (auto x : path[st[1][1].back()])
          cout << x << ' ';
        st[1][1].pop_back();
      }

      assert(st[0][0].size() == st[1][1].size());
      for (int i = 0; i < st[0][0].size(); i++)
      {
        for (auto x : path[st[cur][cur][i]])
          cout << x << ' ';
        for (auto x : path[st[cur ^ 1][cur ^ 1][i]])
          cout << x << ' ';
      }
    }
  }
}