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

int main() {
  io;
  // freopen("a", "r", stdin);
  // freopen("a", "w", stdout);
  // cin >> Q;
  // f0r(q, Q) {
    cin >> n >> k;
    f0r(i, n) cin >> a[i];
    f1r(i, 1, n) dif[i-1] = a[i] - a[i-1];
    ms(inc, 0);
    f0r(i, n-1) difs.pb(mp(dif[i], i));
    sort(difs.begin(), difs.end());
    f0r(i, n-k) {
      inc[difs[i].s] = 1;
    }
    inc[n] = 1;
    int lpt = 0;
    ll ans = 0;
    f0r(i, n) {
      if (!inc[i]) {
        ans += a[i] - a[lpt];
        lpt = i + 1;
      }
    }
    cout << ans << endl;
}