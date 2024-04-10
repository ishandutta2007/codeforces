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
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    long long sum = accumulate(A.begin(), A.end(), 0LL);
    vector<long long> que;
    map<long long, long long> ct;
    auto Add = [&](long long x, long long c) {
      if (!ct.count(x)) {
        que.push_back(x);
      } 
      ct[x] += c;
    };


    map<long long, int> a;
    for (auto e : A) {
      a[e] += 1;
    }
    Add(sum, 1);
    int f = 0;
    for (int i = 0; i < int(que.size()); ++i) {
      long long x = que[i];
      while (a[x] > 0 && ct[x] > 0) {
        --ct[x];
        --a[x];
        f += 1;
      }
      Add((x + 1) / 2, ct[x]);
      Add(x / 2, ct[x]);
    }
    cout << (f == N ? "YES" : "NO") << '\n';
  }
}