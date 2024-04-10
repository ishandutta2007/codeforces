#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

template <typename num_t>
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  segtree(): n(0){}
  segtree(int s): n(s), tree(4*s,0) {}

  segtree(int s, vector<long long>& arr): n(s), tree(4*s,0) {
    init(0, 0, n - 1, arr);
  }

  void init(int s, vector<long long>& arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, vector<long long>& arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int i, ll v){
    /*Adds v to index i*/
    update(0, 0, n-1, i, num_t(v));
  }

  void set_val(int i, ll v){
    /*Sets index i to value v*/
    update(i, v-query(i));
  }

  num_t update(int i, int tl, int tr, int q, num_t v) {

    if (tl > tr || tr < q || q < tl) return tree[i];
    if (tl == tr && q == tl){
      tree[i].val += v.val;
    }
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, q, v),
          b = update(2 * i + 2, mid + 1, tr, q, v);
    return tree[i] = a.op(b);
  }

  ll query(int l, int r) {
    return query(0, 0, n-1, l, r).val;
  }

  ll query(int i){
    return query(0, 0, n-1, i, i).val;
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {

    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

//For addition seg trees
struct add_t {
  ll val;
  static const long long null_v = 0;

  add_t(): val(0) {}
  add_t(ll v): val(v) {}

  add_t op(add_t& other) {
    return add_t(val + other.val);
  }
};

int main(){
    fast_io();
    int n, q;
    cin >> n >> q;
    vi a(n);
    forn(i, n){
      cin >> a[i];
      a[i]--;
    }
    vector<pair<pii, int>> qs(q);
    forn(i, q){
      int x, y;
      cin >> x >> y;
      qs[i] = mp(mp(x, y), i);
    }
    vi ans(q);
    sort(qs.begin(), qs.end(), [] (pair<pii, int> p1, pair<pii, int> p2){
           return p1.f.s > p2.f.s;
         });

    segtree<add_t> res(n+2);
    int qptr = 0;
    int tot = 0;
    forn(i, n){
      int x = (i)-a[i];
      if(x >= 0 && x <= tot){
        int lo = 0;
        int hi = i;
        while(hi > lo){
          int mid = (hi+lo+1)/2;
          int val = res.query(mid, n);
          if(val < x){
            hi = mid-1;
          }else{
            lo = mid;
          }
        }
        //cout << i << " " << lo << " " << x <<"*\n";
        res.update(lo, 1);
        tot ++;
      }

      while(qptr < q && n - qs[qptr].f.s == i+1){
        ans[qs[qptr].s] = res.query(qs[qptr].f.f, n);
        qptr++;
      }
    }

    forn(i, q){
      cout << ans[i] <<"\n";
    }
}