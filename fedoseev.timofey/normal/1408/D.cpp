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
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> c[i] >> d[i];
  }
  vector <pair <int, int>> go;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int f = max(0, c[j] - a[i] + 1);
      int s = max(0, d[j] - b[i] + 1);
      go.push_back({f, s});
    }
  }
  sort(go.rbegin(), go.rend());
  int mx = -1;
  vector <pair <int, int>> nw;
  for (auto p : go) {
    if (p.second > mx) {
      nw.push_back(p);
      mx = p.second;
    }
  }   
  /*for (auto p : nw) {
    cout << p.first << ' ' << p.second << endl;
  }*/
  int ans = 2e9;
  for (int i = 0; i <= (int)nw.size(); ++i) {
    int needf = (i == 0 ? 0 : nw[i - 1].second);
    int needs = (i == (int)nw.size() ? 0 : nw[i].first);
    ans = min(ans, needf + needs);
  }
  cout << ans << '\n';
}