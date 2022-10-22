#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  priority_queue<int> rem_a, rem_b;
  priority_queue<int> sel_a, sel_b;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    rem_a.push(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    rem_b.push(x);
  }
  int ans = n;
  long long suma = 0, sumb = 0;
  auto update = [&](long long & sum, priority_queue<int> & pq, priority_queue<int> & added, int sz) {
    sz /= 4;
    while ((int)pq.size() > sz) {
      sum += pq.top();
      added.push(-pq.top());
      pq.pop();
    }
    if (pq.size() > 0 && added.size() > 0) {
      while (pq.top() > -added.top()) {
        int u = pq.top();
        int v = -added.top();
        pq.pop();
        added.pop();
        sum += u - v;
        pq.push(v);
        added.push(-u);
      }
    }
  };
  update(suma, rem_a, sel_a, ans);
  update(sumb, rem_b, sel_b, ans);
  while (suma < sumb) {
    ++ans;
    rem_a.push(100);
    rem_b.push(0);
    update(suma, rem_a, sel_a, ans);
    update(sumb, rem_b, sel_b, ans);
  }
  ans -= n;
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}