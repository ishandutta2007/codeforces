#include <bits/stdc++.h>
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

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
  const int MX = 1500;
    fast_io();
    int n, m;
    cin >> n >> m;
    vii a(n, vi(m)), b(n, vi(m));
    forn(i, n){
      forn(j, m){
        cin >> a[i][j];
      }
    }
    forn(i, n){
      forn(j, m){
        cin >> b[i][j];
      }
    }
    vi p(n, -1);
    vb used(n);
    bool works = true;
    forn(i, n){
      forn(j, n){
        if(!used[j]){
          bool good = true;
          forn(k, m){
            if(b[i] != a[j]){
              good = false;
              break;
            }
          }
          if(good){
            p[i] = j;
            used[j] = true;
            break;
          }
        }
      }
      if(p[i] == -1){
        works = false;
        break;
      }
    }
    if(!works){
      cout << "-1\n";
      return 0;
    }
    bitset<MX> need;
    forn(i, n-1){
      if(p[i+1] < p[i]){
        need.set(i);
      }
    }
    vector<bitset<MX>> in(m);
    vector<bitset<MX>> out(m);

    forn(i, m){
      forn(j, n-1){
        if(b[j+1][i] < b[j][i]){
          in[i].set(j);
        }
        if(b[j+1][i] != b[j][i]){
          out[i].set(j);
        }
      }
    }
    bitset<MX> curr;
    vb spent(m);
    vi ans;
    forn(mi, m){
      forn(i, m){
        if(!spent[i] && (curr|in[i]) == curr){
          spent[i] = true;
          ans.pb(i+1);
          curr |= out[i];
        }
      }
    }
    if((curr|need) == curr){
      cout << ans.size() << "\n";
      for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
      }cout << "\n";
    }else{
      cout << "-1\n";
    }
    // cout << p << "\n";
    // cout << in << "\n";
    // cout << out << "\n";
    // cout << need << "\n";
  }