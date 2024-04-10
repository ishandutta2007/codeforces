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
    vector<array<int, 2>> bad(M * 2);
    for (int i = 0; i < M; ++i) {
      cin >> bad[i][0] >> bad[i][1];
      bad[M + i] = bad[i];
      swap(bad[i][0], bad[i][1]);
    }
    sort(bad.begin(), bad.end());
    auto Bad = [&](int x, int y) {
      return (x == y) || binary_search(bad.begin(), bad.end(), array{x, y});
    };
    debug(bad);

    map<int, int> freq;
    for (auto e : A) {
      freq[e] += 1;
    }
    map<int, vector<int>> ct;
    for (auto[x, c] : freq) {
      ct[c].push_back(x);
    }
    vector<pair<int, vector<int>>> pairs(ct.begin(), ct.end());
    debug(pairs);
    for(auto&[x, v] : pairs) { 
      reverse(v.begin(), v.end());
    }
    long long ans = 0;
    int size = int(pairs.size());
    for (int i = 0; i < size; ++i) {
      for (int j = i; j < size; ++j) {
        int ci = pairs[i].first;
        int cj = pairs[j].first;
        debug(i, j, ci, cj);
        for (auto x : pairs[i].second) {
          int p = 0;
          while (p < int(pairs[j].second.size()) && Bad(x, pairs[j].second[p])) {
            ++p;
          }
          if (p < int(pairs[j].second.size())) {
            debug(x, p, pairs[j].second[p]);
            ans = max(ans, 1LL * (ci + cj) * (x + pairs[j].second[p]));
          }
          if (p == 0) {
            break;
          }
        }   
      }
    }
    cout << ans << '\n';
  }
}