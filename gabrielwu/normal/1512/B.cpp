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


int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vector<vector<char>> vc(n, vector<char>(n));
      vi x, y;
      forn(i, n){
        forn(j, n){
          cin >> vc[i][j];
          if(vc[i][j] == '*'){
            x.pb(i);
            y.pb(j);
          }
        }
      }
      if(x[0] == x[1]) x.pop_back();
      if(y[0] == y[1]) y.pop_back();
      if(x.size() > 1){
        if(y.size() > 1){
          vc[x[0]][y[1]] = '*';
          vc[x[1]][y[0]] = '*';
        }else{
          if(y[0] == 0){
            vc[x[0]][y[0]+1] = '*';
            vc[x[1]][y[0]+1] = '*';
          }else{
            vc[x[0]][y[0]-1] = '*';
            vc[x[1]][y[0]-1] = '*';

          }
        }
      }else{

        if(x[0] == 0){
          vc[x[0]+1][y[0]] = '*';
          vc[x[0]+1][y[1]] = '*';
        }else{
          vc[x[0]-1][y[0]] = '*';
          vc[x[0]-1][y[1]] = '*';

        }

      }

      forn(i, n){
        forn(j, n){
          cout << vc[i][j];
        }
        cout << "\n";
      }
      //cout << "\n";
    }
}