#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
int n, total, f[N], ret[N], lim;
vector<int> single;
vector<int> a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> total >> n;
    lim = (n + 1) / 2;
    for (int i = 1; i <= total; i++) {
      f[i] = 0;
    }
    single.clear();
    for (int i = 1; i <= n; i++) {
      ret[i] = -1;
      int k;
      cin >> k;
      a[i].clear();
      a[i].resize(k);
      for (auto &x : a[i]) {
        cin >> x;
      }
      if (k == 1) single.push_back(i);
    }
    for (auto &i : single) {
      ret[i] = a[i][0];
      f[ret[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (ret[i] == -1) {
        int fmin = (int) 1e9;
        for (auto &x : a[i]) fmin = min(fmin, f[x]);
        for (auto &x : a[i]) {
          if (fmin == f[x]) {
            ret[i] = x;
            f[x]++;
            break;
          }
        }
      }
    }
    bool good = 1;
    for (int i = 1; i <= total; i++) {
      if (f[i] > lim) good = 0;
    }
    if (!good) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int j = 1; j <= n; j++) cout << ret[j] << " ";
      cout << "\n";
    }
  }
}