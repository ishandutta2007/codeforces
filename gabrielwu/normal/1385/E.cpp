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

vi L;
vector<vi> out;
vb perm, temp;

bool visit(int v){
  //cout << "visit " << v << endl;
  if(perm[v]){
    return true;
  }
  if(temp[v]){
    return false;
  }

  temp[v] = true;

  for(int u: out[v]){
    bool x = visit(u);
    if(!x){
      return false;
    }
  }
  temp[v] = false;
  perm[v] = true;
  L.pb(v);
  return true;
}

int main(){
    fast_io();

    int t;
    cin >> t;
    forn(ti, t){
      int n, m;
      cin >> n >> m;
      perm = vb(n);
      temp = vb(n);
      out = vector<vi>(n, vi());
      L = vi();
      vpi ans;
      vpi und;

      forn(i, m){
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        y--;
        if(t==1){
          out[x].pb(y);
          ans.pb(mp(x+1, y+1));
        }else{
          und.pb(mp(x, y));
        }
      }
      bool works = true;
      forn(i, n){
        if(!perm[i]){
          bool x = visit(i);
          if(!x){
            works = false;
            break;
          }
        }
      }
      if(works){
        vi place(n);
        forn(i, n){
          place[L[n-1-i]] = i;
        }
        for(pii e: und){
          if(place[e.f] < place[e.s]){
            ans.pb(mp(e.f+1, e.s+1));
          }else{
            ans.pb(mp(e.s+1, e.f+1));
          }
        }
        cout << "YES\n";
        for(pii e:ans){
          cout << e.f << " " << e.s << "\n";
        }
      }else{
        cout << "NO\n";
      }

    }
}