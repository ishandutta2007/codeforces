#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> p(n);
  vector<bool> have(n);
  for (int& x : p) {
    cin >> x;
    --x;
    if (x >= 0) {
      have[x] = true;
    }
  }
  vector<int> put;
  for (int i = 0; i < n; ++i) {
    if (!have[i]) {
      put.push_back(i);
    }
  }
  mt19937 rng(566);
  while (true) {
    vector<int> ans(n);
    shuffle(put.begin(), put.end(), rng);
    int j = 0;
    bool fail = false;
    for (int i = 0; i < n; ++i) {
      if (p[i] >= 0) {
        ans[i] = p[i];
      } else {
        ans[i] = put[j++];
        if (ans[i] == i) {
          fail = true;
        }
      }
    }
    if (!fail) {
      for (int x : ans) {
        cout << x + 1 << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
  return 0;
}