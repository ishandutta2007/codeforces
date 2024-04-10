#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int ask(vector<int> a)
{
  cout << "? " << size(a);
  for (int x : a)
    cout << ' ' << x;
  cout << endl;
  cout.flush();
  string resp;
  cin >> resp;
  return resp == "YES";
}

void answer(int x)
{
  cout << "! " << x << endl;
  cout.flush();
  string resp;
  cin >> resp;
  if (resp == ":)")
    exit(0);
}

vector<int> merge(vector<int> a, vector<int> b)
{
  auto res = a;
  for (int x : b)
    res.push_back(x);
  return res;
}

void solve(vector<int> a)
{
  int n = size(a);
  if (n <= 2)
  {
    for (int x : a)
      answer(x);
    assert(0);
  }

  if (n == 3)
  {
    for (int _ : {0, 1})
      if (ask({a[0]}))
      {
        answer(a[0]);
        if (ask({a[1]})) answer(a[1]);
        else answer(a[2]);
      }

    answer(a[1]);
    answer(a[2]);
    assert(0);
  }

  vector<vector<int>> groups(4);
  for (int i = 0, cur = 0; i < 4; i++)
  {
    int curSz = n / 4 + (i < n % 4);
    while (curSz--)
      groups[i].push_back(a[cur++]);
  }

  int x = ask(merge(groups[0], groups[1]));
  int y = ask(merge(groups[0], groups[2]));
  int bad = x * 2 + y;

  vector<int> newA;
  for (int i = 0; i < 4; i++)
    if (i != bad)
      for (int x : groups[i])
        newA.push_back(x);

  solve(newA);
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  iota(begin(a), end(a), 1);
  solve(a);
}