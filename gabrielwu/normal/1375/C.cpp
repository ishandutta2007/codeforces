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
      vi v(n);
      forn(i, n){
        cin >> v[i];
      }
      /*
      vi prefmin(n), postmax(n);
      prefmin[0] = v[0];
      postmax[n-1] = v[n-1];
      forn(i, n-1){
        prefmin[i+1] = min(prefmin[i], v[i+1]);
      }
      for(int i=n-1; i>=1; i--){
        postmax[i-1] = max(postmax[i], v[i-1]);
      }

      bool works = true;
      forn(i, n-1){
        if(prefmin[i] > postmax[i+1]){
          works = false;
        }
      }
      */
      if (v[n-1] > v[0]){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
      /*
      int lowest = 0;
      bool did = false;
      bool good = true;
      int prev = 0;
      forn(i, n){
        if(v[i] > prev){
          if(!did && v[i] > lowest){
            lowest = v[i];
            did = true;
          }
        }else{
          if(!did){
            good = false;
          }
          did = false;
        }
        prev = v[i];
        //cout << prev << " " << did << " " << lowest << " " << good << "\n";
      }

      if(!did){
        good = false;
      }
      if (good){
        cout << "YES" << endl;;
      }else{
        cout << "NO" << endl;
      }
      */
    }

}