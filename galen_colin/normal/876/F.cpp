#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n; cin >> n;
  ll a[n];

  f0r(i, n) {
    cin >> a[i];
  }

  /*ll bans = 0;
  f0r(i, n) {
    ll o = a[i];
    ll m = a[i];
    for (ll j = i-1; j >= 0; j--) {
      o |= a[j];
      m = max(m, a[j]);
      if (o != m) {
        bans++;
      }
    }
    cout << i << " " << bans << endl;
  }

  cout << bans << endl;*/

  //< <a, b>, c >
  //a = maximum
  //b = or
  //c = length
  deque <pair<pll, ll> > dq;

  ll ans = 0;

  f0r(i, n) {
    if (i == 0) {
      dq.pb(mp(mp(a[i], a[i]), 1));
      continue;
    }

    dq.pb(mp(mp(0, 0), 1));

    deque <pair<pll, ll> > dq2;

    auto focus = dq.front();
    dq.pop_front();

    focus.f.s = max(focus.f.s, a[i]);
    focus.f.f |= a[i];

    bool f1 = (focus.f.f == focus.f.s);

    for(auto x: dq) {
      
      x.f.s = max(x.f.s, a[i]);
      x.f.f |= a[i];
      // cout << i << " " << focus << " " << x << endl;
      bool f2 = (x.f.f == x.f.s);
      if ((x.f.f != focus.f.f) || (f1 != f2)) {
        if (!f1) {
          ans += focus.s;
        }
        dq2.pb(focus);
        focus = x;
        f1 = f2;
      } else {
        focus.s += x.s;
        focus.f.f = max(focus.f.f, x.f.f);
      }
      //cout << focus << " " << x << endl;
    }

    if (!f1) {
      ans += focus.s;
    }
    dq2.pb(focus);

    dq = dq2;
    //cout << i << " " << ans << endl;
  }

  cout << ans << endl;
}