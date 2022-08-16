#include<bits/stdc++.h>
using namespace std;


int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int x, y, z;
  cin >> x >> y >> z;
  int buff = min(a, x);
  a -= buff;
  x -= buff;
  buff = min(b, y);
  b -= buff;
  y -= buff;
  buff = min(c, z);
  c -= buff;
  z -= buff;
  int surplus = a / 2 + b / 2 + c / 2;
  buff = min(surplus, x);
  x -= buff;
  surplus -= buff;
  buff = min(surplus, y);
  y -= buff;
  surplus -= buff;
  buff = min(surplus, z);
  z -= buff;
  surplus -= buff;

  if(x + y + z == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

}