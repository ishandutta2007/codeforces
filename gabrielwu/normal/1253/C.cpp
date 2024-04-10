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

int main(){
    fast_io();
    int n, m;
    cin >> n >> m;
    vl a(n),p(n);
    forn(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    p[0] = a[0];
    for(int i=1; i<n; i++){
        p[i] = p[i-1]+a[i];
    }
    vector<vl> grid(m, vl(n/m+1));
    forn(i, m){
        grid[i][0] = p[i];
        for(int j=1; j<n/m+1; j++){
            if(i+j*m<n){
                grid[i][j] = grid[i][j-1] + p[i+j*m];
            }
        }
    }
    //cout << a << endl;
    //cout << p << endl;
    //cout << grid << endl;

    forn(i,n){
        cout << grid[i%m][i/m] << " ";
    }
}