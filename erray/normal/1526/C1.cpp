// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  priority_queue<int> pq;
  long long sum = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (a[i] < 0) {
      pq.push(-a[i]);
    }
    while (sum < 0) {
      sum += pq.top();
      pq.pop();
      ++ans;
    }
  }
  cout << n - ans << '\n';
}