// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }

    vector<vector<array<int, 2>>> es(N);
    for (int i = 0; i < N; ++i) {
      int L = -1;
      int R = -1;
      {
        int low = 1, high = N;
        while (low < high) {
          int mid = 1 + ((low + high) >> 1);
          if ((i + 1) / mid >= B[i]) {
            low = mid;
          } else {
            high = mid - 1;
          }
        }
        R = low;
      }

      {
        int low = 1, high = N;
        while (low < high) {
          int mid = (low + high) >> 1;
          if ((i + 1) / mid <= B[i]) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        L = low;
      }
      debug(i, L, R);
      es[L - 1].push_back({R, i});
    }
    vector<int> a(N);
    min_pq<array<int, 2>> pq;
    for (int i = 0; i < N; ++i) {
      for (auto e : es[i]) {
        pq.push(e);
      }
      auto[foo, id] = pq.top();
      pq.pop();
      a[id] = i;
    }
    for (int i = 0; i < N; ++i) {
      cout << a[i] + 1 << " \n"[i == N - 1];
    }
  }
}