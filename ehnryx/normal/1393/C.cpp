//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n+1);
    for(int i=0; i<n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    function<bool(int)> valid = [&](int m) {
      priority_queue<int> todo;
      for(int v : a) {
        todo.push(cnt[v]);
      }
      vector<vector<int>> add(n);
      for(int i=0; i<n; i++) {
        if(todo.empty()) return false;
        int c = todo.top();
        todo.pop();
        if(c > 1 && i+m+1 < n) {
          add[i+m].push_back(c-1);
        }
        for(int v : add[i]) {
          todo.push(v);
        }
      }
      return true;
    };

    int l = 0;
    int r = n-2;
    while(l < r) {
      int m = (l+r+1) / 2;
      if(valid(m)) {
        l = m;
      } else {
        r = m-1;
      }
    }
    cout << r << nl;
  }

  return 0;
}