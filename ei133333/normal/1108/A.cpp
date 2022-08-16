#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int Q;
  cin >> Q;
  while(Q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = a; i <= b; i++) {
      for(int j = c; j <= d; j++) {
        if(i != j) {
          cout << i << " " << j << endl;
          goto foo;
        }
      }
    }
    foo:;
  }
}