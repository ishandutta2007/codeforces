#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A> ostream& operator<<(ostream& cout, vector<A> const& v){
  cout << "["; forn(i, v.size()){if(i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> ostream& operator<<(ostream& cout, pair<A, B> const& p){
  return cout << "(" << p.f << ", " << p.s << ")";
}

const int MAX = 1e5;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  vi sieve(MAX, 1);
  for(int i=2; i<MAX; i++){
    if(sieve[i] == 1){
      for(int j=i; j<MAX; j+=i){
        sieve[j] = i;
      }
    }
  }

  set<int> primes;
  for(int i=2; i<MAX; i++){
    if(sieve[i] == i) primes.insert(i);
  }
  int t;
  cin >> t;
  forn(ti, t){
    int d;
    cin >> d;
    ll x = *primes.lower_bound(d+1);
    ll y = *primes.lower_bound(x+d);
    cout << x*y << "\n";
  }

}