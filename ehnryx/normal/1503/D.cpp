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
  vector<int> match(2*n + 1);
  vector<bool> top(2*n + 1);
  for(int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    match[a] = b;
    match[b] = a;
    top[a] = true;
  }

  vector<int> val(2*n + 2);
  int ans = 0;
  for(int l=1, r=2*n; l<r; ) {
    //cerr << l << " " << r << nl;
    vector<int> all;
    int li = 1;
    int ri = n;
    val[l] = li;
    val[match[l]] = -li;
    li++;
    all.push_back(l);
    all.push_back(match[l]);

    int lto = l;
    int rto = match[l];
    while(l <= lto || r >= rto) {
      while(r >= rto) {
        if(!val[r]) {
          val[r] = ri;
          val[match[r]] = -ri;
          ri--;
          all.push_back(r);
          all.push_back(match[r]);
          lto = max(lto, match[r]);
        }
        r--;
      }
      while(l <= lto) {
        if(!val[l]) {
          val[l] = li;
          val[match[l]] = -li;
          li++;
          all.push_back(l);
          all.push_back(match[l]);
          rto = min(rto, match[l]);
        }
        l++;
      }
    }

    sort(begin(all), end(all));
    int cnt = 0;
    int pos = -INF, neg = -INF;
    for(int i : all) {
      if(val[i] > 0) {
        if(pos > val[i]) {
          cout << -1 << nl;
          return 0;
        }
        pos = val[i];
        cnt += top[i];
      } else {
        if(neg > val[i]) {
          cout << -1 << nl;
          return 0;
        }
        neg = val[i];
      }
    }

    ans += min(cnt, (int)size(all)/2 - cnt);
  }

  cout << ans << nl;

  return 0;
}