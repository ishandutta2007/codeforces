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
template<class T> struct SegTree {
    const T ID = -922337203685477580LL;
    T comb(T a, T b) {
        return max(a, b); //Edit op here
    }
    int n;
    vector<T> seg;
    SegTree(int s){
      init(s);
    }
    void init(int _n) {
        n = _n;
        seg.assign(2 * n, ID);
    }
    void pull(int p) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }
    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

int main(){
    fast_io();
    int n;
    cin >> n;
    vi h(n);
    vl b(n);
    forn(i, n){
      cin >> h[i];
    }
    forn(i, n){
      cin >> b[i];
    }
    SegTree<ll> st(n);
    vi left(n);
    SegTree<ll> stshort(n+1);
    for(int i=0; i<n; i++){
      ll x = stshort.query(0, h[i]-1);
      if(x<=0){
        left[i] = i;
      }else{
        left[i] = x-1;
      }
      stshort.upd(h[i], i+1);
    }
    st.upd(0, b[0]);
    for(int i=1; i<n; i++){
      ll dp;
      if(left[i] == i){
        dp = max(0LL, st.query(0, i-1)) + b[i];
      }else{
        if(left[i] == i-1) dp = max(st.query(left[i], left[i]), st.query(left[i], left[i]) + b[i]);
        else dp = max(st.query(left[i], left[i]), st.query(left[i]+1, i-1) + b[i]);
      }
      st.upd(i, dp);
    }
    // cout << left;
    cout << st.query(n-1, n-1) << "\n";
}