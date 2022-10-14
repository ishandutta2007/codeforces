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

struct segtree {
  int n, depth;
  vector<ll> tree, lazy;

  segtree(): n(0){}
  segtree(int s): n(s), tree(4*s,0), lazy(4*s,0) {}

  segtree(int s, vector<long long>& arr): n(s), tree(4*s,0), lazy(4*s,0) {
    init(0, 0, n - 1, arr);
  }

  void init(int s, vector<long long>& arr) {
    n = s;
    tree = vector<ll>(4 * s, 0);
    lazy = vector<ll>(4 * s, -1);
    init(0, 0, n - 1, arr);
  }

  ll init(int i, int l, int r, vector<long long>& arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    ll a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a + b;
  }

  void update(int l, int r, ll v) {
    /*Adds v to every number in the range l to r*/
    update(0, 0, n - 1, l, r, v);
  }

  void update(int i, ll v){
    /*Adds v to index i*/
    update(0, 0, n-1, i, i, v);
  }

  void set_val(int i, ll v){
    /*Sets index i to value v*/
    update(i, v-query(i));
  }

  ll update(int i, int tl, int tr, int ql, int qr, ll v) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) {
      lazy[i] = v;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    ll a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a + b;
  }

  ll query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  ll query(int i){
    return query(0, 0, n-1, i, i);
  }

  ll query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return 0;

    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a+b;
  }

  /* varies by implementation */
  /* this one is for range additions */
  void eval_lazy(int i, int l, int r) {
    /* special part */
    if(lazy[i] == -1) return;
    tree[i] = lazy[i] * (r - l + 1);
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i];
      lazy[i * 2 + 2] = lazy[i];
    }
    /* end special part */
    lazy[i] = -1;
  }
};



int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n, q;
      cin >> n >> q;
      vl s(n), f(n);
      forn(i, n){
        char c;
        cin >> c;
        if(c=='1'){
          s[i] = 1;
        }
      }
      forn(i, n){
        char c;
        cin>> c;
        if(c=='1'){
          f[i] = 1;
        }
      }

      segtree seg;
      seg.init(n, f);
      // cout << seg.query(0, n-1) << "blah\n";
      bool works = true;
      vpi queries(q);
      forn(qi, q){
        int x, y;
        cin >> x >> y;
        x--;y--;
        queries[qi] = mp(x, y);
      }

      for(int qi=q-1; qi>=0; qi--){
        int x = queries[qi].f, y=queries[qi].s;
        int cnt = seg.query(queries[qi].f, queries[qi].s);
        // cout << cnt << " cnt\n";
        if(cnt*2 < y-x+1){
          seg.update(x, y, 0);
        }else if(cnt*2 > y-x+1){
          seg.update(x, y, 1);
        }else{
          //cout << "tie\n";
          works = false;
          break;
        }
      }
      forn(i, n){
        if(seg.query(i) != s[i]){
          works = false;
        }
      }
      if(works){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }
}