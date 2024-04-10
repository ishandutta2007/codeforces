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

struct dijkstra {
  int n;
  const ll inf = 4e18;
  vector<ll> dists; /* for a single run */
  vector<vector<pair<ll, int> > > edges; /* weight, to */
  
  void init(int s) {
    n = s;
    dists = vector<ll>(n);
    edges = vector<vector<pair<ll, int> > >(n);
  }

  void edge(int a, int b, ll wt) {
    edges[a].push_back(make_pair(wt, b));
    edges[b].push_back(make_pair(wt, a));
  }

  using ptype = pair<ll, int>;
  void run(int src) {
    fill(dists.begin(), dists.end(), inf);

    priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
    dists[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
      ptype foc = pq.top();
      pq.pop();
      dists[foc.s] = min(dists[foc.s], foc.f);
      for (ptype x: edges[foc.s]) {
        ll d = dists[foc.s] + x.f;
        if (d < dists[x.s]) {
          dists[x.s] = d;
          pq.push(make_pair(d, x.s));
        }
      }
    }
  }
};
 
ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;

string s1, s2;
vi edges[300001];
bool mark[300001];
vi mat, ind;

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("butter.out", "w", stdout);
  
  cin >> Q;
  f0r(q, Q) {
    mat.clear();
    ind.clear();
    cin >> n >> m;
    f0r(i, 3*n) mark[i] = 0;
    f0r(i, m) {
      int a, b; cin >> a >> b; a--; b--; 
      edges[a].pb(b); edges[b].pb(a);
      if (!mark[a] && !mark[b]) {
        mat.pb(i+1);
        mark[a] = mark[b] = 1;
      }
    }
 
    if (mat.size() >= n) {
      cout << "Matching" << endl;
      f0r(i, n) {
        if (i) cout << " ";
        cout << mat[i];
      }
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      int cnt = 0, i = 0;
      while (i < 3*n && cnt < n) {
        if (!mark[i]) {
          if (cnt) cout << " ";
          cout << i+1;
          ++cnt;
        }
        ++i;
      }
      cout << endl;
    }
  }
}