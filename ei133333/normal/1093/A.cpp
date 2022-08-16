#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int T;
  cin >> T;
  while(T--) {
    int X;
    cin >> X;
    int ret = 0;
    while(X > 3) {
      X -= 2;
      ++ret;
    }
    cout << ret + 1 << endl;
  }
}