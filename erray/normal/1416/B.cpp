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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int tar = accumulate(a.begin(), a.end(), 0);
    if (tar % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    tar /= n;

    vector<tuple<int, int, int>> ans;
    auto Add = [&](int i, int j, int x) {
      int add = (i + 1) * x;
      assert(a[i] >= add);
      a[i] -= add;
      a[j] += add;
      ans.emplace_back(i, j, x);
    };

    for (int i = 1; i < n; ++i) {
      int add = (i + 1) - (a[i] % (i + 1));
      if (add == (i + 1)) {
        add = 0;
      }
      Add(0, i, add);
      Add(i, 0, a[i] / (i + 1));
      assert(a[i] == 0);
    }

    for (int i = 1; i < n; ++i) {
      Add(0, i, tar);
    }

    cout << (int) ans.size() << '\n';
    for (auto[i, j, x] : ans) {
      cout << i + 1 << ' ' << j + 1 << ' ' << x << '\n';
    }
  }
}