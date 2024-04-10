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
const lld EPS = 1e-12;
lld dist(lld a, lld b){
  return sqrt(a*a + b*b);
}

lld closest(lld a, lld b, lld c, lld d){
  if(dist(a-c, b-d) < EPS) return 0;

  if(dist(a, b) < EPS || dist(c, d) < EPS) return 0;
  lld d1 = dist(a, b);
  lld d2 = dist(c, d);
  lld len = abs(a*d-b*c)/dist(a-c, b-d);
  lld ca = dist(a-c, b-d);
  if(d1*d1 <= d2*d2+ca*ca && d2*d2 <= d1*d1+ca*ca){
    return len;
  }else{
    return min(d1, d2);
  }
}
int main(){
    fast_io();
    int n;
    cin >> n;
    ll d1, d2;
    cin >> d1 >> d2;
    vpl coords;
    forn(i, n){
      ll a, b, c, d;
      cin >> a >> b >> c >> d;
      coords.pb(mp(a-c, b-d));
    }

    bool ready = true;
    vector<lld> dists;
    dists.pb(dist(coords[0].f, coords[0].s));
    forn(i, n-1){
      dists.pb(closest(coords[i].f, coords[i].s, coords[i+1].f, coords[i+1].s));
      dists.pb(dist(coords[i+1].f, coords[i+1].s));
    }
    int cnt = 0;

    forn(i, dists.size()){
      if(dists[i] <= d1){
        if(ready) cnt++;
        ready = false;
      }else if(dists[i] > d2){
        ready = true;
      }
    }
    cout << cnt << "\n";
}