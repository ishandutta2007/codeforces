#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  deque <int> e[2];
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'D') e[0].push_back(i);
    else e[1].push_back(i);

  int last = n;
  while (!e[0].empty() && !e[1].empty()) 
  {
    int x = e[0].front();
    e[0].pop_front();
    int y = e[1].front();
    e[1].pop_front();
    if (x < y) e[0].push_back(last++);
    else e[1].push_back(last++);
  }

  cout << (e[0].empty() ? 'R' : 'D') << endl;
}