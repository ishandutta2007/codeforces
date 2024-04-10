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
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

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

int main(){
    fast_io();
    int h, w;
    cin >> h >> w;
    vi r(h), c(w);
    vector<vector<int> > grid(h, vector<int>(w, -1));
    ll out = 1;

    forn(i,h){
        cin >> r[i];
        forn(j,r[i]){
            grid[i][j] = 1;
        }
        if(r[i]<w){
            grid[i][r[i]] = 0;
        }
    }
    forn(i,w){
        cin >> c[i];
        forn(j,c[i]){
            if(grid[j][i] == 0){
                out = 0;
            }
            grid[j][i] = 1;
        }
        if(c[i]<h){
            if(grid[c[i]][i] == 1){
                out = 0;
            }
            grid[c[i]][i] = 0;
        }
    }

    forn(i,h){
        forn(j,w){
            if(grid[i][j] == -1){
                out *= 2;
                out %= MOD;
            }
        }
    }

    cout << out << endl;


}