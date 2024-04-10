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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
 
ll i, j;
const ll mod = 1e9 + 7;
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

ll n, q, Q, T, m, k, r, y, z, g;
ll a[101], b[101];

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  sort(a, a+n);
  reverse(a, a+n);
  b[0] = a[0];
  f1r(i, 1, n) {
    if (i % 2) b[i/2 + 1] = a[i];
    else b[n - i/2] = a[i];
  }
  f0r(i, n) cout << b[i] << " ";
}