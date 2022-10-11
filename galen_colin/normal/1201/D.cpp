/* avg time test */
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
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
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
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}
 
// bool prime[1000001]; 
// void sieve(int n) { 
//   ms(prime, 1);
//   for (int p=2; p*p<=n; p++) { 
//     if (prime[p] == true) { 
//       for (int i=p*p; i<=n; i += p) 
//         prime[i] = false; 
//     } 
//   } 
// } 
 
// ll mpow(ll base, ll exp) {
//   ll res = 1;
//   while (exp) {
//     if (exp % 2 == 1){
//         res = (res * base) % mod;
//     }
//     exp >>= 1;
//     base = (base * base) % mod;
//   }
//   return res;
// }
 
ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;
pll a[200001];
vl safel;
vl tr[200001];
const ll dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const ll dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
map<ll, ll> best;
 
void put(ll x, ll y) {
  if (best.find(x) == best.end()) best[x] = y;
  else best[x] = min(best[x], y);
}
 
ll bins(ll loc) {
  ll l = 0, r = q - 1;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (loc >= safel[m]) l = m + 1;
    else r = m - 1;
  }
  return l;
}
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> m >> k >> q;
  ll h = 0;
  f0r(i, k) {cin >> a[i].f >> a[i].s; a[i].f--; a[i].s--;}
  f0r(i, k) h = max(h, a[i].f);
  sort(a, a+k);
  f0r(i, k) tr[a[i].f].pb(a[i].s);
  f0r(i, n) sort(all(tr[i]));
  f0r(i, q) {
    cin >> x; 
    x--;
    safel.pb(x);
  }
  sort(all(safel));
 
  queue<pair<ll, ll> > qu; //loc, cost
  qu.push(mp(0, h));
  ll ans = 1e14;
  f0r(i, h+1) {
    best.clear();
    while (!qu.empty()) {
      pair<ll, ll> x = qu.front();
      qu.pop();
      ll loc = x.f;
      if (tr[i].size() == 0) {
        if (i == 0) {
          put(safel[0], x.s + safel[0]);
        } else put(loc, x.s);
      } else {
        //do left
        ll l = bins(tr[i][0]);
        // cout << "BINS " << i << " " << tr[i][0] << " " << l << endl;
        ll m = l - 1;
        ll dist = tr[i].back() - tr[i][0];
        ll cost = x.s + dist + abs(loc - tr[i].back());
        if (m > -1) put(safel[m], 
        cost + (i != h ? abs(tr[i][0] - safel[m]) : 0));
        if (l < q) put(safel[l], 
        cost + (i != h ? abs(tr[i][0] - safel[l]) : 0));
        //do right
        l = bins(tr[i].back());
        // cout << "BINS " << i << " " << tr[i][0] << " " << l << endl;
        m = l - 1;
        cost = x.s + dist + abs(loc - tr[i][0]);
        if (m > -1) put(safel[m], 
        cost + (i != h ? abs(tr[i].back() - safel[m]) : 0));
        if (l < q) put(safel[l], 
        cost + (i != h ? abs(tr[i].back() - safel[l]) : 0));
      }
    }
    for (pair<ll, ll> x: best) {
      qu.push(mp(x.f, x.s));
      // cout << i << " " << x.f << " " << x.s << endl;
    }
  }
  for (pair<ll, ll> x: best) {
      ans = min(ans, x.s);
      // cout << i << " " << x.f << " " << x.s << endl;
    }
  cout << ans << endl;
}