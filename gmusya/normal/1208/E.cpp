#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vvi arr(n);
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    arr[i].resize(sz);
    for (int j = 0; j < sz; j++)
      cin >> arr[i][j];
  }
  ll ans = 0;
  vector <vector <pii>> arrbirth(w + 5), arrdeath(w + 5);
  for (int i = 0; i < n; i++) {
    int sz = (int)arr[i].size();
    for (int j = 0; j < sz; j++) {
      int birth = j + 1;
      int death = w + 2 - (sz - j);
      death = min(death, w + 1);
      if (birth < death) {
        arrbirth[birth].push_back({i, arr[i][j]});
        arrdeath[death].push_back({i, arr[i][j]});
      }
    }
    {
      int birth = 1;
      int death = w + 1 - sz;
      death = min(death, w + 1);
      if (birth < death) {
        arrbirth[birth].push_back({i, 0});
        arrdeath[death].push_back({i, 0});
      }
    }
    {
      int birth = sz + 1;
      int death = w + 1;
      death = min(death, w + 1);
      if (birth < death) {
        arrbirth[birth].push_back({i, 0});
        arrdeath[death].push_back({i, 0});
      }
    }
  }
  ll sum = 0;
  vector <multiset <int>> vs(n);
  for (int curw = 1; curw <= w; curw++) {
    for (auto &now : arrbirth[curw]) {
      int id = now.fi, val = now.se;
      if (!vs[id].empty())
        sum -= *vs[id].rbegin();
      vs[id].insert(val);
      sum += *vs[id].rbegin();
    }
    for (auto &now : arrdeath[curw]) {
      int id = now.fi, val = now.se;
      sum -= *vs[id].rbegin();
      vs[id].erase(vs[id].find(val));
      if (!vs[id].empty())
        sum += *vs[id].rbegin();
    }
    cout << sum << ' ';
  }
  return 0;
}