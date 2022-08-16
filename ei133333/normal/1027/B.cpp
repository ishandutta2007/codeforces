#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, Q;
  cin >> N >> Q;
  int64 row = (N * N + 1) / 2;

  while(Q--) {
    int64 X, Y;
    cin >> Y >> X;
    --X, --Y;
    if((X + Y) & 1) {
      cout << row + (N * Y) / 2 + X / 2 + 1 << endl;
    } else {
      cout << (N * Y + 1) / 2 + X / 2 + 1 << endl;
    }
  }
}