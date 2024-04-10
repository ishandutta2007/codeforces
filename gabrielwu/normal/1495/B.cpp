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
    }
    vi peaks;
    forn(i, n){
      if((i==0 || v[i] > v[i-1]) && (i==n-1 || v[i] > v[i+1])){
        peaks.pb(i);
      }
      if((i==0 || v[i] < v[i-1]) && (i==n-1 || v[i] < v[i+1])){
        peaks.pb(i);
      }
    }
    // cout << peaks << "\n";
    int start = 2;
    if(v[0] < v[1]){
      start = 1;
    }
    bool works = false;
    int high = 0;
    for(int i=start; i<peaks.size()-1; i+=2){
      int a=peaks[i] - peaks[i-1];
      int b=peaks[i+1] - peaks[i];
      if(a == b){
        if(a > high){
          works = true;
        }else if(a==high){
          works = false;
        }
      }else{
        if(max(a,b) >= high){
          works = false;
        }
      }
      high = max(max(high, a),b);
    }
    int longtail = 0;
    if(v[1] < v[0]){
      longtail = max(longtail, peaks[1] - peaks[0]);
    }
    if(v[n-2] < v[n-1]){
      longtail = max(longtail, peaks[peaks.size()-1] - peaks[peaks.size()-2]);
    }
    if(works && high%2==0 && high > longtail){
      cout << "1\n";
    }else{
      cout << "0\n";
    }
    // if(v[0] == 39390){
    //   cout << high << " " << longtail << "\n";
    //   cout << peaks << "\n";
    // }
}