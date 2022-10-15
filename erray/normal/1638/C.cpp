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

    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
      int mx = A[i];
      while (!pq.empty() && pq.top() > A[i]) {
        int m = pq.top();
        pq.pop();
        mx = max(mx, m);
      }
      pq.push(mx);
    }
    cout << int(pq.size()) << '\n';
  }
}