// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> A(Q), B(Q);
  set<array<int, 2>> st;
  for (int i = 0; i < Q; ++i) {
    cin >> A[i] >> B[i];
    st.insert({A[i], B[i]});
  }

  vector<pair<int, int>> que;
  que.emplace_back(1, 1);
  int ans = int(1e6);
  for (int p = 0; p <= ans; ++p) {
    sort(que.rbegin(), que.rend());
    vector<pair<int, int>> new_que;
    int mx = -1;
    for (auto[x, y] : que) {
      if (mx < y) {
        mx = y;
        int nw = x + y + st.count({x, y});
        new_que.emplace_back(min(N, nw), y);
        new_que.emplace_back(x, min(M, nw));
        if ((x == N && nw >= M) || (y == M && nw >= N)) {
          ans = min(ans, p + 1); 
        } else if ((nw >= N && N + y >= M) || (nw >= M && M + x >= N)) {
          ans = min(ans, p + 2);
        }
      }  
    }
    swap(que, new_que);
  }

  cout << ans << '\n';
}