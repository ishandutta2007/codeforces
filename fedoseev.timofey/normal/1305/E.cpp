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

const int N = 5000 * 5000 + 1000;

bool hv[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> ans;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (i <= 2) {
      ans.push_back(i);
    } else { 
      int can = (i - 1) / 2;
      if (can + cnt <= m) {
        ans.push_back(i);
        cnt += can;
      } else {
        int need = m - cnt;
        int sm = ans.back() + ans[(int)ans.size() - 2 * need];
        ans.push_back(sm);
        cnt = m;
      }
    }
    if (cnt == m) break;
  }
  if (cnt != m) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    for (int j = i + 1; j < (int)ans.size(); ++j) {
      hv[ans[i] + ans[j]] = true;
    }
  }
  int uk = ans.back() + 1;
  while ((int)ans.size() < n) {
    while (hv[uk]) ++uk;
    for (int i = 0; i < (int)ans.size(); ++i) {
      hv[ans[i] + uk] = true;
    }
    ans.push_back(uk);
    ++uk;
  }
  for (int x : ans) cout << x << ' ';
}