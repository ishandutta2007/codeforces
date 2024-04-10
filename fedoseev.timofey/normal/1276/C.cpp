#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  map <int, int> cnt;
  for (int x : a) ++cnt[x];
  vector <int> cnt_size(n + 1);
  for (auto p : cnt) ++cnt_size[p.second];
  int p = 0, q = 0;
  int sum = 0;
  int alive = cnt.size();
  for (int mn = 1; mn <= n; ++mn) {
    sum += mn * cnt_size[mn];
    alive -= cnt_size[mn];
    int have = sum + alive * mn;
    int mx = have / mn;
    if (mx >= mn) {
      if (mn * mx > p * q) {
        p = mn;
        q = mx;
      }
    }
  }
  cout << p * q << '\n';
  cout << p << ' ' << q << endl;
  for (auto &pr : cnt) {
    pr.second = min(pr.second, p);
  }
  vector <pair <int, int>> ord;
  for (int j = 0; j < q; ++j) {
    for (int i = 0; i < p; ++i) {
      ord.push_back({i, (j + i) % q});
    }
  }
  vector <vector <int>> ans(p, vector <int> (q));
  int uk = 0;
  for (auto pr : cnt) {
    if (pr.second != p) continue;
    for (int i = 0; i < pr.second; ++i) {
      if (uk < ord.size()) {
        ans[ord[uk].first][ord[uk].second] = pr.first;
        ++uk;
      }
    }
  }
  for (auto pr : cnt) {
    if (pr.second == p) continue;
    for (int i = 0; i < pr.second; ++i) {
      if (uk < ord.size()) {
        ans[ord[uk].first][ord[uk].second] = pr.first;
        ++uk;
      }
    }
  }
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < q; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}