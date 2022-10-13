#include <bits/stdc++.h>
using namespace std;

int main()
{
  int y, b, r;
  cin >> y >> b >> r;
  cout << min({y, b - 1, r - 2}) * 3 + 3 << endl;
}