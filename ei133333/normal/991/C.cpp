#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int64 N;
  cin >> N;

  int64 high = N, low = 0;

  auto check = [&](int64 k) {

    int64 v = N;

    int64 get = 0;
    while(v > 0) {
      int64 add = min(k, v);
      get += add;
      v -= add;
      add = v / 10;
      v -= add;
    }
    return 2 * get >= N;
  };

  while(high - low > 1) {
    int64 mid = (high + low) / 2;
    if(check(mid)) high = mid;
    else low = mid;
  }

  cout << high << endl;

}