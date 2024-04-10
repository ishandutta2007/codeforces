// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
      cin >> w[i];
    }
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      ++deg[x];
      ++deg[y];
    }
    long long ans = accumulate(w.begin(), w.end(), 0LL);
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return w[x] > w[y];
    });

    cout << ans << ' ';
    int p = 0;
    for (int i = 0; i < n - 2; ++i) {
      while (p < n && deg[ord[p]] == 1) {
        ++p;
      }

      if (p != n) {
        ans += w[ord[p]];
        --deg[ord[p]];
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
}