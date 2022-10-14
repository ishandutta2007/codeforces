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
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vector<vb> v(3, vb(2*n));
      forn(i, 3){
        forn(j, 2*n){
          char c; cin >> c;
          v[i][j] = (c=='1');
        }
      }

      int a=0, b=0, c=0;
      int used = 0;
      vb ans;
      while(used < 2){
        if(used == 0){
          if(v[0][a] == v[1][b]){
            ans.pb(v[0][a]);
            a++; b++;
            if(a == 2*n) used++;
            if(b == 2*n) used++;
          }else if(v[0][a] == v[2][c]){
            ans.pb(v[0][a]);
            a++; c++;
            if(a == 2*n) used++;
            if(c == 2*n) used++;
          }else if(v[1][b] == v[2][c]){
            ans.pb(v[1][b]);
            b++; c++;
            if(b == 2*n) used++;
            if(c == 2*n) used++;
          }
        }else{
          // cout << a << " "<< b << " "<< c << endl;
          if(a==2*n){
            if(b > c){
              ans.pb(v[1][b]);
              b++;
              if(b==2*n) used++;
            }else{
              ans.pb(v[2][c]);
              c++;
              if(c==2*n) used++;
            }
          }else if(b==2*n){
            if(a > c){
              ans.pb(v[0][a]);
              a++;
              if(a==2*n) used++;
            }else{
              ans.pb(v[2][c]);
              c++;
              if(c==2*n) used++;
            }
          }else if(c==2*n){
            if(b > a){
              ans.pb(v[1][b]);
              b++;
              if(b==2*n) used++;
            }else{
              ans.pb(v[0][a]);
              a++;
              if(a==2*n) used++;
            }
          }
        }
      }
      while(ans.size() < 3*n) ans.pb(0);

      forn(i, 3*n){
        cout << (ans[i] ? '1' : '0');
      }cout << "\n";
    }
}