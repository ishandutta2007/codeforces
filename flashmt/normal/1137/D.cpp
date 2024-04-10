#include <bits/stdc++.h>
using namespace std;

int dist[10], where[10];

void move(vector<int> a)
{
  cout << "next ";
  for (int x : a)
  {
    dist[x]++;
    cout << x << ' ';
  }
  cout << endl;
  cout.flush();
}

void response()
{
  string s;
  getline(cin, s);
  memset(where, -1, sizeof where);
  int id = 0;
  for (char c : s)
    if (c == ' ') id++;
    else where[c - '0'] = id;
}

void findCycle()
{
  for (int i = 1;; i++)
  {
    move({1});
    response();
    move({0, 1});
    response();
    if (where[0] == where[1])
      return;
  }
  assert(0);
}

int main()
{
  findCycle();
  vector<int> all;
  for (int i = 0; i < 10; i++)
    all.push_back(i);
  while (1)
  {
    move(all);
    response();
    int done = 1;
    for (int i = 1; i < 10; i++)
      if (where[i] != where[i - 1])
        done = 0;
    if (done)
    {
      cout << "done" << endl;
      return 0;
    }
  }
}