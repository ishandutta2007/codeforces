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
    int n, M, k;
    cin >> n >> M >> k;
    vi c(n);
    forn(i, n){
      cin >> c[i];
      c[i]--;
    }

    vii adj(n);
    map<pii, vpi> m;
    forn(i,M){
      int a, b;
      cin >> a >> b;
      a--;b--;
      if(c[a]==c[b]){
        adj[a].pb(b);
        adj[b].pb(a);
      }else{
        m[mp(min(c[a], c[b]), max(c[a], c[b]))].pb(mp(a, b));
      }
    }
    int curr = 1;
    vi comp(n);
    vb works(k, true);
    forn(i, n){
      if(comp[i] == 0){
        comp[i] = curr;
        queue<int> q;
        q.push(i);
        while(q.size()){
          int u = q.front(); q.pop();
          for(int v: adj[u]){
            if(comp[v] != 0 && comp[v] == comp[u]){
              works[c[u]] = false;
              break;
            }
            if(comp[v] == 0){
              comp[v] = -comp[u];
              q.push(v);
            }
          }
        }
        curr++;
      }
    }
    ll good = 0;
    forn(i, k){
      if(works[i]) good++;
    }

    ll sub = 0;

    for(auto it=m.begin(); it!=m.end(); it++){
      int c1 = (*it).f.f;
      int c2 = (*it).f.s;
      if(!works[c1] || !works[c2]) continue;
      map<int, vector<pair<int, bool> > > p;
      set<int> used;
      for(auto e: (*it).s){
        bool flip =  ((ll) comp[e.s])*comp[e.f]>0;
        p[abs(comp[e.f])].pb(mp(abs(comp[e.s]), flip));
        p[abs(comp[e.s])].pb(mp(abs(comp[e.f]), flip));
        used.insert(abs(comp[e.f]));
        used.insert(abs(comp[e.s]));
      }
      //for(auto a: )
      map<int, int> nc;

      bool succ = true;
      for(int i: used){
        if(nc[i] == 0){
          nc[i] = 1;
          queue<int> q;
          q.push(i);
          while(q.size()){
            int u = q.front(); q.pop();
            for(auto v: p[u]){
              if(nc[v.f] != 0 && ((nc[v.f] == nc[u]) ^ v.s)){
                succ = false;
                break;
              }
              if(nc[v.f] == 0){
                if(v.s){
                  nc[v.f] = nc[u];
                }else{
                  nc[v.f] = -nc[u];
                }
                q.push(v.f);
              }
            }
          }
        }
      }
      if(!succ){
        sub++;
      }
    }
    //cout << comp << "\n";
    //cout << "G " << good << " " << sub << endl;

    cout << (good)*(good-1)/2 - sub << "\n";
}