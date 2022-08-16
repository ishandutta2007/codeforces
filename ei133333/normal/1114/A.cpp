#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int X, Y, Z, A, B, C;
  cin >> X >> Y >> Z;
  cin >> A >> B >> C;

  int get = min(Z, C);
  Z -= get;
  C -= get;

  get = min(Z, B);
  Z -= get;
  B -= get;

  get = min(Z, A);
  Z -= get;
  A -= get;

  get = min(Y, B);
  Y -= get;
  B -= get;

  get = min(Y, A);
  Y -= get;
  A -= get;

  get = min(X, A);
  X -= get;
  A -= get;

  if(X == 0 && Y == 0  && Z == 0) puts("YES");
  else puts("NO");

}