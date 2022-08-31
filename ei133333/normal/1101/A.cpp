#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int Q;
  cin >> Q;
  while(Q--) {
    int64 L, R, D;
    cin >> L >> R >> D;
    if(L <= D && D <= R) {
      int64 T = (R + D) / D * D;
      cout << T << endl;
    } else {
      cout << D << endl;
    }
  }
}