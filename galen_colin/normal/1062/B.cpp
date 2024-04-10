#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;
#define f0r(a, b) for (int a = 0; a < b; a++)
#define f1r(a, b, c) for (int a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> ll max(A x, B y) {
  return x > y ? x : y;
}
template<typename A, typename B> ll min(A x, B y) {
  return x < y ? x : y;
}
 
ll i, j;
const ll mod = 1e9 + 7;
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

ll n, q, Q, T, m, k, r, y, z, g;
ll a[100001];
bool prime[1000001]; 

void sieve(int n) { 
  ms(prime, 1);
  for (int p=2; p*p<=n; p++) { 
    if (prime[p] == true) { 
      for (int i=p*p; i<=n; i += p) 
        prime[i] = false; 
    } 
  } 
} 

vi facs(1000000);
int main() {
  // freopen("case", "w", stdout);

  cin >> n;
  sieve(n);
  ll res = 1;
  ll pt = 0;
  f1r(i, 2, n+1) {
    while (prime[i] && n % i == 0) {
      if (!facs[pt]) res *= i;
      facs[pt]++;
      n /= i;
    }
    if (facs[pt]) pt++;
  }
  ll ops = 0;
  ll m = 0;
  f0r(i, pt) m = max(m, facs[i]);
  ll v = 1, pow = 0;
  while (v < m) {
    pow++;
    v *= 2;
  }
  bool f = 0;
  f0r(i, pt) if (facs[i] < v) f = 1;
  cout << res << " " << pow + f << endl;
}