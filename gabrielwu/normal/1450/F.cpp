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
      vi v(n);
      vi cnt(n);
      forn(i, n){
        cin >> v[i];
        v[i]--;
        cnt[v[i]]++;
      }
      bool works = true;
      forn(i, n){
        if(cnt[i] > (n+1)/2){
          works = false;
        }
      }
      if(!works){
        cout << "-1\n";
        continue;
      }
      vi nc(n);
      int parts = 1;  //cuts
      forn(i, n-1){
        if(v[i] == v[i+1]){
          nc[v[i]]+=2;
          parts++;
        }
      }
      nc[v[0]]++;
      nc[v[n-1]]++;
      //cout << nc << "\n";
      bool good = true;
      int worst = 0;
      forn(i, n){
        if(nc[i] - parts > 1){
          good = false;
          worst = max(worst, nc[i]);
        }
      }
      //cout << "wo " << worst << "goo " << good << "\n";
      if(good){
        cout << parts - 1 << "\n";
      }else{
        cout << worst - 2 << "\n";
      }
    }
}