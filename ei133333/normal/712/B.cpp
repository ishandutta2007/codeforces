#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  string S;
  cin >> S;
  if(S.size() & 1) {
    cout << -1 << endl;
  } else {
    int x = 0, y = 0;
    for(char& c : S) {
      if(c == 'L') ++x;
      else if(c == 'R') --x;
      else if(c == 'U') ++y;
      else --y;
    }
    x = abs(x);
    y = abs(y);
    cout << min(x, y) + abs(x - y) / 2 << endl;
  }

}