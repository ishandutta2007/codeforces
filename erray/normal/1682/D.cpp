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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int odd = count(S.begin(), S.end(), '1');
    if (odd % 2 == 1 || odd == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      a[i] = S[i] - '0';
    }

    vector<array<int, 2>> ans;
    auto Add = [&](int x, int y) {
      ans.push_back({x, y});
      a[x] ^= 1;
      a[y] ^= 1;
    };
    
    vector<bool> act(N, true);
    for (int it = 0; it < 2; ++it) {
      for (int i = 0; i < N; ++i) {
        int n = (i + 1) % N;
        if (act[i] && act[n] && a[i] == 1 && a[n] == 0) {
          Add(i, n);
          act[i] = false; 
        }
      }
    }
                   
    int p = 0;
    while (p < N && !act[p]) {
      ++p;
    }
    for (int i = p + 1; i < N; ++i) {
      if (act[i]) {
        Add(p, i);
      }
    }
    assert(accumulate(a.begin(), a.end(), 0) == 0);
    for (auto[v, u] : ans) {
      cout << v + 1 << ' ' << u + 1 << '\n'; 
    }
  }
}