// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int> pq;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    x -= i;
    pq.push(x);
    pq.push(x);
    ans += pq.top() - x;
    pq.pop();
  }
  cout << ans << '\n';
}