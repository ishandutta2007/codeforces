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

struct Query {
  int l, r, k, t;
};

struct Put {
  int i, x, t;
};

const int N = 1e5 + 1;
const int S = 5000;
const int M = N / S + 1;
int a[N], init[N], have[N], vals[N], lb[N], rb[N], ans[N];
vector<Query> ask[M][M];
vector<Put> put;

int answer(int k, int n) {
  unsigned int best = -1;
  for(int i=0; i+k<=n; i++) {
    best = min(best, (unsigned int)(vals[i] - vals[i+k-1]));
  }
  return best;
}

void insert(int v) {
  vals[lb[have[v]]++] += 1;
  rb[++have[v]] += 1;
}

void remove(int v) {
  vals[--rb[have[v]]] -= 1;
  lb[--have[v]] -= 1;
}

void solve(const vector<Query>& v) {
  memset(have, 0, sizeof have);
  memset(vals, 0, sizeof vals);
  memset(lb, 0, sizeof lb);
  memset(rb, 0, sizeof rb);
  memcpy(a, init, sizeof init);

  int pid = 0;
  int left = 1;
  int right = 0;

  for(auto [l, r, k, t] : v) {
    while(pid < put.size() && put[pid].t < t) {
      auto [i, x, _] = put[pid++];
      if(left <= i && i <= right) {
        insert(x);
        remove(a[i]);
      }
      a[i] = x;
    }
    while(right < r) insert(a[++right]);
    while(left > l) insert(a[--left]);
    while(right > r) remove(a[right--]);
    while(left < l) remove(a[left++]);
    ans[t] = answer(k, lb[0]);
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

  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    cin >> init[i];
  }

  vector<int> out;
  for(int i=1; i<=m; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int l, r, k;
      cin >> l >> r >> k;
      ask[l/S][r/S].push_back({l, r, k, i});
      out.push_back(i);
    } else {
      int p, x;
      cin >> p >> x;
      put.push_back({p, x, i});
    }
  }

  for(int s=0; s<M; s++) {
    for(int t=s; t<M; t++) {
      if(ask[s][t].empty()) continue;
      solve(ask[s][t]);
    }
  }

  for(int i : out) {
    cout << ans[i] << nl;
  }

  return 0;
}