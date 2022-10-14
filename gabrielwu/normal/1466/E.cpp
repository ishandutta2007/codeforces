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
    vl res(1000);
    res[0] = 1;
    forn(i, 999){
      res[i+1] = (res[i]*2)%MOD;
    }
    forn(ti, t){
      int n;
      cin >> n;
      vl v(n);
      vl bits(60);
      ll sum = 0;
      forn(i, n){
        cin >> v[i];
        ll x = v[i];
        forn(j, 60){
          bits[j] += x%2;
          x >>= 1;
        }
        sum = (sum+v[i])%MOD;
      }

      ll ans = 0;
      forn(j, n){
        ll x = v[j];
        ll brack = 0;
        forn(i, 60){
          if(x%2==1){
            brack = (brack + bits[i]*res[i])%MOD;
          }
          x >>= 1;
        }
        ans = (ans + brack*((((v[j]%MOD)*n)%MOD + sum)%MOD))%MOD;
        ans = (((ans - (brack*brack)%MOD)%MOD)+MOD)%MOD;
      }

      cout << ans << "\n";
    }
}