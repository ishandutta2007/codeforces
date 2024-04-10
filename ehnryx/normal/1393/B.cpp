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

const int N = 1e5 + 7;
int cnt[N];
set<pair<int,int>> cur;

void add(int v) {
  cur.erase(make_pair(cnt[v], v));
  cur.insert(make_pair(++cnt[v], v));
}

void remove(int v) {
  cur.erase(make_pair(cnt[v], v));
  cur.insert(make_pair(--cnt[v], v));
}

bool valid() {
  auto it = cur.rbegin();
  if(it->first >= 8) {
    return true;
  } else if(it->first >= 6 && next(it)->first >= 2) {
    return true;
  } else if(it->first >= 4 && next(it)->first >= 4) {
    return true;
  } else if(it->first >= 4 && next(it)->first >= 2 && next(next(it))->first >= 2) {
    return true;
  }
  return false;
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

  add(N-1);
  add(N-2);
  add(N-3);

  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    int v;
    cin >> v;
    add(v);
  }

  int m;
  cin >> m;
  for(int i=0; i<m; i++) {
    char t;
    int v;
    cin >> t >> v;
    if(t == '+') {
      add(v);
    } else {
      remove(v);
    }
    if(valid()) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }

  return 0;
}