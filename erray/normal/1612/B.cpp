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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, A, B;
    cin >> N >> A >> B;
    --A, --B;
    vector<int> res(N);
    iota(res.rbegin(), res.rend(), 0);
    res.erase(find(res.begin(), res.end(), A));
    res.erase(find(res.begin(), res.end(), B));
    res.insert(res.begin(), A);
    res.insert(res.end(), B);
    if (*min_element(res.begin(), res.begin() + N / 2) == A && *max_element(res.rbegin(), res.rbegin() + N / 2) == B) {
      for (auto e : res) {
         cout << e + 1 << ' ';
      }
    } else {
      cout << -1;
    }
    cout << '\n';
  }
}