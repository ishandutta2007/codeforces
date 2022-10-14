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

vl primefac(ll x){
  vl v;
  ll c = 2;
  while(x>1 && c*c <= x){
    if(x%c==0){
      v.pb(c);
      x/=c;
    }else{
      c++;
    }
  }
  if(x>1) v.pb(x);
  return v;
}

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      ll p, q;
      cin >> p >> q;
      if(p%q != 0){
        cout << p << "\n";
      }else{
        vl v = primefac(q);
        
        vl w;
        ll x = p/q;
        for(ll fac: v){
          while(x%fac==0){
            x/=fac;
            w.pb(fac);
          }
        }
        w.pb(x);
        /*c = 2;
        while(x>1 && c*c <= x){
          if(x%c==0){
            w.pb(c);
            x/=c;
          }else{
            c++;
          }
        }
        if(x>1) w.pb(x);*/
        //cout << v << " " << w << endl;
        ll best = 1;
        forn(i, v.size()){
          if(i==0 || v[i] != v[i-1]){
            ll div = q/v[i];
            for(ll fac: w){
              if(fac != v[i]){
                div *= fac;
              }
            }
            best = max(best, div);
          }
        }
        cout << best << "\n";
      }
    }
}