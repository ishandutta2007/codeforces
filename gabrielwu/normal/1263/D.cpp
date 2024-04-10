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
    int n;
    cin >> n;
    DSU d(26);
    vb cont(26, false);
    forn(i,n){
        string s;
        cin >> s;
        forn(i,s.size()-1){
            d.join((int) s[i] - ((int) 'a'), (int) s[i+1] - ((int) 'a'));
            cont[(int) s[i] - ((int) 'a')] = true;
        }
        cont[(int) s[s.size()-1] - ((int) 'a')] = true;
    }
    vi roots;
    forn(i,26){
        if(cont[i]){
            bool in = false;
            for(int p:roots){
                if(d.root(i) == p){
                    in = true;
                    break;
                }
            }
            if(!in){
                roots.pb(d.root(i));
            }
        }
    }
    cout << roots.size() << endl;
}