#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
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
   cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io() {
   cin.tie(0)->sync_with_stdio(0);
}
void file_io(string taskname) {
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
    	int n;
    	cin >> n;
    	vi h(n);
    	forn(i, n){
    		cin >> h[i];
    	}
    	sort(h.begin(), h.end());

      int best = MOD;
      forn(i, n-1){
         best = min(best, h[i+1]-h[i]);
      }

    	vi v;
    	for(int i=0; i<n-1; i++){
    		if(h[i+1] - h[i] > best){
    			continue;
    		}
    		v.pb(h[i]);
    		for(int j=i+2; j<n; j++){
            v.pb(h[j]);
         }
         for(int j=0; j<i; j++){
            v.pb(h[j]);
         }
    		v.pb(h[i+1]);
    		break;
    	}
      // cout << v << "\n";
    	forn(i, n){
    		cout << v[i] << " ";
    	}cout << "\n";
    }
}