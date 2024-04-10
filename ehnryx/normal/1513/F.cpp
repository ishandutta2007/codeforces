#pragma GCC optimize("O3")

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

struct SegmentTree {
  int n;
  vector<ll> st;
  SegmentTree(int _n) {
    n = 1 << (32 - __builtin_clz(max(1, _n - 1)));
    st.resize(2 * n, INFLL);
  }
  void insert(int i, ll v) {
    st[i += n] = v;
    for(i/=2; i; i/=2) {
      st[i] = min(st[2*i], st[2*i+1]);
    }
  }
  ll query(int l, int r) {
    ll res = INFLL;
    for(l+=n, r+=n; l<r; l/=2, r/=2) {
      if(l&1) res = min(res, st[l++]);
      if(r&1) res = min(res, st[--r]);
    }
    return res;
  }
};

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

  int n;
  cin >> n;
  map<ll,int> remap;
  vector<ll> a(n), b(n);
  vector<pair<ll,int>> oa, ob;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    remap[a[i]];
    oa.emplace_back(a[i], i);
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
    remap[b[i]];
    ob.emplace_back(b[i], i);
  }
  int rid = 0;
  for(auto& it : remap) {
    it.second = rid++;
  }

  sort(begin(oa), end(oa));
  sort(begin(ob), end(ob));

  ll ans = 0;
  for(int iter=0; iter<2; iter++) {
    // aj < bi
    SegmentTree smaller(rid), larger(rid);
    int apre = 0;
    for(auto [bi, i] : ob) {
      while(apre < n && oa[apre].first <= bi) {
        auto [aj, j] = oa[apre];
        smaller.insert(remap[b[j]], -aj - b[j] - abs(aj - b[j]));
        larger.insert(remap[b[j]], -aj + b[j] - abs(aj - b[j]));
        apre++;
      }
      int mid = remap[a[i]];
      ll cur = bi + a[i] + smaller.query(0, mid) - abs(a[i] - bi);
      ll oth = bi - a[i] + larger.query(mid, rid) - abs(a[i] - bi);
      ans = min(ans, min(cur, oth));
    }
    swap(a, b);
    swap(oa, ob);
  }

  //cerr << "shift: " << ans << nl;
  for(int i=0; i<n; i++) {
    ans += abs(a[i] - b[i]);
  }
  cout << ans << nl;

  return 0;
}