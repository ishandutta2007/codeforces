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
ll a[200001], c[200001];
int b[200001];
using type = pair<ll, pair<int, ll>>;
priority_queue<type, vector<type>, greater<type> > s;

int main() {
  io;
  cin >> n >> k;
  f0r(i, n) cin >> a[i];
  f0r(i, n) cin >> b[i];
  f0r(i, n) c[i] = a[i] / b[i];
  ll l = 0, r = 2000000000005;
  while (l <= r) {
    ll mid = (l + r) / 2;
    vector<type> v;
    f0r(i, n) v.pb(mp(c[i], mp(i, a[i])));
    s = priority_queue<type, vector<type>, greater<type> >(v.begin(), v.end());
    bool f = 1;
    f0r(i, k-1) {
      type p = s.top();
      s.pop();
      ll x = p.s.s + mid;
      s.push(mp(x / b[p.s.f], mp(p.s.f, x)));
      // cout << l << " " << r << " " << s.top() << endl;
      if (s.top().f <= i) {
        f = 0;
        break;
      }
    }
    if (f) r = mid - 1;
    else l = mid + 1;
  }
  cout << (l == 2000000000006 ? -1 : l) << endl;
}