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
      int n, m;
      cin >> n >> m;
      vi a(n), b(n), c(m);
      vi occ(n, -1);
      vii need(n);
      forn(i, n){
        cin >> a[i];
        a[i]--;
      }
      forn(i, n){
        cin >> b[i];
        b[i]--;
        occ[b[i]] = i;
        if(a[i] != b[i]){
          need[b[i]].pb(i);
        }
      }
      forn(i, m){
        cin >> c[i];
        c[i]--;
      }
      if(occ[c[m-1]] == -1){
        cout << "NO\n";
        continue;
      }
      vi resp(m, -1);
      forn(i, m){
        if(need[c[i]].size()){
          resp[i] = need[c[i]].back();
          need[c[i]].pop_back();
        }else{
          resp[i] = occ[c[i]];
        }
      }
      bool works = true;
      forn(i, n){
        if(need[i].size()){
          works = false;
          break;
        }
      }
      if(!works){
        cout << "NO\n";
        continue;
      }
      int cubierto = resp[m-1];
      forn(i, m){
        if(resp[i] == -1){
          resp[i] = cubierto;
        }
      }
      cout << "YES\n";
      forn(i, m){
        cout << resp[i]+1 << " ";
      }
      cout << "\n";

    }
}