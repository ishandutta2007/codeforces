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
      int n, l, r, s;
      cin >> n >> l >> r >> s;
      int len = r-l+1;
      ll curr = len*(len+1)/2;
      int start = 1;
      while(curr+len <= s && start+len <= n){
        curr += len;
        start++;
      }
      vb used(n+1);
      // cout << "c " <<curr << " " <<s << "\n";
      if(curr == s){
        for(int i=start; i<start+len; i++){
          used[i] = true;
        }
      }else{
        bool works = true;
        if(start+len==n+1) works = false;
        if(curr > s) works = false;
        if(s-curr <= len-1){
          for(int i=start; i<start+len; i++){
            if(i-start<len-(s-curr)){
              used[i] = true;
            }else{
              used[i+1] = true;
            }
          }
        }else{
          works = false;
        }
        if(!works){
          cout << "-1\n";
          continue;
        }
      }
      // cout << used << "\n";
      vi ans(n);
      int i0=0;
      if(i0==l-1) i0=r;
      int i1=l-1;
      for(int i=1; i<=n; i++){
        if(used[i]){
          ans[i1++] = i;
        }else{
          ans[i0++] = i;
          if(i0==l-1) i0=r;
        }
      }
      forn(i, n){
        cout << ans[i] << " ";
      }cout << "\n";
    }
}