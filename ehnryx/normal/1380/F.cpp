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

vector<int> cnt(100);

const int N = 1 << 19;
#ifdef ONLINE_JUDGE
static_assert(N > 5e5);
#endif

int val[N];
ll st[2*N], lst[2*N], rst[2*N], mst[2*N];

void insert(int i, int v) {
  int s = i;
  int e = i + 1;
  int len = 1;
  val[s] = v;

  i += N;
  st[i] = cnt[v];
  lst[i] = rst[i] = 1;
  mst[i] = 0;

  for(i /= 2; i > 0; i /= 2, len *= 2) {
    if(__builtin_ctz(s) < __builtin_ctz(e)) {
      s -= len;
    } else {
      e += len;
    }

    int m = (s+e) / 2;
    st[i] = st[2*i] * st[2*i+1] % MOD;
    lst[i] = st[2*i] * lst[2*i+1] % MOD;
    rst[i] = rst[2*i] * st[2*i+1] % MOD;
    mst[i] = rst[2*i] * lst[2*i+1] % MOD;
    if(val[m-1] == 1) {
      int mid = 10 + val[m];
      st[i] = (st[i] + lst[2*i] * rst[2*i+1] % MOD * cnt[mid]) % MOD;
      lst[i] = (lst[i] + lst[2*i] * mst[2*i+1] % MOD * cnt[mid]) % MOD;
      rst[i] = (rst[i] + mst[2*i] * rst[2*i+1] % MOD * cnt[mid]) % MOD;
      mst[i] = (mst[i] + mst[2*i] * mst[2*i+1] % MOD * cnt[mid]) % MOD;
    }
  }
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

  for(int i=0; i<10; i++) {
    cnt[i] = i + 1;
  }
  for(int i=18; i>=10; i--) {
    cnt[i] = 19 - i;
  }

  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    char c;
    cin >> c;
    insert(N-n+i, c - '0');
  }
  for(int i=0; i<N-n; i++) {
    insert(i, 0);
  }

  for(int i=0; i<m; i++) {
    int x; char c;
    cin >> x >> c;
    insert(N-n+x-1, c - '0');
    cout << st[1] << nl;
  }

  return 0;
}