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
      int x = 0;
      forn(i, n){
        char c;
        cin >> c;
        if(c=='0'){
          v[i] = 1;
          x++;
        }
      }
      if(x%2 == 1){
        cout << "NO\n";
        continue;
      }
      vi a(n), b(n);
      int c = 0, d=0;
      forn(i, n){
        if(v[i]){
          if(c%2){
            a[i] = -1;
            b[i] = 1;
          }else{
            a[i] = 1;
            b[i] = -1;
          }
          c++;
        }else{
          if(d < (n-x)/2){
            a[i] = 1;
            b[i] = 1;
          }else{
            a[i] = -1;
            b[i] = -1;
          }
          d++;
        }
      }
      bool works = true;
      int curr = 0;
      forn(i, n){
        curr += a[i];
        if(curr < 0) works = false;
      }
      curr = 0;
      forn(i, n){
        curr += b[i];
        if(curr < 0) works = false;
      }
      // cout << a << "\n" << b << "\n";
      if(works){
        cout << "YES\n";
        forn(i, n){
          if(a[i] > 0) cout << "(";
          else cout << ")";
        }cout << "\n";
        forn(i, n){
          if(b[i] > 0) cout << "(";
          else cout << ")";
        }cout << "\n";
      }else{
        cout << "NO\n";
      }
    }
}