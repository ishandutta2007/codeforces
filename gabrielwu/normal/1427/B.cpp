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
      int n, k;
      cin >> n >> k;
      vi runs;
      int curr = 0;
      bool prev = false;
      int score = 0;
      forn(i, n){
        char c;
        cin >> c;
        if(c=='W'){
          if(prev == false){
            runs.pb(curr);
            curr = 0;
            score += 1;
          }else{
            score += 2;
          }
          prev = true;
        }else{
          curr++;
          prev = false;
        }
      }
      runs.pb(curr);
      if(runs.size() == 1){
        cout << min(2*n-1, max(0, 2*k-1)) << "\n";
      }else{

        vi r;
        for(int i=1; i<runs.size()-1; i++){
          if(runs[i] > 0) r.pb(runs[i]);
        }
        sort(r.begin(), r.end());
        for(int x: r){
          if(k >= x){
            score += 2*x+1;
            k -= x;
          }else{
            score += 2*k;
            k = 0;
            break;
          }
        }
        score += min(2*k, 2*(runs[0] + runs[runs.size()-1]));
        cout << score << "\n";
      }
    }
}