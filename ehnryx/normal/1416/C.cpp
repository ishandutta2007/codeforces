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

pair<ll,int> solve(int j, const vector<vector<int>>& b) {
  if(j < 0) {
    return make_pair(0, 0);
  }

  ll keep = 0, flip = 0;
  vector<vector<int>> nxt;
  for(const vector<int>& a : b) {
    vector<int> one, zero;
    for(int v : a) {
      if(v & 1<<j) {
        one.push_back(v);
        flip += zero.size();
      } else {
        zero.push_back(v);
        keep += one.size();
      }
    }
    if(!one.empty()) nxt.push_back(one);
    if(!zero.empty()) nxt.push_back(zero);
  }

  auto [inv, ans] = solve(j-1, nxt);
  if(keep <= flip) {
    return make_pair(inv + keep, ans);
  } else {
    return make_pair(inv + flip, ans | 1<<j);
  }
}

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

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> b(1, a);
  auto [inv, ans] = solve(30, b);
  cout << inv << " " << ans << nl;

  return 0;
}