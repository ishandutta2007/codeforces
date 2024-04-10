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
  cout << ""; for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << "";
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
    vl v(n), d(n), p(n);
    forn(i, n){
      cin >> v[i] >> d[i] >> p[i];
    }

    ll tot = 0;
    vl ans;
    vb in(n, true);
    //ll a = 0;
    forn(i, n){
      if(p[i] >= 0){
        //cout << "p" << i << " " << p[i] << endl;
        ll acc = 0;
        tot++;
        ans.pb(i+1);
        for(int j=i+1; j<n; j++){
          if(p[j] >= 0){
            p[j] -= v[i];
            p[j] -= acc;
            if(p[j] < 0){
              acc += d[j];
            }
            if(v[i] > 0){
              v[i]--;
            }
          }
        }
      }
    }

    /*
    vl plus(n);

    ll acc = 0;
    ll red = 0;
    int tot = 0;
    vi ans;
    forn(i, n){
      red += plus[i];
      acc += red;
      if(acc > p[i]){
        acc += d[i];
      }else{
        tot ++;
        ans.pb(i+1);
        acc += v[i];
        red--;
        if(i+v[i] < n){
          plus[i+v[i]]++;
        }
      }
    }
    */
    cout << tot << endl << ans << endl;

}