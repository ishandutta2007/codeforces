#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int Q;
  cin >> Q;

  auto solve2 = [&](int64 N, int64 A, int64 L) {
    return 1LL * N * (A + L) / 2;
  };
  auto solve = [&](int64 V) {
    int64 add = 0LL;
    // 
    {
      int64 last = V % 2 == 1 ? V : V - 1;
      add -= solve2(last / 2+1, 1, last);
    }
    // 
    {
      int64 last = V % 2 == 0 ? V : V - 1;
      add += solve2(last / 2, 2, last);
    }
    return add;
  };
  while(Q--) {
    int L, R;
    cin >> L >> R;
    cout << solve(R) - solve(L - 1) << endl;
  }
}