#include <bits/stdc++.h>
using namespace std;
int which[7] = {0, 1, 2, 0, 2, 1, 0};
int a[3], per[3] = {3, 2, 2};
int main() {
  for (int i=0; i<3; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i=0; i<7; ++i) {
    int b[3];
    for (int j=0; j<3; ++j) {
      b[j] = a[j];
    }
    int tans = 0;
    for (int j=0; j<7; ++j) {
      -- b[which[(i + j) % 7]];
      ++ tans;
      if (b[which[(i + j) % 7]] < 0) {
        break;
      }
      int mst = 2e9;
      for (int k=0; k<3; ++k) {
        mst = min(mst, b[k] / per[k]);
      }
      ans = max(ans, tans + mst * 7);
    }
  }
  cout << ans << endl;
}