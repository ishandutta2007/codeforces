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

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

void solve(int m, const vector<tuple<int,int,int>>& v, vector<int>& ans, bool refl, bool refr) {
  int n = size(v);
  vector<pair<int,int>> left;
  map<int,int> right;
  for(int i=0; i<n; i++) {
    auto [x, d, j] = v[i];
    if(d) {
      if(!refl) left.emplace_back(x, j);
      if(refr) right[2*m-x] = j;
    } else {
      if(!refr) right[x] = j;
      if(refl) left.emplace_back(-x, j);
    }
  }
  sort(begin(left), end(left), greater<>());
  for(auto [x, j] : left) {
    if(ans[j] != -1) continue;
    auto it = right.upper_bound(x);
    while(it != end(right) && (it->second == j || ans[it->second] != -1)) {
      it = right.erase(it);
    }
    if(it != end(right)) {
      ans[j] = ans[it->second] = (it->first - x) / 2;
      right.erase(it);
    }
  }
}

void solve(int m, const vector<tuple<int,int,int>>& v, vector<int>& ans) {
  solve(m, v, ans, 0, 0);
  solve(m, v, ans, 0, 1);
  solve(m, v, ans, 1, 0);
  solve(m, v, ans, 1, 1);
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> even, odd;
    for(int i=0; i<n; i++) {
      cin >> x[i];
      if(x[i] % 2) {
        odd.push_back(i);
      } else {
        even.push_back(i);
      }
    }
    vector<char> dir(n);
    for(int i=0; i<n; i++) {
      cin >> dir[i];
    }

    vector<tuple<int,int,int>> lv, rv;
    for(int i : even) {
      lv.emplace_back(x[i], dir[i] == 'R', i);
    }
    for(int i : odd) {
      rv.emplace_back(x[i], dir[i] == 'R', i);
    }

    vector<int> ans(n, -1);
    solve(m, lv, ans);
    solve(m, rv, ans);
    for(int i=0; i<n; i++) {
      cout << ans[i] << " ";
    }
    cout << nl;
  }

  return 0;
}