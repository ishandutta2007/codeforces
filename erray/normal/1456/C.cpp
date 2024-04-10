// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  priority_queue<long long> pq;
  for (int i = 0; i < k + 1; ++i) {
    pq.push(0);
  }

  long long ans = 0;
  for (auto el : a) {
    long long w = pq.top();
    pq.pop();
    ans += w;
    pq.push(w + el);
  }
  cout << ans << '\n';
}