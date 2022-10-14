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
    vl a(6);
    forn(i, 6){
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int n;
    cin >> n;
    vl b(n);
    forn(i, n){
      cin >> b[i];
    }
    //vector<pair<ll, pii> > pq;
    //ll mins = 2*MOD;
    //ll maxs = -1;
    set<pair<ll, pii> > used;
    forn(i, n){
      used.insert(mp(b[i]-a[5], mp(i, 5)));
      //maxs = max(maxs, b[i]-a[5]);
    }
    //sort(pq.begin(), pq.end());
    ll ans = ((--used.end())->f)-(used.begin()->f);
    //  cout << (used.end())->f << "\n";
    forn(i, n*6){
      auto it = used.begin();
      auto p = it->s;
      if(p.s > 0){
        used.erase(it);
        used.insert(mp(b[p.f]-a[p.s-1], mp(p.f, p.s-1)));
        ans = min(ans, ((--used.end())->f)-(used.begin()->f));
      }else{
        break;
      }
    }

    cout << ans << "\n";

}