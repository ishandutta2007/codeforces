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
      int n, k;
      cin >> n >> k;
      vi v(n);
      forn(i, n){
        char x;
        cin >> x;
        if(x=='1'){
          v[i] = 1;
        }else if(x=='0'){
          v[i] = 0;
        }else{
          v[i] = -1;
        }
      }
      bool works = true;
      for(int i=0; i+k<n; i++){
        if(v[i] != -1){
          if(v[i+k] != -1){
            if(v[i] != v[i+k]){
              works = false;
              break;
            }
          }else{
            v[i+k] = v[i];
          }
        }else{
          if(v[i+k] != -1){
            v[i] = v[i+k];
          }
        }
      }
      for(int i=n-1-k; i>=0; i--){
        if(v[i] != -1){
          if(v[i+k] != -1){
            if(v[i] != v[i+k]){
              works = false;
              break;
            }
          }else{
            v[i+k] = v[i];
          }
        }else{
          if(v[i+k] != -1){
            v[i] = v[i+k];
          }
        }
      }

      if(!works){
        cout << "NO\n";
      }else{
        int one = 0;
        int ques = 0;
        forn(i, k){
          if(v[i] == 1) one++;
          if(v[i] == -1)ques++;

        }
        if(one <= k/2 && one + ques >= k/2){
          cout << "YES\n";
        }else{
          cout << "NO\n";
        }
      }
    }
}