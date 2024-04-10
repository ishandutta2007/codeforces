/**
TASK:
USER: gabriel90
LANG: C++
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define printVec(v) for(auto e: v){cout << e << " ";} cout << endl;
#define pb push_back
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
  segtree(int s): n(s), tree(4*s,0), lazy(4*s,0) {}

  segtree(int s, vector<long long>& arr): n(s), tree(4*s,0), lazy(4*s,0) {
    init(0, 0, n - 1, arr);
  }

  void init(int s, vector<long long>& arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, vector<long long>& arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    /*Adds v to every number in the range l to r*/
    update(0, 0, n - 1, l, r, v);
  }

  void update(int l, int r, long v) {
    /*Adds v to every number in the range l to r*/
    update(0, 0, n - 1, l, r, num_t(v));
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

//For min seg trees
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

//For max seg trees
struct max_t {
  ll val;
  static const long long null_v = -10000000LL;

  max_t(): val(0) {}
  max_t(ll v): val(v) {}

  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }

  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val);
  }
};


int main(){
    fast_io();
    int n;
    cin >> n;
    segtree<max_t> smax(1000005);
    segtree<min_t> smin(1000005);
    int pt = 0;
    vi line(1000005);
    int cnt = 0;
    forn(i,n){
        char c;
        cin >> c;
        if(c=='R'){
            pt++;
        }else if(c=='L'){
            if(pt>0){pt--;}
        }else if(c=='('){
            if(line[pt]==0){
                smax.update(pt,1000004,1);
                smin.update(pt,1000004,1);
                cnt ++;
            }else if(line[pt] == -1){
                smax.update(pt,1000004,2);
                smin.update(pt,1000004,2);
                cnt+=2;
            }

            line[pt] = 1;
        }
        else if(c==')'){
            if(line[pt]==0){
                smax.update(pt,1000004,-1);
                smin.update(pt,1000004,-1);
                cnt--;
            }else if(line[pt] == 1){
                smax.update(pt,1000004,-2);
                smin.update(pt,1000004,-2);
                cnt-=2;
            }
            line[pt] = -1;
        }else{
            if(line[pt]==1){
                smax.update(pt,1000004,-1);
                smin.update(pt,1000004,-1);
                cnt--;
            }else if(line[pt] == -1){
                smax.update(pt,1000004,1);
                smin.update(pt,1000004,1);
                cnt++;
            }
            line[pt] = 0;
        }

        if(cnt==0 && smin.query(0,1000004).val>=0){
            cout << smax.query(0,1000004).val << " ";
        }else{
            cout << -1 << " ";
        }

    }
    cout << endl;
}