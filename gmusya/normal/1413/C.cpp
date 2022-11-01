#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned int uint;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <uint> a(6);
  for (int i = 0; i < 6; i++)
    cin >> a[i];
  uint n;
  cin >> n;
  vector <uint> b(n);
  for (uint i = 0; i < n; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  uint ans = 2e9;
  for (uint i = 0; i < n; i++)
    for (uint j = 0; j < 6; j++) {
      uint x = b[i] - a[j];
      if (b[0] - a[0] < x)
        continue;
      int pos1 = lower_bound(b.begin(), b.end(), x + a[1]) - b.begin() - 1;
      int pos2 = lower_bound(b.begin(), b.end(), x + a[2]) - b.begin() - 1;
      int pos3 = lower_bound(b.begin(), b.end(), x + a[3]) - b.begin() - 1;
      int pos4 = lower_bound(b.begin(), b.end(), x + a[4]) - b.begin() - 1;
      int pos5 = lower_bound(b.begin(), b.end(), x + a[5]) - b.begin() - 1;
      int pos6 = n - 1;
      uint tmpans = 0;
      if (pos1 != -1)
        tmpans = max(b[pos1] - a[0], tmpans);
      if (pos2 != -1)
        tmpans = max(b[pos2] - a[1], tmpans);
      if (pos3 != -1)
        tmpans = max(b[pos3] - a[2], tmpans);
      if (pos4 != -1)
        tmpans = max(b[pos4] - a[3], tmpans);
      if (pos5 != -1)
        tmpans = max(b[pos5] - a[4], tmpans);
      if (pos6 != -1)
        tmpans = max(b[pos6] - a[5], tmpans);
      ans = min(ans, tmpans - x);
    }
  cout << ans;
  return 0;
}