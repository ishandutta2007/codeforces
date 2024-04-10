#include<bits/stdc++.h>
using namespace std;

int N;
string S;
int X, Y;

int main() {
  cin >> N >> S >> X >> Y;
  if (abs(X) + abs(Y) > N || abs(X+Y)%2 != N%2) {
    cout << -1 << '\n';
    return 0;
  }
  for (char c : S) {
    if (c == 'L') X++;
    else if (c == 'R') X--;
    else if (c == 'U') Y--;
    else if (c == 'D') Y++;
    else assert(false);
  }
  if (abs(X) + abs(Y) == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int res = N+1;
  for (int l = 0, r = 0; true; ) {
    if (abs(X) + abs(Y) <= (r-l)) {
      res = min(res, r-l);
      assert(l < r);
      char c = S[l++];
      if (c == 'L') X++;
      else if (c == 'R') X--;
      else if (c == 'U') Y--;
      else if (c == 'D') Y++;
      else assert(false);
    } else {
      if (r == N) break;
      char c = S[r++];
      if (c == 'L') X--;
      else if (c == 'R') X++;
      else if (c == 'U') Y++;
      else if (c == 'D') Y--;
      else assert(false);
    }
  }
  cout << res << '\n';
  return 0;
}