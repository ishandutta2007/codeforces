#include <bits/stdc++.h>

using namespace std;

int f(int x) {
  int ans = 0;
  while (x > 0) {
    ++ans;
    x /= 10;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  priority_queue<int> a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push(x);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b.push(x);
  }
  int ans = 0;
  while (!a.empty()) {
    if (a.top() == b.top()) {
      a.pop();
      b.pop();
    } else if (a.top() > b.top()) {
      int x = f(a.top());
      a.pop();
      ++ans;
      a.push(x);
    } else {
      int x = f(b.top());
      b.pop();
      ++ans;
      b.push(x);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}