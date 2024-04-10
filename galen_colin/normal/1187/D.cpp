#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
int i, j;
typedef long long ll;
typedef pair<int, int> pii;

ll n, q, Q, t, T, m, k;
ll a[300001], b[300001], c[300001], d[300001];

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(6 * s, 0);
    lazy = vector<num_t>(6 * s, 0);
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

struct max_t {
  long long val;
  static const long long null_v = -9223372;

  max_t(): val(0LL) {}
  max_t(int v): val(v) {}

  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }
  
  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val);
  }
};

struct sum_t {
  long long val;
  static const long long null_v = 0;

  sum_t(): val(0) {}
  sum_t(int v): val(v) {}

  sum_t op(sum_t& other) {
    return sum_t(val + other.val);
  }
  
  sum_t lazy_op(sum_t v, int size) {
    return sum_t(val + v.val * size);
  }
};

vector<vector<int> > loc;
segtree<max_t> st;

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> n;
    loc = vector<vector<int> >(n+5);

    f0r(i, n) cin >> a[i];
    f0r(i, n) cin >> b[i];

    //compare elements of array
    f0r(i, n) {
      loc[a[i] - 1].pb(i);
      c[i] = a[i];
      d[i] = b[i];
    }
    sort(c, c+n);
    sort(d, d+n);
    bool fl = 0;
    f0r(i, n) {
      if (c[i] != d[i]) {
        cout << "NO" << endl;
        fl = 1;
        break;
      }
    }
    if (fl) continue;

    st.init(n, a);

    bool ok = 1;
    for (int i = n - 1; i >= 0; i--) {
      int lo = loc[b[i] - 1][loc[b[i] - 1].size() - 1];
      if (lo > n-1 || st.query(lo, n-1).val != b[i]) {
        ok = 0;
        break;
      }
      loc[b[i] - 1].pop_back();
      int c = a[i], d = b[i];
      st.update(lo, lo, -b[i]);
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}