#include<bits/stdc++.h>

using namespace std;

int main()
{
  int X;
  cin >> X;

  if(X == 3) {
    cout << 5 << endl;
    return (0);
  }

  for(int i = 1; ; i += 2) {
    if(X <= (i * i + 1) / 2) {
      cout << i << endl;
      return (0);
    }
  }
}