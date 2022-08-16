#include<bits/stdc++.h>
using namespace std;
int main()
{
  auto is_uruu =[](int y)
  {
    return(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
  };
  
  int Y;
  cin >> Y;
  pair< int, int > p(0, is_uruu(Y)), q = p;
  do {
    (q.first += 365 + is_uruu(Y++)) %= 7;
    q.second = is_uruu(Y);
  } while(p != q);
  
  cout << Y << endl;
}