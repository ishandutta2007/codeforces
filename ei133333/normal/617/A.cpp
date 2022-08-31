#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int X, ret = 0;
  cin >> X;
  while(X - 5 >= 0) X -= 5, ++ret;
  while(X - 4 >= 0) X -= 4, ++ret;
  while(X - 3 >= 0) X -= 3, ++ret;
  while(X - 2 >= 0) X -= 2, ++ret;
  while(X - 1 >= 0) X -= 1, ++ret;
  cout << ret << endl;
}