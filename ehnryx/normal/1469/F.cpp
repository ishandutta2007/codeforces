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

const int N = 1<<20;
ll st[2*N], z[2*N];

void push(int i) {
  if(z[i]) {
    st[2*i] += z[i]/2;
    st[2*i+1] += z[i]/2;
    z[2*i] += z[i]/2;
    z[2*i+1] += z[i]/2;
    z[i] = 0;
  }
}

void pull(int i) {
  st[i] = st[2*i] + st[2*i+1];
}

void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
  if(r<s || e<l) return;
  if(l<=s && e<=r) {
    int tot = v * (e-s+1);
    st[i] += tot;
    z[i] += tot;
    return;
  }
  push(i);
  int m = (s+e) / 2;
  insert(l, r, v, 2*i, s, m);
  insert(l, r, v, 2*i+1, m+1, e);
  pull(i);
}

unsigned int kth(int k, int i=1, int s=0, int e=N-1) {
  if(s == e) return i-N;
  push(i);
  int m = (s+e) / 2;
  if(st[2*i] >= k) return kth(k, 2*i, s, m);
  else return kth(k - st[2*i], 2*i+1, m+1, e);
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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());

  ll have = 1;
  insert(0, 0, 1);
  unsigned int ans = -1;
  for(int v : a) {
    int first = kth(1);
    int half = (v-1)/2;
    int other = v-1 - half;
    insert(first, first, -1);
    insert(first+2, first+2+half-1, 1);
    insert(first+2, first+2+other-1, 1);
    have += v - 2;
    if(k <= have) {
      ans = min(ans, kth(k));
    }
  }
  cout << (int)ans << nl;

  return 0;
}