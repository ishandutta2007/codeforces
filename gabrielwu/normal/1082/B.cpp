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
    int n;
    cin >> n;
    vb v(n);
    forn(i, n){
      char c;
      cin >> c;
      if(c=='G'){
        v[i] = true;
      }
    }
    vi x(n);
    int cnt = 0;
    int prev = 0;
    forn(i, n){
      if(v[i]){
        prev += 1;
      }else{
        for(int j = i-prev; j<i; j++){
          x[j] = prev;
        }
        if(prev > 0) cnt++;
        prev = 0;
      }
    }
    for(int j = n-prev; j<n; j++){
      x[j] = prev;
    }
    if(prev > 0) cnt++;
    if(cnt == 0){
      cout << "0\n";
    }else if(cnt == 1){
      int best = 0;
      forn(i, n){
        best = max(best, x[i]);
      }
      cout << best << "\n";
    }else if(cnt == 2){
      int best = 0;
      forn(i, n){
        best = max(best, x[i]+1);
        if(!v[i] && i > 0 && i < n-1 && v[i-1] && v[i+1]){
          best = max(best, x[i-1] + x[i+1]);
        }
      }
      cout << best << "\n";
    }else{
      int best = 0;
      forn(i, n){
        best = max(best, x[i]+1);
        if(!v[i] && i > 0 && i < n-1 && v[i-1] && v[i+1]){
          best = max(best, x[i-1] + x[i+1]+1);
        }
      }
      cout << best << "\n";
    }
}