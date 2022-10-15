// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    map<int, int> mp;
    for (auto e : A) {
      mp[e] += 1;
    }

    priority_queue<int> pq;
    int left = K;
    auto Add = [&](int x) {
      left -= x;
      pq.push(x);
      if (left < 0) {
        left += pq.top();
        pq.pop();
      }
    };

    for (auto[x, y] : mp) {
      if (x > N) {
        Add(y);
      }
    }

    int miss = 0;
    int mex = 0;
    for (int i = 0; i <= N; ++i) {
      if (mp.count(i)) {
        if (mex == i) {
          mex += 1;
        }
      } else {
        miss += 1;
      }
    }

    int s = int(mp.size());
    debug(miss, mex);
    int ans = mex;
    for (int i = N; i >= 0; --i) {
      if (mp[i] == 0) {
        miss -= 1;
      } else {
        Add(mp[i]);
      }

      debug(i, miss, pq);
      if (miss <= K) {
        ans = max(ans, i + int(pq.size()) - miss); 
      }
    }
    debug(ans);
    cout << s - ans << '\n';
  }
}