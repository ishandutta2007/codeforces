#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 beet(int64 a, int64 b, int64 c)
{
  if(a > b) swap(a, b);
  if(a < 0) {
    b += (-a + (c - 1)) / c * c;
    a += (-a + (c - 1)) / c * c;
  }
  return (b / c - a / c);
}

int main()
{
  int a, b, x_1, y_1, x_2, y_2;
  cin >> a >> b >> x_1 >> y_1 >> x_2 >> y_2;
  auto p = beet(x_1 + y_1, x_2 + y_2, 2 * a);
  auto q = beet(x_1 - y_1, x_2 - y_2, 2 * b);
  cout << max(p, q) << endl;
}