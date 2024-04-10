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
    int n, m;
    cin >> n >> m;
    vector<vb> v(n, vb(m));
    forn(i, n){
      forn(j, m){
        char c;
        cin >> c;
        if(c=='*'){
          v[i][j] = true;
        }
      }
    }
    int x=0,y=0;
    bool down = true;
    int ans = 0;
    ans += v[0][0];
    vii dist(n, vi(m, 99));
    for(int i=n-1; i>=0; i--){
      for(int j=m-1; j>=0; j--){
        if(v[i][j]) dist[i][j] = 0;
        else{
          int best = 99;
          if(i+1<n) best = min(best, dist[i+1][j]+1);
          if(j+1<m) best = min(best, dist[i][j+1]+1);
          dist[i][j] = best;
        }
      }
    }
    while(!(x==n-1&&y==m-1)){
      if(x == n-1){
        y++;
      }else if(y == m-1){
        x++;
      }else{
        if(dist[x][y+1] <= dist[x+1][y]){
          y++;
        }else{
          x++;
        }
      }
      if(v[x][y]) ans++;
    }
    cout << ans << "\n";
}