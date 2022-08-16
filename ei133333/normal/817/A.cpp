#include<bits/stdc++.h>

using namespace std;


bool check(int X1, int Y1, int X2, int Y2, int X, int Y)
{
  int sa = abs(X1 - X2);
  if(sa % X != 0) {
    return (false);
  }

  int add = 0;
  if(sa % (2 * X) == X) add += Y;

  if((Y1 + add - Y2) % (2 * Y) == 0) {
    return(true);
  } else {
    return(false);
  }
}

int main()
{
  int X1, Y1, X2, Y2, X, Y;

  cin >> X1 >> Y1 >> X2 >> Y2;
  cin >> X >> Y;
  if(check(X1, Y1, X2, Y2, X, Y) || check(Y1, X1, Y2, X2, Y, X)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}