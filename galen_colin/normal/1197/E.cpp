#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  /* varies by implementation */
  /* this one is for range additions */
  void eval_lazy(int i, int l, int r) {
    /* special part */
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }
    /* end special part */

    lazy[i] = num_t();
  }
};

struct min_t {
  ll val;
  static const long long null_v = 9223372036854775807LL;

  min_t(): val(0) {}
  min_t(ll v): val(v) {}

  min_t op(min_t& other) {
    return min_t(min(val, other.val));
  }
  
  min_t lazy_op(min_t v, int size) {
    return min_t(val + v.val);
  }
};


ll i, j;
const ll mod = 1e9 + 7;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
pair<ll, ll> v[200001];
pair<ll, ll> dp[200001];
ll a[200001];
ll sufm[200001];
bool ok[200001];
vector<ll> comp;
vector<ll> loc[200001];
vector<ll> sum[200001];
segtree<min_t> st;

int bins(ll o) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (v[m].s > o) r = m - 1;
    else l = m + 1;
  }
  return r;
}

int bins_c(ll v) {
  int l = 0, r = comp.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (comp[m] == v) return m;
    if (comp[m] > v) r = m - 1;
    else l = m + 1;
  }
  return -1;
}

int bins_loc(ll i, ll o) {
  int l = 0, r = loc[i].size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (loc[i][m] > o) r = m - 1;
    else l = m + 1;
  }
  return r;
}

int main() {
  io;
  // freopen("a", "r", stdin);
  // freopen("a", "w", stdout);
  // cin >> Q;
  // f0r(q, Q) {
    cin >> n;
    f0r(i, n) cin >> v[i].f >> v[i].s;
    sort(v, v+n);
    f0r(i, n) swap(v[i].f, v[i].s);
    // cout << endl;
    // f0r(i, n) cout << v[i].f << " " << v[i].s << endl;

    ms(a, 0);
    st.init(n, a);
    f0r(i, n) {
      ll r = bins(v[i].f);
      if (r == -1) dp[i].f = v[i].f;
      else dp[i].f = v[i].f + st.query(0, r).val;
      st.update(i, i, dp[i].f - v[i].s);
    }
    comp = vector<ll>(n);
    f0r(i, n) comp[i] = dp[i].f - v[i].s;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    f0r(i, n) {
      int x = bins_c(dp[i].f - v[i].s);
      loc[x].pb(i);
    }

    // f0r(i, comp.size()) {
    //   cout << i << " - ";
    //   f0r(j, loc[i].size()) cout << loc[i][j] << " ";
    //   cout << endl;
    // }

    sufm[n-1] = v[n-1].f;
    for (int i = n-2; i >= 0; i--) {
      sufm[i] = max(v[i].f, sufm[i+1]);
    }

    /* find minimum val */
    ms(ok, 0);
    ll best = 1e9;
    f0r(i, n) {
      if (i == n-1 || v[i].s > sufm[i+1]) {
        best = min(best, dp[i].f);
        ok[i] = 1;
      } else {
        ok[i] = 0;
      }
    }

    // f0r(i, n) cout << v[i] << " " << dp[i].f - v[i].s << endl;

    ll ans = 0;
    /* count values */
    // f0r(i, n) cout << st.query(i, i).val << " ";
    // cout << endl;
    f0r(i, n) {
      ll r = bins(v[i].f);
      ll x, y;
      if (r == -1) {
        dp[i].s = 1;
      }
      else {
        x = bins_c(st.query(0, r).val);
        ll y = bins_loc(x, r);
        // cout << x << " " << r << " " << y << endl;
        if (y >= sum[x].size() || y == -1) dp[i].s = 1;
        else dp[i].s = sum[x][y];
      }
      x = bins_c(dp[i].f - v[i].s);
      if (sum[x].size() == 0) sum[x].pb(dp[i].s);
      else sum[x].pb((sum[x][sum[x].size() - 1] + dp[i].s) % mod);
      if (dp[i].f == best && ok[i]) ans += dp[i].s;
    }
    // f0r(i, comp.size()) {
    //   cout << i << " - ";
    //   f0r(j, sum[i].size()) cout << sum[i][j] << " ";
    //   cout << endl;
    // }
    // f0r(i, n) {
    //   cout << ok[i] << " " << dp[i].f << " " << dp[i].s << endl;
    // }
    cout << ans%mod << endl;
}