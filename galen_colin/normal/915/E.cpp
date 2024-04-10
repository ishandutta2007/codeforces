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
int i, j;

int t[600001], pre[600001];

struct segtree {
  int n, depth;
  vector<int> tree;
  vector<char> lazy;

  void init(int s, int* arr) {
    n = s;
    tree = vector<int>(4 * s, 0);
    lazy = vector<char>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  int init(int i, int l, int r, int* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    return tree[i] = init(2 * i + 1, l, mid, arr) + init(2 * i + 2, mid + 1, r, arr);
  }

  void update(int l, int r, int v) {
    update(0, 0, n - 1, l, r, v);
  }

  int update(int i, int tl, int tr, int ql, int qr, int v) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) {
      lazy[i] = v;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    return tree[i] = update(2 * i + 1, tl, mid, ql, qr, v) + update(2 * i + 2, mid + 1, tr, ql, qr, v);
  }

  int query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  int query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return 0;

    int mid = (tl + tr) / 2;
    return query(2 * i + 1, tl, mid, ql, qr) + query(2 * i + 2, mid + 1, tr, ql, qr);
  }

  /* varies by implementation */
  /* this one is for range additions */
  void eval_lazy(int i, int l, int r) {
    /* special part */
    switch (lazy[i]) {
      case 1: 
        tree[i] = 0;
        break;
      case 2:
        if (l == 0) tree[i] = pre[r];
        else tree[i] = pre[r] - pre[l-1];
        break;
      default:
        break;
    }
    // cout << i << " " << l << " " << r << " " << lazy[i].val << " " << tree[i].val << endl;
    if (l != r && lazy[i]) {
      lazy[i * 2 + 1] = lazy[i];
      lazy[i * 2 + 2] = lazy[i];
    }
    /* end special part */

    lazy[i] = 0;
  }
};

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

int n, Q, T, m, k, r, x, y, z, g;
int a, b, c, d;
pair<pii, int> q[300001];
vector<int> v;
segtree st;
int dif[600001];

int bins(int l, int r, int v) {
  assert(l <= r);
  int mid = (l + r)/2;
  if (t[mid] == v) return mid;
  if (t[mid] < v) return bins(mid+1, r, v);
  else return bins(l, mid-1, v);
}

int main() {
  io;
  cin >> n >> Q;
  // auto a = high_resolution_clock::now(); 

  // n = floor(1e1), Q = 300000;
  f0r(i, Q) {
    cin >> q[i].f.f >> q[i].f.s >> q[i].s;
    // q[i].f.f = rand() % n, q[i].f.s = q[i].f.f + (rand() % (n - q[i].f.f));
    // q[i].s = (rand() % 2) + 1;
    v.pb(q[i].f.f);
    v.pb(++q[i].f.s);
  }
  v.pb(1);
  v.pb(n+1);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int pt = 0;
  for (int i: v) {
    t[pt++] = i;
  }
  f0r(i, pt-1) dif[i] = t[i+1] - t[i];
  pt--;
  pre[0] = dif[0];
  f1r(i, 1, pt) pre[i] = dif[i] + pre[i-1];
  st.init(pt, dif);
  f0r(i, Q) {
    q[i].f.f = bins(0, pt, q[i].f.f);
    q[i].f.s = bins(0, pt, q[i].f.s);
    --q[i].f.s;
    // cout << q[i].f.f << " " << q[i].f.s << endl;
  }
  f0r(i, Q) {
    st.update(q[i].f.f, q[i].f.s, q[i].s);
    cout << st.query(0, pt-1) << '\n';
  }
  cout.flush();
  // auto b = high_resolution_clock::now(); 
	// auto duration = duration_cast<microseconds>(b - a); 
	// cout << duration.count() << endl; 

}