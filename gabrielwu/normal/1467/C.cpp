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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vl a(n1), b(n2), c(n3);
    ll A = 0, B = 0, C = 0;
    ll mina = MOD, minb = MOD, minc = MOD;
    forn(i, n1){
      cin >> a[i];
      A += a[i];
      mina = min(mina, a[i]);
    }forn(i, n2){
      cin >> b[i];
      B += b[i];
      minb = min(minb, b[i]);
    }forn(i, n3){
      cin >> c[i];
      C += c[i];
      minc = min(minc, c[i]);
    }
    ll best = 0;
    vl poss{A-B-C, A-B+C, A-C+B, A+B-2*minb+C-2*minc,
        B-A-C, B-A+C, B-C+A, B+A-2*mina+C-2*minc,
        C-B-A, C-B+A, C-A+B, C+B-2*minb+A-2*mina};
    for(ll x: poss){
      best = max(best, x);
    }
    cout << best << "\n";
}