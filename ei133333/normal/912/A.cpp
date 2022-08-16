#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 A, B, X, Y, Z;
  cin >> A >> B;
  cin >> X >> Y >> Z;

  A -= 2 * X;
  B -= 3 * Z;
  A -= Y;
  B -= Y;

  cout << max(0LL, -A) + max(0LL, -B) << endl;
}