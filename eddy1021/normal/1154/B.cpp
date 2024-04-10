#include <bits/stdc++.h>
using namespace std;
const int N = 1021;
int n, a[N];
int main() {
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> a[i];
  }
  for (int i=0; i<N; ++i) {
    unordered_map<int, int> cnt;
    for (int j=0; j<n; ++j) {
      for (int d=-1; d<=1; ++d) {
        if (i == 0 and d) {
          continue;
        }
        ++ cnt[a[j] + d * i];
      }
    }
    int mx = 0;
    for (auto j: cnt) mx = max(mx, j.second);
    if (mx == n) {
      cout << i << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}