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
  /*
  evet efendim arkadas sayili parti problemi cozen bir vatandas
  ne zamani
  zaman degil efendim arkadas sayisi, arkadas
  sokarim zamanina 
  */

  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i] >> B[i];
    }


    auto Can = [&](int x) {
      int c = 0;
      for (int i = 0; i < N; ++i) {
        c += (B[i] >= c && A[i] >= x - c - 1);
      }

      return (c >= x);
    };

    int low = 1, high = N;
    while (low < high) {
      int mid = 1 + ((low + high) >> 1);
      if (Can(mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    
    cout << low << '\n';
  }
}