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

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main(){
    fast_io();
    ll n, m;
    ll k;
    cin >> n >> m >> k;
    vl a(n), b(m);
    forn(i, n){
      cin >> a[i];
    }
    forn(j, m){
      cin >> b[j];
    }

    if(n < m){
      swap(n, m);
      swap(a, b);
    }
    ll g = gcd(n, m);
    vl occ(2*(n+m)+5, -1);
    forn(i, n){
      occ[a[i]] = i;
    }
    vl skips(n);
    vl ind(n);
    ll p = 0;
    forn(i, n/g){
      ind[p] = i;
      p += m;
      p %= n;
    }
    ll tot = n*m/g;
    forn(i, m){
      if(occ[b[i]] != -1){
        if((occ[b[i]] - i)%g != 0){
          continue;
        }
        int diff = (occ[b[i]] - i + n)%n;
        skips[ind[diff]]++;
        tot--;
      }
    }
    ll cycles = (k-1)/tot;
    k -= cycles*tot;

    ll ans = (cycles*n/g)*m;
    ll sofar = 0;
    forn(i, n/g){
      if(sofar + m-skips[i] >= k){
        ll need = k-sofar;
        forn(j, m){
          if(b[j] != a[((ll)i*m+j)%n]){
            need--;
          }
          if(need==0){
            ans += (ll)i*m+j+1;
            break;
          }
        }
        break;
      }
      sofar += m-skips[i];
    }
    // cout << tot << " " << cycles << "\n";
    // cout << occ << "\n";
    // cout << skips << "\n";

    cout << ans << "\n";
}