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

ll val(ll len, ll pcs){
  ll tot = 0;
  ll base = len/pcs;
  tot += (base+1)*(base+1)*(len-pcs*base);
  tot += base*base*(pcs-(len-pcs*base));
  return tot;
}

int main(){
    fast_io();
    int n, k;
    cin >> n >> k;
    vl v(n);
    forn(i, n){
      cin >> v[i];
    }
    vi used(n, 1);
    priority_queue<pll> best;
    forn(i, n){
      best.push(mp(val(v[i], 1)-val(v[i], 2), i));
    }
    ll tot = 0;
    forn(i, n){
      tot += v[i]*v[i];
    }
    forn(i, k-n){
      pll next = best.top();best.pop();
      //cout<< next << "\n";
      tot -= next.f;
      used[next.s]++;
      best.push(mp(val(v[next.s], used[next.s])-val(v[next.s], used[next.s]+1), next.s));
    }
    cout << tot << "\n";
    /*
    lld lo = 1;
    lld hi = 1e15; //largest piece allowed
    forn(time, 200){
      lld mid = (lo+hi)/2;
      int used = 0;
      forn(i, n){
        used += (int) (((lld) 100000000 * v[i] + i)/mid);
      }
      if(used > k-n){
        lo = mid;
      }else{
        hi = mid;
      }
    }
    //cout << lo << " lo\n";
    ll tot = 0;
    forn(i, n){
      int x = (int) (((lld) 100000000 * v[i] + i)/hi) + 1;
      int base = v[i]/x;
      forn(j, v[i]-x*base){
        tot += (base+1)*(base+1);
      }
      forn(j, x-(v[i]-x*base)){
        tot += base*base;
      }
    }
    cout << tot << "\n";
    */
}