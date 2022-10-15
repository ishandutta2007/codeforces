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
  int N;
  cin >> N;
  vector<int> M(N), K(N);
  for (int i = 0; i < N; ++i) {
    cin >> M[i] >> K[i];
    --M[i];
  }

  const int MAX = *max_element(M.begin(), M.end());
  pair<int, int> mx = {0, 1};
  vector<int> ans;
  for (int j = 20; j > 0; --j) {
    debug(j);
    vector<int> ct(MAX + 1);
    for (int i = 0; i < N; ++i) {
      ct[M[i]] += min(j, K[i]);
    }

    vector<int> ord(MAX + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return ct[x] > ct[y];
    });
    debug(ct);
    debug(ord);

    vector<int> res;
    int c = 0;
    for (int k = 0; k < min(j, MAX + 1); ++k) {
      res.push_back(ord[k]);
      c += ct[ord[k]];
    } 

    debug(c);
    
    
    if (1LL * mx.second * c >= 1LL * mx.first * j) {
      ans = res;
      mx = {c, j};
    }
  }
  
  debug(mx);
  cout << int(ans.size()) << '\n';
  for (auto e : ans) {
    cout << e + 1 << ' ';
  }
}