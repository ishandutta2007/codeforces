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

int n;
vi a;

ld check(ld x){
  ld lowest = 0, highest = 0;
  ld curr = 0;
  forn(i, n){
    curr += a[i]-x;
    lowest = min(lowest, curr);
    highest = max(highest, curr);
  }
  return abs(highest-lowest);
}

int main(){
    fast_io();

    cin >> n;
    a = vi(n);
    forn(i, n){
      cin >> a[i];
    }

    ld lo = -10000;
    ld hi = 10000;

    //while(abs(hi-lo) > 1e-11){
    forn(i, 100){
      //cout << setprecision(26) << lo << " "<< hi << endl;
      ld mid1 = (hi+lo*(ld)2)/(ld)3;
      ld mid2 = (hi*(ld)2+lo)/(ld)3;
      //cout << mid1 << " " << mid2 << endl;
      if(check(mid1) < check(mid2)){
        hi = mid2;
      }else{
        lo = mid1;
      }
    }

    cout << setprecision(16) << check(lo) << endl;
}