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

struct DSU{
    vi parent;//Parent of each element. If parent[i] = i, it is a root of a set
    vi num_elements;//Number of elements in a set given by a root.
    int n;

    DSU(int n):n(n),parent(n),num_elements(n,1){
        forn(i,n){
            parent[i] = i;
        }
    }

    //Merge the two sets that x and y are in.
    void join(int x, int y){
        if(parent[x] == parent[y]){
            return; //already in same set
        }
        int xroot = root(x);
        int yroot = root(y);

        if(num_elements[xroot] < num_elements[yroot]){
            parent[xroot] = yroot;
            num_elements[yroot] += num_elements[xroot];
        }else{
            parent[yroot] = xroot;
            num_elements[xroot] += num_elements[yroot];
        }
    }

    //Find root of an element. Uses path splitting for efficiency. (compresses path)
    int root(int x){
        while (parent[x] != x){
            int prev = x;
            x = parent[x];
            parent[prev] = parent[x];
        }
        return x;
    }

    //Whether two elements are in the same set.
    bool together(int x, int y){
        return root(x) == root(y);
    }
};

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n, m;
      cin >> n >> m;
      DSU d(n);
      vi in(n);
      int ans = m;
      forn(i, m){
        int x, y;
        cin >> x >> y;
        x--;y--;
        if(x==y){
          ans--;
          continue;
        }
        in[x]++;
        in[y]++;
        d.join(x, y);
      }

      int minus = 0;
      forn(i, n){
        if(d.root(i) == i){
          ans++;

        }
        if(in[i]==0){
          minus += 2;
        }else if(in[i] == 1){
          minus += 1;
        }
      }
      //cout << "ans " << ans << " " << minus << "\n";
      ans -= minus/2;
      cout << ans << "\n";
    }
}