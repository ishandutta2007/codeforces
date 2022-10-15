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
     {
       auto sa = A;
       sort(sa.begin(), sa.end());
       sa.erase(unique(sa.begin(), sa.end()), sa.end());
       for (auto& e : A) {
         e = int(lower_bound(sa.begin(), sa.end(), e) - sa.begin());
       }
     }

     vector<int> left(N, N);       
     vector<int> right(N, -1);
     for (int i = 0; i < M; ++i) {
       int L, R;
       cin >> L >> R;
       --L, --R;
       left[R] = min(left[R], L);
       right[L] = max(right[L], R);
     }
     for (int i = N - 1; i > 0; --i) {
       left[i - 1] = min(left[i - 1], left[i]);
     }
     for (int i = 0; i < N - 1; ++i) {
       right[i + 1] = max(right[i + 1], right[i]);
     }

     int rr = -1;
     int ll = N - 1;
     vector<vector<int>> pos(N);
     for (int i = 0; i < N; ++i) {
       pos[A[i]].push_back(i);
     }
     for (int i = N - 1; i >= 0; --i) {
       int x = A[i];
       int next = int(lower_bound(pos[x].begin(), pos[x].end(), i) - pos[x].begin()) - 1;
       if (next >= 0) {
         int n = pos[x][next];
         debug(i, n, left[i]);
         if (left[i] <= n) {
           ll = min(ll, i);
           rr = max(rr, n);
         }
       }
     }

     debug(ll, rr);
     int ans = N - 1 - ll + 1;
     for (int i = N - 1; i > rr; --i) {
       int l = left[i];
       int x = A[i];
       int next = int(lower_bound(pos[x].begin(), pos[x].end(), l) - pos[x].begin());
       if (next < int(pos[x].size()) && pos[x][next] < ll) {
         ll = pos[x][next];
       }
       debug(i, ll);
       ans = min(ans, i - ll);
     }
     cout << max(0, ans) << '\n';
  }
}