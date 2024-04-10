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
  auto F = [&](int x) {
    return 1LL * x * (x - 1) / 2;
  };

  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    map<pair<int, int>, long long> M;
    auto Ask = [&](int l, int r) {
      assert(l >= 1 && r <= N);
      if (M.count({l, r})) {
        return M[{l, r}];
      }
      cout << "? " << l << ' ' << r << endl;
      long long res;
      cin >> res;
      M[{l, r}] = res;
      return res;
    };

    int pos;
    {
      int low = 1, high = N - 2;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (Ask(1, mid) == 0) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      pos = low;
    }

    int diff = Ask(pos - 1, N) - Ask(pos, N);
    long long left = Ask(1, N) - F(diff + 1);
    int size = 0;
    {
      int low = 2, high = N;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (F(mid) >= left) {
          high = mid;  
        } else {
          low = mid + 1;
        }
      }
      size = low;  
    }

    cout << "! " << pos - 1 << ' ' << pos + diff << ' ' << pos + diff + size - 1 << endl;
  }
}