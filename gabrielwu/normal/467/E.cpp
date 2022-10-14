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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct trap_tree {
  int n;
  vector<vi> tree;

  trap_tree(): n(0){}
  trap_tree(int s): n(s), tree(4*s) {}

  int test(int i){
    return test(0, 0, n-1, i);
  }

  int test(int i, int tl, int tr, int q) {

    if (tl > tr || tr < q || q < tl) return -1;
    if(tree[i].size() > 0){
      return tree[i][0];
    }

    if (tl == tr) return -1;

    int mid = (tl + tr) / 2;
    int a = test(2 * i + 1, tl, mid, q);
    int b = test(2 * i + 2, mid + 1, tr, q);
    return max(a, b);
  }

  void  lay(int l, int r, int trap) {
    lay(0, 0, n-1, l, r, trap);
  }

  void lay(int i, int tl, int tr, int ql, int qr, int trap) {

    if (ql <= tl && tr <= qr){
      tree[i].pb(trap);
      return;
    }
    if (tl > tr || tr < ql || qr < tl) return;

    int mid = (tl + tr) / 2;
    lay(2 * i + 1, tl, mid, ql, qr, trap);
    lay(2 * i + 2, mid + 1, tr, ql, qr, trap);
    return;
  }
};


int main(){
    fast_io();
    int n;
    cin >> n;
    vi a(n);
    //vpi ps(n);
    forn(i, n){
      cin >> a[i];
    }
    //sort(ps.begin(), ps.end());
    vi ans;
    int ind = 0;
    trap_tree trap(n+2);
    while(ind < n){
      unordered_map<int, int, custom_hash> last;
      unordered_map<int, int, custom_hash> cnt;
      bool done = false;
      while(!done && ind < n){
        int la = last[a[ind]];
        cnt[a[ind]]++;
        if(cnt[a[ind]] >= 4){
          done = true;
          ans.pb(a[ind]);
          ans.pb(a[ind]);
          ans.pb(a[ind]);
          ans.pb(a[ind]);
        }else if(la != 0){
          int x = trap.test(la);
          if(x>=0){
            done = true;
            ans.pb(x);
            ans.pb(a[ind]);
            ans.pb(x);
            ans.pb(a[ind]);
          }else{
            trap.lay(la+1, ind, a[ind]);
          }
        }
        last[a[ind]] = ind+1;
        ind++;
      }
    }
    cout << ans.size() << "\n";
    forn(i, ans.size()){
      cout << ans[i] << " ";
    }
}