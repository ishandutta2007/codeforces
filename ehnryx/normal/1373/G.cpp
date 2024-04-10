//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

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

const int N = 1 << 19;
int st[2*N], z[2*N];

void push(int i) {
  if(z[i]) {
    st[2*i] += z[i];
    st[2*i+1] += z[i];
    z[2*i] += z[i];
    z[2*i+1] += z[i];
    z[i] = 0;
  }
}

void pull(int i) {
  st[i] = max(st[2*i], st[2*i+1]);
}

void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
  //if(i == 1) cerr<<"INSERT "<<l<<" "<<r<<" "<<v<<nl;
  if(r<s || e<l) return;
  if(l<=s && e<=r) {
    st[i] += v;
    z[i] += v;
    return;
  }
  push(i);
  int m = (s+e) / 2;
  insert(l, r, v, 2*i, s, m);
  insert(l, r, v, 2*i+1, m+1, e);
  pull(i);
}

int query(int l, int r, int i=1, int s=0, int e=N-1) {
  if(r<s || e<l) return 0;
  if(l<=s && e<=r) {
    return st[i];
  }
  push(i);
  int m = (s+e) / 2;
  return max(query(l, r, 2*i, s, m), query(l, r, 2*i+1, m+1, e));
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int n, k, m;
  cin >> n >> k >> m;

  multiset<int> top;
  top.insert(n);
  for(int i=1; i<=n; i++) {
    insert(1, i, -1);
  }

  set<pair<int,int>> have;
  for(int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    int v = y + abs(x-k);
    if(have.insert(make_pair(x, y)).second) {
      insert(1, v, 1);
      int old = *top.rbegin();
      top.insert(v);
      int cur = *top.rbegin();
      if(cur != old) {
        for(int j=old+1; j<=cur; j++) {
          insert(1, j, -1);
        }
      }
    } else {
      have.erase(make_pair(x, y));
      insert(1, v, -1);
      int old = *top.rbegin();
      top.erase(top.find(v));
      int cur = *top.rbegin();
      if(cur != old) {
        for(int j=cur+1; j<=old; j++) {
          insert(1, j, 1);
        }
      }
    }

    int ub = *top.rbegin();
    int ans = max(0, query(1, ub));
    cout << ans + ub - n << nl;
  }

  return 0;
}