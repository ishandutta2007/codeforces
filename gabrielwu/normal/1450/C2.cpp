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
      vi d(3), e(3);
      vector<vi> v(n, vi(n));
      forn(i, n){
        forn(j, n){
          char c;
          cin >> c;
          if(c=='.') v[i][j] = 0;
          else if(c=='O') v[i][j] = 1;
          else if(c=='X') v[i][j] = 2;

          if(v[i][j]==2) d[(i+j)%3]++;
          if(v[i][j]==1) e[(i+j)%3]++;
          /*if((i+j)%2 == 0){
            if(v[i][j] == 1) d[(i+j)%3]++;
          }else if((i+j)%2 == 1){
            if(v[i][j] == 2) d[(i+j)%3]++;
          }*/
        }
      }

      int c;
      int de2 = d[2] + e[0];
      int de1 = d[1] + e[2];
      int de0 = d[0] + e[1];
      if(de2 <= de1 && de2 <= de0){
        c = 2;
      }else if(de1 <= de0 && de1 <= de2){
        c = 1;
      }else{
        c = 0;
      }

      forn(i, n){
        forn(j, n){
          if((i+j)%3 == c){
            if(v[i][j] == 2) v[i][j] = 1;
          }if((i+j)%3 == (c+1)%3){
            if(v[i][j] == 1) v[i][j] = 2;
          }
            /*
            if((i+j)%2 == 0){
              if(v[i][j] == 1) v[i][j] = 2;
            }else if((i+j)%2 == 1){
              if(v[i][j] == 2) v[i][j] = 1;
            }
            */
        }
      }

      forn(i, n){
        forn(j, n){
          if(v[i][j]==2) cout << "X";
          else if(v[i][j]==1) cout << "O";
          else if(v[i][j]==0) cout << ".";
        }cout << "\n";
      }
    }
}