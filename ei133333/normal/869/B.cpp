#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 A, B;
  cin >> B >> A;

  int64 frac = 1;
  for(int64 i = B + 1; i <= A; i++) {
    (frac *= i) %= 10;
    if(frac == 0) break;
  }

  cout << frac << endl;
}