#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, ax, ay, bx, by, cx, cy;
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  int kingArea = (bx < ax) * 2 + (by < ay);
  int targetArea = (cx < ax) * 2 + (cy < ay);
  cout << (kingArea == targetArea ? "YES" : "NO") << endl;
}