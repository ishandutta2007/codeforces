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
    ll n, d, m;
    cin >> n >> d >> m;
    vl v(n);
    forn(i, n){
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    if(v[n-1] <= m){
      ll sum = 0;
      forn(i, n){
        sum += v[i];
      }
      cout << sum << endl;
      return 0;
    }
    ll sum = 0;
    int k;
    for(k=0; k<n; k++){
      if(v[k] > m){
        break;
      }
    }
    forn(i, k){
      sum += v[i];
    }
    ll best = sum;
    int curr = k;
    //cout << v << endl;
    //cout << k << " k \n";
    for(int x=n-1; x>=k; x--){
      int remove = curr-(n-(n-1-x)*(d+1)-1);
      if(remove > curr){
        break;
      }
      forn(i, remove){
        sum -= v[k-curr];
        curr--;
      }
      sum += v[x];
      //cout << curr << " " << sum << " " << best << endl;
      best = max(best, sum);
    }
    cout << best << endl;
    /*

    ll tot = 0;
    int left = 0;
    forn(i, n){
      if(left==0){
        tot += v[i];
        if(v[i] > m){
          left = d;
        }
      }else{
        left--;
      }
    }
    cout << tot << endl;*/
}