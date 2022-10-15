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
    vector<int> P(N - 1);
    vector<int> deg(N);
    for (int i = 0; i < N - 1; ++i) {
      cin >> P[i];
      --P[i];
      deg[P[i]] += 1;
    }

    deg.push_back(1);
    sort(deg.begin(), deg.end());
    deg.erase(deg.begin(), lower_bound(deg.begin(), deg.end(), 1));
    int s = int(deg.size());
    int low = s, high = N;
    while (low < high) {
      int mid = (low + high) >> 1;
      int extra = 0;
      int l = mid - s; 
      for (int i = 0; i < s; ++i) {
        extra += max(0, deg[s - i - 1] - (mid - i));
      }

      if (extra <= l) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << low << '\n';
  }
}