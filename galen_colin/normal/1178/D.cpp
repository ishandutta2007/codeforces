#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll i, j;
const ll mod = 998244353  ;

ll n, q, Q, T, m, k, r, x, y, z, g, a, b;

/* GeeksforGeeks */
bool prime[10000001];
void sieve(int n) { 
  ms(prime, 1);
  prime[0] = prime[1] = 0;
  
  for (int p=2; p*p<=n; p++) { 
    if (prime[p]) { 
      for (int i=p*p; i<=n; i += p) 
      prime[i] = 0; 
    } 
  } 
} 
vector<int> primes;

pii deg[1001];
bool can[1001][20001];
int par[1001][20001];
vector<pii> ans;

int main() {
  io;
  cin >> n;
  int nsq = n*n;
  sieve(20000);
  f0r(i, 20000) if (prime[i]) primes.pb(i);
  
  bool f = 0;
  f1r(i, 2*n, 3*n+1) {
    if (i % 2 == 0 && prime[i/2]) {
      int ans = i;
      f0r(j, n) {
        if (ans - 2*(n-j) == 0) deg[j].f = 2;
        else deg[j].f = 3;
        ans -= deg[j].f;
      }
    }
  }
  f0r(i, n) deg[i].s = i;
  
  f0r(i, n) {
    sort(deg+i, deg+n);
    reverse(deg+i, deg+n);
    f1r(j, i+1, n) {
      if (deg[i].f <= 0) break;
      if (deg[j].f <= 0) continue;
      deg[i].f--;
      deg[j].f--;
      ans.pb(mp(deg[i].s+1, deg[j].s+1));
    }
  }
  cout << ans.size() << endl;
  for (auto x: ans) cout << x.f << " " << x.s << endl;
}