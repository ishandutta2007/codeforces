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
    vpi runs;
    vi v(n);
    int curr = 0;
    forn(i, n){
      cin >> v[i];
      if(i>0 && v[i] == v[i-1]){
        curr++;
      }else{
        if(curr>0){
          runs.pb(mp(i-curr-1, curr+1));
        }
        curr = 0;
      }
    }
    if(curr>0){
      runs.pb(mp(n-curr-1, curr+1));
    }
    ll ans = n;
    if(runs.size() == 0){
      cout << n << "\n";
      return 0;
    }
    //cout << runs << "\n";
    ans -= runs[0].s-2;
    for(int i=1; i<runs.size(); i++){
      if(v[runs[i].f] != v[runs[i-1].f]){
        ans -= runs[i].s-2;
      }else{
        int cnt = 0;
        for(int j=runs[i-1].f+runs[i-1].s; j<runs[i].f; j++){
          if(v[j] == v[runs[i].f]) cnt++;
        }
        int len = runs[i].f - runs[i-1].f - runs[i-1].s;
        if(len%2==1 && len/2==cnt){
          ans -= runs[i].s-1;
        }else{
          ans -= runs[i].s-2;
        }
      }
    }
    cout << ans << "\n";
}