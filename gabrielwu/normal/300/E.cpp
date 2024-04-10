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

const int MAX_PRIME = 10000005;
bool prime[MAX_PRIME];
int sieve[MAX_PRIME];
void set_sieve(){
    int sz = MAX_PRIME;
    memset(sieve, 0, sz*sizeof(sieve[0]));
    memset(prime, 0, sz*sizeof(prime[0]));

    for(int i=2; i<sz; i++){
        if(!sieve[i]){
            prime[i] = true;
            for(int x=i; x<sz; x+=i){
                if(sieve[x] == 0){
                    sieve[x] = i;
                }
            }
        }else{
            prime[i] = false;
        }
    }
}

int main(){
    fast_io();
    set_sieve();
    vl primes;
    for(int i=2; i<MAX_PRIME; i++){
      if(prime[i]) primes.pb(i);
    }
    int p = primes.size();
    vl cnt(MAX_PRIME);
    ll k;
    cin >> k;
    vl place(MAX_PRIME);
    forn(i, k){
      ll x;
      cin >> x;
      place[x]++;
      /*
      forn(j, p){
        ll c = primes[j];
        while(c <= x){
          cnt[j] += x/c;
          c *= primes[j];
        }
      }*/
    }
    ll sum = 0;
    for(int i=MAX_PRIME-1; i>=2; i--){
      sum += place[i];
      ll x = i;
      while(x>1){
        ll pr = sieve[x];
        cnt[pr] += sum;
        x /= pr;
      }
    }
    //forn(i, 10){
      //cout << primes[i] << " " << cnt[i] << "\n";
    //}
    ll m = 1;
    forn(i, p){
      ll lo=1;
      ll hi=cnt[primes[i]]*primes[i];
      while(lo < hi){
        ll mid = (lo+hi)/2;
        ll c = primes[i];
        ll x = mid;
        ll calc = 0;
        while(c <= x){
          calc += x/c;
          c *= primes[i];
        }
        if(calc < cnt[primes[i]]){
          lo = mid+1;
        }else{
          hi = mid;
        }
      }
      m = max(lo, m);
    }
    cout << m << "\n";
}