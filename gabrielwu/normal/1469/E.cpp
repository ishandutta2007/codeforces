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

//Custom hash function for anti-hacking on unordered_map and unordered_set
//Use: unordered_map<whatever, whatever, custom_hash> safe_map;
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       // http://xorshift.di.unimi.it/splitmix64.c
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //use uniform_int_distribution<int>(0, i)(rng) if you want [0, i].
const ll P1 = MOD;
const ll P2 = 100663319LL;
const int p1 = uniform_int_distribution<int>(7, 2000)(rng);
const int p2 = uniform_int_distribution<int>(7, 2000)(rng);
const int MAXN = 1e6+5;
ll res1[MAXN];
ll res2[MAXN];
int main(){
    fast_io();
    res1[0] = 1;
    res2[0] = 1;
    for(int i=1; i<MAXN; i++){
      res1[i] = (res1[i-1]*p1)%P1;
      res2[i] = (res2[i-1]*p2)%P2;
    }

    int t;
    cin >> t;
    forn(ti, t){
      int n, k;
      cin >> n >> k;
      vb v(n);
      forn(i, n){
        char c;
        cin >> c;
        if(c=='1') v[i] = true;
      }

      ll c1 = 0;
      ll c2 = 0;
      unordered_set<ll, custom_hash> s;
      forn(i, n){
        c1 = ((c1*p1)%P1 + (!v[i] ? 1 : 0) - (i>=k && !v[i-k] ? res1[k] : 0) + P1)%P1;
        c2 = ((c2*p2)%P2 + (!v[i] ? 1 : 0) - (i>=k && !v[i-k] ? res2[k] : 0) + P2)%P2;
        if(i >= k-1){
          s.insert(c1+c2);
        }
      }
      bool works = false;
      ll ans;
      forn(x, n+1){
        ll c1 = 0;
        ll c2 = 0;
        forn(i, 20){
          if((x>>i)%2 == 1){c1 = (c1+res1[i])%P1; c2 = (c2+res2[i])%P2;}
        }
        if(s.find(c1+c2) == s.end()){
          works = true;
          ans = x;
          break;
        }
      }
      if(works && ans < (1LL << min(k, 20))){
        cout << "YES\n";
        for(int i=k-1; i>=0; i--){
          if(i >= 20 || (ans>>i)%2==0){
            cout << '0';
          }else{
            cout << '1';
          }
        }
        cout << "\n";
      }else{
        cout << "NO\n";
      }
    }
}