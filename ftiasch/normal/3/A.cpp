// Codeforces Beta Round #3
// Problem A -- Shortest path of the king
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> creat()
{
  char a, b;
  cin >> a >> b;
  return make_pair(a - 'a', b - '1');
}

pair<int, int> s, t;

int main()
{
  s = creat(), t = creat();
  char sx = s.first < t.first? 'R': 'L',
       sy = s.second < t.second? 'U': 'D';
  int dx = abs(t.first - s.first), dy = abs(t.second - s.second);
  cout << max(dx, dy) << "\n";
  for(int i = 0; i < min(dx, dy); ++ i)
    cout << sx << sy << "\n";
  if(dx > dy)
    for(int i = min(dx, dy); i < dx; ++ i)
      cout << sx << "\n";
  else
    for(int i = min(dx, dy); i < dy; ++ i)
      cout << sy << "\n";    
  return 0;
}