// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> ga(n);
    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      ga[x - 1].push_back(i);
    }

    vector<vector<int>> gb(n);
    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      gb[x - 1].push_back(i);
    }
    
    vector<int> in(n);
    vector<int> out(n);
    int t = 0;
    function<void(int)> DfsB = [&](int v) {
      in[v] = t++;
      for (auto u : gb[v]) {
        DfsB(u);
      }
      out[v] = t++;
    };
    DfsB(0);
    vector<int> id(2 * n, -1);
    for (int i = 0; i < n; ++i) {
      id[in[i]] = i;
    }

    int ans = 0;
    set<int> act;
    function<void(int)> DfsA = [&](int v) {
      bool added = false;
      int del = -1;
      auto sub = act.lower_bound(in[v]);
      if (sub == act.end() || *sub > out[v]) {
        added = true;
        if (sub != act.begin() && out[id[*(--sub)]] > out[v]) {
          del = id[*sub];
          act.erase(sub);
        }
        act.insert(in[v]);
      }
      ans = max(ans, int(act.size()));
      for (auto u : ga[v]) {
        DfsA(u);
      }
      if (added) {
        act.erase(in[v]);
        if (del != -1) {
          act.insert(in[del]);
        }
      }
    };
    DfsA(0);
    cout << ans << '\n';
  }
}