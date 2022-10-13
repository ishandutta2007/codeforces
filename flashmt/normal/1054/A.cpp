#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int elevatorTime = (abs(z - x) + abs(x - y)) * t2 + t3 * 3;
  if (elevatorTime <= abs(x - y) * t1) cout << "YES";
  else cout << "NO";
}