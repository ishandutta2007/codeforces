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
    int q;
    cin >> q;
    forn(qi, q){
      ll u, v;
      cin >> u >> v;
      if(u == v){
        cout << "YES\n";
        continue;
      }
      if(u > v){
        cout << "NO\n";
        continue;
      }
      int n = 30;
      vi x, y;
      forn(i, n){
        if(u%2==1)x.pb(n-i);
        if(v%2==1)y.pb(n-i);
        u >>= 1;
        v >>= 1;
      }
      sort(x.begin(), x.end());
      sort(y.begin(), y.end());
      // cout << x << " " << y << "\n";
      if(x.size() < y.size()){
        cout << "NO\n";
        continue;
      }
      // cout << x << " " << y << "\n";
      int kill = x.size() - y.size();
      int xi = 0, yi=0;
      while(x[xi] == y[yi]){
        xi++;
        yi++;
      }
      if(x[xi] < y[yi]){
        cout << "NO\n";
        continue;
      }
      xi += kill+1;
      yi++;
      bool works = true;
      while(xi < x.size()){
        works &= x[xi] >= y[yi];
        xi++;
        yi++;
      }
      if(works){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }
}