#include <bits/stdc++.h>
using namespace std;
const int oo = int(1e9);

int n, m, numStair, numElevator, v, stairs[100100], elevators[100100];

int dist(int from, int to, int mid)
{
  return abs(from - mid) + abs(to - mid);
}

int calc(int y1, int y2, int num, int pos[]) 
{
  if (!num)
    return oo;
  int res = oo;
  int ry1 = upper_bound(pos, pos + num, y1) - pos;
  if (ry1)
    res = min(res, dist(y1, y2, pos[ry1 - 1]));
  if (ry1 < num)
    res = min(res, dist(y1, y2, pos[ry1]));
  int ry2 = upper_bound(pos, pos + num, y2) - pos;
  if (ry2)
    res = min(res, dist(y1, y2, pos[ry2 - 1]));
  if (ry2 < num)
    res = min(res, dist(y1, y2, pos[ry2]));
  return res;
}

int main()
{
  int q, x1, x2, y1, y2;
  ios::sync_with_stdio(0);
  cin >> n >> m >> numStair >> numElevator >> v;
  for (int i = 0; i < numStair; i++)
    cin >> stairs[i];
  for (int i = 0; i < numElevator; i++)
    cin >> elevators[i];
  cin >> q;
  while (q--)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) 
    {
      cout << abs(y1 - y2) << '\n';
    }
    else 
    {
      if (y1 > y2)
        swap(y1, y2);
      int timeStair = calc(y1, y2, numStair, stairs) + abs(x1 - x2); 
      int timeElevator = calc(y1, y2, numElevator, elevators) + (abs(x1 - x2) + v - 1) / v;
      cout << min(timeStair, timeElevator) << '\n';
    }
  }
}