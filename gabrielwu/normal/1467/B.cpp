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

int count(vi& v){
  int h=0;
  for(int i=1; i<v.size()-1; i++){
    if((v[i] > v[i-1] && v[i] > v[i+1]) || (v[i] < v[i-1] && v[i] < v[i+1])){
      h++;
    }
  }
  return h;
}

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vi v(n);
      forn(i, n){
        cin >> v[i];
      }
      if(n < 3){
        cout << 0 << "\n";
        continue;
      }
      int h = count(v);
      int best = 0;
      forn(i, n){
        vi bef, now;
        for(int j=i-2; j<=i+2; j++){
          if(j >= 0 && j < n){
            bef.pb(v[j]);
            if(j != i){
              now.pb(v[j]);
            }else if(i>0){
              now.pb(v[i-1]);
            }
          }
        }
        best = max(best, count(bef) - count(now));
      }
      forn(i, n){
        vi bef, now;
        for(int j=i-2; j<=i+2; j++){
          if(j >= 0 && j < n){
            bef.pb(v[j]);
            if(j != i){
              now.pb(v[j]);
            }else if(i < n-1){
              now.pb(v[i+1]);
            }
          }
        }
        best = max(best, count(bef) - count(now));
      }
      cout << h - best << "\n";
    }
}