#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 3e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<ii, int> v[ms];

void solve() {
  int n, k; cin >> n >> k;
  if(k > n) {
    cout << "NO" << endl;
    return;
  }
  priority_queue<int> pq;
  int ans = 0;
  for(int i = 0; i < 30; i++) {
    if(n & (1 << i)) {
      pq.emplace(i);
      ans++;
    }
  }
  if(ans > k) {
    cout << "NO" << endl;
    return;
  }
  while(ans < k) {
    ans++;
    int x = pq.top();
    pq.pop();
    pq.emplace(x-1);
    pq.emplace(x-1);
  }
  cout << "YES" << endl;
  while(!pq.empty()) {
    cout << (1 << pq.top()) << ' ';
    pq.pop();
  }
  cout << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}