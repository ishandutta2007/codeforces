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
    vl v(n);
    ll sum = 0;
    forn(i, n){
      cin >> v[i];
      sum += v[i];
    }
    sort(v.begin(), v.end());
    if(n==1){
      cout << 0 << endl;
      return 0;
    }
    priority_queue<ll, vl, greater<ll> > pq;
    forn(i, n){
      pq.push(v[i]);
    }
    ll ans = 0;
    if(n%2==0){
      ll a = pq.top(); pq.pop();
      ll b = pq.top(); pq.pop();
      ans += a + b;
      pq.push(a+b);
    }
    while(pq.size() >= 3){
      ll a = pq.top(); pq.pop();
      ll b = pq.top(); pq.pop();
      ll c = pq.top(); pq.pop();
      ans += a + b + c;
      pq.push(a+b+c);
    }
    cout << ans << endl;
    /*
    int x = 0;
    ll p = 1;
    while(p*3 <= n){
      x++;
      p*=3;
    }
    ll ans = x*sum;
    int extra = n-p + (n-p+1)/2;
    forn(i, extra){
      ans += v[i];
    }
    cout << ans << endl;
    */
}