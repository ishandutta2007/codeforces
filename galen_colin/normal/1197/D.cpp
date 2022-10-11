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
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
 
ll i, j;
const ll mod = 1e9 + 7;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
ll a[600001], dif[300001];
bool inc[300001];
vector<pii> difs;
 
ll f(ll l, ll r) {
  return k * ((r - l + m) / m);
}
 
int main() {
  io;
  // freopen("a", "r", stdin);
  // freopen("a", "w", stdout);
  // cin >> Q;
  // f0r(q, Q) {
    cin >> n >> m >> k;
    f0r(i, n) cin >> a[i];
    ll best = 0;
    f0r(j, m) {
      ll run = 0;
      int pt = j;
      f1r(i, j, n) {
        if (pt == i) {
          run += a[i];
        } else if ((((i - pt) % m == 0) && run < f(pt, i-1))) {
          pt = i;
          run = a[i];
        } else {
          run += a[i];
        }
        // cout << pt << " " << i << " " << run << endl;
        best = max(best, run - f(pt, i));
      }
    }
    
    cout << best << endl;
}