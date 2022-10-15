// author: erray
#include<bits/stdc++.h>
 
using namespace std;

#define int long long
 
int32_t main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long w;
    cin >> n >> w;
    vector<int> a(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]].push_back(i + 1);
    }
    long long bot = (w + 1) / 2;
    sort(a.begin(), a.end());
    vector<int> now;
    for (int i = 0; i < n && a[i] <= w; ++i) {
      now.push_back(a[i]);
    }
    vector<int> ans;
    reverse(now.begin(), now.end());
    long long sum = 0;
    int cur = 0;
    while (sum < bot && cur < (int) now.size()) {
      sum += now[cur];
      ans.push_back(now[cur]);
      ++cur;
    }
    if (sum < bot) {
      cout << -1 << '\n';
      continue;
    }
    cout << (int) ans.size() << '\n';
    for (auto el : ans) {
      cout << pos[el].back() << ' ';
      pos[el].pop_back();
    }
    cout << '\n';
  }
}