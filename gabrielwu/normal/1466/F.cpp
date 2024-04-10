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

    vb doubled;

    DSU(int n):n(n),parent(n),num_elements(n,1),doubled(n){
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
            if(doubled[xroot]) doubled[yroot] = true;
            num_elements[yroot] += num_elements[xroot];
        }else{
            parent[yroot] = xroot;
            if(doubled[yroot]) doubled[xroot] = true;
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
    int n, m;
    cin >> n >> m;
    vpi sing; //index, node
    DSU d(m);
    vi ans;
    forn(i, n){
      int k;
      cin >> k;
      if(k==1){
        int a;
        cin >> a; a--;
        if(!d.doubled[d.root(a)]){
          d.doubled[d.root(a)] = true;
          ans.pb(i);
        }
        // sing.pb(mp(i, a));
      }else{
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(!d.together(a, b) && !(d.doubled[d.root(a)] && d.doubled[d.root(b)])){
          d.join(a, b);
          ans.pb(i);
        }
      }
    }
    // vb doubled(m);
    // for(pii s: sing){
    //   if(!doubled[d.root(s.s)]){
    //     doubled[d.root(s.s)] = true;
    //     ans.pb(s.f);
    //   }
    // }
    ll tot = 1;
    vl res(m+1);
    res[0] = 1;
    forn(i, m){
      res[i+1] = (res[i]*2)%MOD;
    }
    forn(i, m){
      if(d.root(i) == i){
        if(d.doubled[i]){
          tot = (((tot*res[d.num_elements[i]-1])%MOD)*2)%MOD;
        }else{
          tot = ((tot*res[d.num_elements[i]-1])%MOD);
        }
      }
    }
    sort(ans.begin(), ans.end());
    cout << tot << " " << ans.size() << "\n";
    for(int x: ans){
      cout << x+1 << " ";
    }
    cout << "\n";
}