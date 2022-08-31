#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int D;
    cin >> D;
    if(D == 0) {
      cout << "Y 0 0\n";
      continue;
    }
    auto x = (D - sqrt(D - 4) * sqrt(D)) * 0.5;
    auto y = (D + sqrt(D - 4) * sqrt(D)) * 0.5;
    if(x >= 0 && y >= 0) cout << "Y " << fixed << setprecision(15) << x << " " << y << endl;
    else cout << "N\n";
  }
}