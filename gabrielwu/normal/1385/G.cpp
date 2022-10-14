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
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vi cnt(n);
      vector<vpi> place(n);
      forn(i, 2){
        forn(j, n){
          int x;
          cin >> x;
          x--;
          cnt[x]++;
          place[x].pb(mp(j, i));
        }
      }

      bool works = true;
      forn(i, n){
        if(cnt[i] != 2){
          works = false;
        }
      }
      if(!works){
        cout << -1 << "\n";
        continue;
      }

      vector<vpi> other(n, vpi(2));
      forn(i, n){
        other[place[i][0].f][place[i][0].s] = place[i][1];
        other[place[i][1].f][place[i][1].s] = place[i][0];
      }

      vb cubierto(n);
      int tot = 0;
      vi ans;

      forn(i, n){
        if(!cubierto[i]){
          int length = 0;
          int cambios = 0;
          vi a, b;
          int curr = 0;

          pii x = mp(i, 0);
          while(!cubierto[x.f]){
            cubierto[x.f] = true;
            length += 1;

            pii y = other[x.f][x.s];
            if(curr^x.s^y.s^1){
              cambios++;
              b.pb(y.f);
            }else{
              a.pb(y.f);
            }
            if(x.s==y.s){
              curr ^= 1;
            }
            x = y;
            x.s ^= 1;
          }
          if(cambios < length-cambios){
            tot += cambios;
            for(int change: b){
              ans.pb(change+1);
            }
          }else{
            tot += length-cambios;
            for(int change: a){
              ans.pb(change+1);
            }
          }
          //tot += min(cambios, length-cambios);
          //cout << "cambios " << cambios << " len " << length << endl;
        }
      }
      cout << tot << "\n";
      cout << ans << "\n";
    }
}