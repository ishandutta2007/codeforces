// author: erray
#undef LOCAL
#undef DEBUG 
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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> ar;
    #ifdef LOCAL
      int K;
      cin >> K;
      ar.resize(K);
      for (int i = 0; i < K; ++i) {
        cin >> ar[i];
        --ar[i];
      }
      sort(ar.begin(), ar.end());
    #endif
    debug(ar);
    auto Ask = [&](int a, int b, int c) {
      assert(a >= 0 && a < N);
      assert(b >= 0 && b < N);
      assert(c >= 0 && c < N);
      #ifdef LOCAL
        int R = 0;
        for (auto e : {a, b, c}) {
          R += binary_search(ar.begin(), ar.end(), e);
        }
        debug(a, b, c, R);
        return (R < 2);
      #else 
        cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
        int R;
        cin >> R;
        return R;
      #endif
    };

    vector<int> t(N / 3);
    for (int i = 0; i * 3 < N; ++i) {
      t[i] = Ask(i * 3, i * 3 + 1, i * 3 + 2);
    }
    debug(t);

    int p = 0;
    while (t[p] == t[p + 1]) {
      ++p;
    }

    vector<int> imp(N, -1);
    array<int, 2> use = {-1, -1};
    array<int, 3> res;
    for (int i = 0; i < 3; ++i) {
      res[i] = Ask(p * 3, p * 3 + 1, (p + 1) * 3 + i);
    }
    debug(res);

    if (count(res.begin(), res.end(), t[p]) == 3) {
      debug("here");
      use[t[p]] = p * 3;
      imp[p * 3] = t[p];
      int next = -1;
      if (Ask(p * 3, (p + 1) * 3, (p + 1) * 3 + 1) == t[p + 1]) {
        next = (p + 1) * 3;
      } else {
        next = (p + 1) * 3 + 2;
      }
      use[t[p + 1]] = next;
      imp[next] = t[p + 1];
    } else {
      int p2 = 0;
      while (res[p2] == t[p]) {
        ++p2;
      }
      p2 += (p + 1) * 3;
      use[t[p + 1]] = p2;
      imp[p2] = t[p + 1];
      int next = -1;
      if (Ask(p2, p * 3, p * 3 + 2) == t[p]) {
        next = p * 3;
      } else {
        next = p * 3 + 1;
      }
      use[t[p]] = next;
      imp[next] = t[p];
    }
    debug(use);
    debug(imp);

    for (int i = p * 3; i < (p + 2) * 3; ++i) {
      if (imp[i] == -1) {
        imp[i] = Ask(use[0], use[1], i);
      }
    }

    debug(imp);

    for (int i = 0; i * 3 < N; ++i) {
      if (i == p || i == p + 1) {
        continue;
      }
      if (Ask(use[t[i] ^ 1], i * 3, i * 3 + 1) == t[i]) {
        imp[i * 3] = imp[i * 3 + 1] = t[i];
        imp[i * 3 + 2] = Ask(use[0], use[1], i * 3 + 2); 
      } else {
        imp[i * 3 + 2] = t[i];
        bool same = Ask(use[0], use[1], i * 3) == t[i];
        if (same) {
          imp[i * 3] = t[i];
          imp[i * 3 + 1] = t[i] ^ 1;
        } else {
          imp[i * 3] = t[i] ^ 1;
          imp[i * 3 + 1] = t[i]; 
        }
      }
    }
  
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
      if (imp[i] == 0) {
        ans.push_back(i);
      }
    }

    debug(ans);
    assert(int(ans.size()) > N / 3 && int(ans.size()) < N / 3 * 2);
    #ifdef LOCAL 
      assert(ar == ans);
      cerr << "SUCC" << endl;
    #else 
      cout << "! " << int(ans.size()) << ' ';
      for (auto e : ans) {
        cout << e + 1 << ' ';
      }               
      cout << endl;
    #endif
  }
}