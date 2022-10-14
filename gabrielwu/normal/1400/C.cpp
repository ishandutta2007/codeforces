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
      string s;
      cin >> s;
      int n = s.size();
      int x;
      cin >> x;
      /*
      bool works = true;
      for(int i=0; i<n-2*x; i++){
        if(s.at(i) != s.at(i+2*x)){
          works = false;
          break;
        }
      }

      if(!works){
        cout << -1 <<endl;
        continue;
      }*/

      vb ans(n, true);
      forn(i, n){
        if(s.at(i) == '0'){
          if(i+x < n){
            ans[i+x] = false;
          }
          if(i-x >= 0){
            ans[i-x] = false;
          }
        }
      }
      bool works = true;
      forn(i, n){
        bool b = (i >=x && ans[i-x]) || (i+x < n && ans[i+x]);
        if(!b && s.at(i) == '1'){
          cout << -1;
          works = false;
          break;
        }
      }
      if(works){
        forn(i, n){
          cout << ans[i];
        }
      }


      cout << endl;
    }
}