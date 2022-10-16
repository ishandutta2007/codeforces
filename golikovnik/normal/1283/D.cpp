#include <bits/stdc++.h>

using namespace std;

//cpp17

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<int, int> d;
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    q.push(x);
    d[x] = 0;
  }
  vector<int> ans;
  ans.reserve(m);
  i64 ans_v = 0;
  while (true) {
    auto x = q.front();
    q.pop();
    for (auto dx : {-1, 1}) {
      auto nx = x + dx;
      if (d.count(nx)) {
        continue;
      }
      ans_v += (d[nx] = d[x] + 1);
      ans.push_back(nx);
      q.push(nx);
      if (!--m) {
        cout << ans_v << '\n';
        for (auto x : ans) {
          cout << x << ' ';
        }
        cout << '\n';
        return 0;
      }
    }
  }
}