#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  priority_queue<long long> pq;
  multiset<long long> a;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    a.insert(x);
    sum += x;
  }
  pq.push(sum);
  while (!a.empty() && !pq.empty()) {
    long long x = pq.top();
    pq.pop();
    auto it = --a.end();
    if (x < *it) {
      cout << "NO\n";
      return;
    } else if (x == *it) {
      a.erase(it);
    } else {
      pq.push(x / 2);
      pq.push((x + 1) / 2);
    }
  }
  if (!a.empty() || !pq.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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