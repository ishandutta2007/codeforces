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

using namespace std;

typedef long long ll;

const int Inf = 1e9;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  cin >> n >> m >> q;
  vector <pair <int, int>> gs;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    gs.push_back({x, y});
  }
  int l = -1, r = q;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    vector <pair <int, int>> have;
    for (int i = 0; i <= mid; ++i) {
      if (gs[i].first % 2 == 0) have.push_back({gs[i].first, gs[i].second});
    } 
    sort(have.begin(), have.end());
    vector <int> pref_min((int)have.size() + 1, Inf);
    for (int i = 0; i < (int)have.size(); ++i) {
      pref_min[i + 1] = min(pref_min[i], have[i].second);
    }
    bool bad = false;
    for (int i = 0; i <= mid; ++i) {
      if (gs[i].first % 2 == 1) {
        int cnt = upper_bound(have.begin(), have.end(), make_pair(gs[i].first, Inf)) - have.begin();
        if (pref_min[cnt] < gs[i].second) {
          bad = true;
          break;
        }
      }
    }
    if (bad) {
      r = mid;
    } else {
      l = mid;
    }
  }
  for (int i = 0; i < r; ++i) cout << "YES\n";
  for (int i = 0; i < q - r; ++i) cout << "NO\n";
}