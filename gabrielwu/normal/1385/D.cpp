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

vector<vi> pref;
vi v;
int n, k;

int recurse(int l, int r, int c){
  if(c==k){
    return v[l]==c ? 0 : 1;
  }
  int mid = (r+l)/2;
  return min(mid-l+1-pref[mid][c]+(l > 0 ? pref[l-1][c]:0) + recurse(mid+1, r, c+1),
            r-mid-pref[r][c]+pref[mid][c] + recurse(l, mid, c+1));
}

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      cin >> n;
      v = vi(n);
      forn(i, n){
        char c;
        cin >> c;
        v[i] = c-'a';
      }

      pref = vector<vi>(n, vi(26));
      forn(i, n){
        forn(j, 26){
          pref[i][j] = (i>0 ? pref[i-1][j] : 0);
        }
        pref[i][v[i]]++;
      }
      k=0;
      ll x = 1;
      while(x < n){
        x <<= 1;
        k ++;
      }
      cout << recurse(0, n-1, 0) << endl;
    }



}