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
    int n;
    cin >> n;
    vi v(n);
    forn(i, n){
      cin >> v[i];
      v[i]--;
    }
    vii ans;
    bool front = true;
    if(n%2==1){
      front = false;
    }
    forn(i, n){
      vi x;
      if(front){
        forn(j, i){
          x.pb(1);
        }
        for(int j=i; j<n; j++){
          if(v[j] == i){
            x.pb(j+1-i);
            x.pb(n-j-1);
            break;
          }
        }
        front = false;

      }else{
        for(int j=0; j<n; j++){
          if(v[j] == i){
            x.pb(j);
            x.pb(n-i-j);
            break;
          }
        }
        forn(j, i){
          x.pb(1);
        }
        front = true;
      }
      ans.pb(x);
      int ind = 0;
      vii groups;
      vi curr;
      for(int p: x){
        forn(pi, p){
          curr.pb(v[ind]);
          ind++;
        }
        groups.pb(curr);
        curr = vi(0);
      }
      vi newv;
      for(int gi=groups.size()-1; gi>=0; gi--){
        for(int pi: groups[gi]){
          newv.pb(pi);
        }
      }
      v = newv;
      //cout << x << " x\n";
      //cout << v << " v\n";
    }

    vii newans;
    for(vi entry: ans){
      vi curr;
      for(int pi: entry){
        if(pi != 0){
          curr.pb(pi);
        }
      }
      if(curr.size() > 1){
        newans.pb(curr);
      }
    }

    cout << newans.size() << "\n";
    forn(i, newans.size()){
      cout << newans[i].size() << " ";
      for(int x: newans[i]){
        cout << x << " ";
      }cout << "\n";
    }
}