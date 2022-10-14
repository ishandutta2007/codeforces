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

int n;
vi a;

ld check(ld x){
  ld lowest = 0, highest = 0;
  ld curr = 0;
  forn(i, n){
    curr += a[i]-x;
    lowest = min(lowest, curr);
    highest = max(highest, curr);
  }
  return abs(highest-lowest);
}

int main(){
    fast_io();

    string start, end;
    cin >> start >> end;
    int n = start.size();
    int k;
    cin >> k;
    int block;
    for(block = 1; block<=n; block++){
      if(n%block > 0){
        continue;
      }
      bool works = true;
      forn(i, n){
        if(start.at(i) != start.at(i%block)){
          works = false;
          break;
        }
      }
      if(works){
        break;
      }
    }
    bool works = true;
    int shift;
    for(shift = 0; shift < block; shift++){
      works = true;
      forn(i, n){
        if(end.at(i) != start.at((i+shift)%block)){
          works = false;
          break;
        }
      }
      if(works){
        break;
      }
    }
    //cout << block << " " << n << endl;
    if(!works){
      cout << 0 << endl;
      return 0;
    }

    vector<vl> dp(k+1, vl(2));
    if(shift==0){
      dp[0][0] = 0;
      dp[0][1] = 1;
    }else{
      dp[0][0] = 1;
      dp[0][1] = 0;
    }

    for(int i=1; i<=k; i++){
      dp[i][0] = (dp[i-1][0]*(n-1-n/block) + dp[i-1][1]*(n-n/block))%MOD;
      dp[i][1] = (dp[i-1][0]*(n/block) + dp[i-1][1]*(n/block-1))%MOD;
    }
    cout << dp[k][1] << endl;
}