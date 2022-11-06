
  #include <bit>
  #include <bits/stdc++.h>
  using namespace std;

  #define int long long

  const int inf = 1e18;
  const int ms = 2e6+5;
  const int mod = 1e9+7;
  using ii = pair<int, int>;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  int n, m;
  pair<ii, int> a[ms];
  int ans[ms];

  void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> a[i].first.first;
      a[i].second = i;
    }
    for(int i = 0; i < n; i++) {
      cin >> a[i].first.second;
    }
    sort(a, a+n);
    int cur = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        pq.emplace(a[i].first.second);
        cur += a[i].first.second;
      ans[a[i].second] = cur;
        // cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
      if(i >= k ) {
        // cout << pq.top() << endl;
        cur -= pq.top();
        pq.pop();
      }
    }
    for(int i = 0; i < n; i++) {
      cout << ans[i] << " "; 
    }
    cout << endl;
  }

  int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // t = inf;
    // cin >> t;
    // cout << fixed << setprecision(9);
    while (t--) {
        solve();
    }
    return 0;
  }