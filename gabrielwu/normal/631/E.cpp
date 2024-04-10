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



template<class T> struct LiChaoTree {

    int C;
    vector<T> tree;
    LiChaoTree(int _C){
      init(_C);
    }
    void init(int _C) {
        C = _C;
        tree = vector<T>(4*C);
    }
    void insert(T line){
      insert(line, 0, C, 0);
    }
    void insert(T line, int l, int r, int o) {
      if(l + 1 == r) {
        if(line(l) > tree[o](l)) tree[o] = line; //< for min
        return;
      }
      int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
      if(tree[o].m > line.m) swap(tree[o], line); //< for min
      if(tree[o](mid) < line(mid)) {  //> for min
        swap(tree[o], line);
        insert(line, l, mid, lson);
      }
      else insert(line, mid, r, rson);
    }
    ll query(int x){
      return query(x, 0, C, 0);
    }
    ll query(int x, int l, int r, int o) {
      if(l + 1 == r) return tree[o](x);
      int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
      if(x < mid) return max(tree[o](x), query(x, l, mid, lson)); //change for min
      else return max(tree[o](x), query(x, mid, r, rson));  //change for min
    }
};

struct Line {
  ll m, b;
  static const long long null_v = -9223372036854775807LL;
  //static const long long null_v = 9223372036854775807LL; //For min queries

  Line(): m(0), b(null_v) {}
  Line(ll _m, ll _b): m(_m), b(_b) {}

  ll operator()(ll x) { return m * x + b; }


};


int main(){
    fast_io();

    int n;
    cin >> n;
    vl v(n), pref(n);
    ll tot = 0;

    forn(i, n){
      cin >> v[i];
      pref[i] = v[i] + (i>0?pref[i-1]:0);
      tot += (i+1)*v[i];
    }
    ll best = 0;
    LiChaoTree<Line> lct(n);
    forn(r, n){
      if(r>0) best = max(best, lct.query(r)-pref[r]);
      lct.insert({v[r], (pref[r] - r*v[r])});
    }

    vl suff(n);
    for(int i=n-1; i>=0; i--){
      suff[i] = v[i] + (i<n-1?suff[i+1]:0);
    }
    lct = LiChaoTree<Line>(n);

    for(int l=n-1; l>=0; l--){
      if(l<n-1) best = max(best, lct.query(l)+suff[l]);
      lct.insert({v[l], (-suff[l] - v[l]*l)});
    }

    cout << tot + best << "\n";
}