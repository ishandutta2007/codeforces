#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

void solve_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> remap;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    remap[a[i]];
  }

  int remap_id = 0;
  for (auto& it : remap) {
    it.second = remap_id++;
  }

  vector<int> left(n, -1), right(n);
  vector<vector<int>> index(n);
  for (int i = 0; i < n; i++) {
    a[i] = remap[a[i]];
    if(left[a[i]] == -1) {
      left[a[i]] = i;
    }
    right[a[i]] = i;
    index[a[i]].push_back(i);
  }

  int ans = 0;
  for (int l = 0, r = 0; l < remap_id; ) {
    int cur = index[l].size();
    while (r + 1 < remap_id && right[r] < left[r + 1]) {
      r++;
      cur += index[r].size();
    }
    // query left
    if (l > 0) {
      auto it = lower_bound(index[l-1].begin(), index[l-1].end(), left[l]);
      cur += it - index[l-1].begin();
    }
    // query right
    if (r + 1 < remap_id) {
      auto it = upper_bound(index[r+1].begin(), index[r+1].end(), right[r]);
      cur += index[r+1].end() - it;
    }
    ans = max(ans, cur);

    if (r > 0) {
      for (int j = 0; j < index[r].size(); j++) {
        int i = index[r][j];
        auto it = lower_bound(index[r-1].begin(), index[r-1].end(), i);
        cur = it - index[r-1].begin() + (int)index[r].size() - j;
        ans = max(ans, cur);
      }
    }

    l = r + 1;
    r = l;
  }

  cout << n - ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve_case();
  }

  return 0;
}