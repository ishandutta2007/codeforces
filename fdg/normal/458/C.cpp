#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long inf = 1000000007;
vector<int> pr[100005];

priority_queue<int> q;
// multiset<int> f;

long long solve(int mx) {
  // f.clear();
  while (q.size()) q.pop();
  long long ret = 0;
  int have = pr[0].size();
  for (int i = 1; i <= 100000; ++i) {
    int rm = (int) pr[i].size() - mx;
    for (int j = 0; j < pr[i].size(); ++j) {
      if (rm > 0) {
        ret += pr[i][j];
        ++have;
        --rm;
      } else {
        q.push(-pr[i][j]);
      }
    }
  }
  while (have <= mx && q.size()) {
    ret -= q.top(); q.pop();
    ++have;
  }
  return ret;
}

int main() {
  inf *= inf;

  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    pr[a].push_back(b);
  }
  for (int i = 0; i <= 100000; ++i)
    sort(pr[i].begin(), pr[i].end());
  int l = 0, r = 100001;
  while (r - l > 30) {
    int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (solve(m1) > solve(m2)) l = m1;
    else r = m2;
  }
  // for (int i = 0; i <= n; ++i) {
  //   cout << i << "  " << solve(i) << endl;
  // }
  long long ans = solve(100001);
  for (int i = l; i <= r; ++i)
    ans = min(ans, solve(i));
  cout << ans << endl;
  return 0;
}