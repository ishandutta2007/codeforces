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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    int K;
    cin >> K;
    vector<int> B(K);
    for (int i = 0; i < K; ++i) {
      cin >> B[i];
    }
    auto Convert = [&](vector<int> a) {
      vector<pair<int, long long>> res;
      for (auto e : a) {
        int c = 1;
        while (e % M == 0) {
          e /= M;
          c *= M;
        }
        if (!res.empty() && res.back().first == e) {
          res.back().second += c;
        } else {
          res.emplace_back(e, c);
        }
      }
      return res;
    };
    cout << (Convert(A) == Convert(B) ? "Yes" : "No") << '\n';
  }
}