#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int X;
  cin >> X;
  for(int B = 1; B <= 100000; B++) {
    for(int A = B; A <= 100000; A += B) {
      if(1LL * A * B > X && A < 1LL * X * B) {
        cout << A << " " << B << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}