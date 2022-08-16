#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int64 N, X, Y, D;
    cin >> N >> X >> Y >> D;
    --X, --Y;

    int64 ret = INF;
    if(abs(Y - X) % D == 0) {
      ret = min(ret, abs(Y - X) / D);
    }
    if(Y % D == 0) {
      ret = min(ret, (X + D - 1) / D + Y / D);
    }
    X = N - X - 1;
    Y = N - Y - 1;
    if(Y % D == 0) {
      ret = min(ret, (X + D - 1) / D + Y / D);
    }
    if(ret == INF) cout << -1 << endl;
    else cout << ret << endl;
  }
}