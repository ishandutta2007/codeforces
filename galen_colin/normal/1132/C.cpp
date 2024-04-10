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
pii p[10001];
int a[3][10001], ps[2][10001];
int sum = 0, ans = 0;
 
int get(int l, int r, int x) {
  if (l > 0) return ps[x][r] - ps[x][l-1];
  else return ps[x][r];
}
 
int oget(pii p, int x) {
  return get(p.f, p.s, x);
}
 
int main() {
  io;
  cin >> n >> Q;
  ms(a, 0);
  f0r(i, Q) {
    cin >> p[i].f >> p[i].s;
    --p[i].f; --p[i].s;
    a[0][p[i].f]++;
    a[0][p[i].s + 1]--;
  }
  ps[0][0] = a[0][0];
  f1r(i, 1, n) {
    ps[0][i] = ps[0][i-1] + a[0][i];
  }
  f0r(i, n) {
    a[0][i] = (ps[0][i] == 1);
    a[1][i] = (ps[0][i] == 2);
    if (ps[0][i] > 0) sum++;
  }
  // if (p[0].f == 22) {
  //   // f1r(i, 50, Q) {
  //   //   cout << ++p[i].f << " " << ++p[i].s << endl;
  //   // }
  //   // f0r(i, n) cout << ps[0][i] << " ";
  //   // cout << endl;
  // }
  ps[0][0] = a[0][0];
  ps[1][0] = a[1][0];
  f0r(j, 2) {
    f1r(i, 1, n) {
      ps[j][i] = a[j][i] + ps[j][i-1];
    }
  }
  f0r(i, Q) {
    f1r(j, i+1, Q) {
      int dec = oget(p[i], 0) + oget(p[j], 0);
      pii x = p[i], y = p[j];
      if (x.f > y.f) {
        pii t = x;
        x = y;
        y = t;
      }
      // if (mp(x, y) == mp(mp(25, 28), mp(26, 29))) cout << dec << endl;
      // cout << x << " " << y << endl;
      if (x.f == y.f) {
        pii z = mp(x.f, min(x.s, y.s));
        dec += oget(z, 1);
        dec -= oget(z, 0);
      } else if (x.s >= y.s) {
        dec += oget(y, 1);
        dec -= oget(y, 0);
      } else if (x.s >= y.f) {
        pii z = mp(y.f, x.s);
        dec += oget(z, 1);
        dec -= oget(z, 0);
      }
      // if (dec < 0) cout << mp(x, y) << " " << dec << endl;
      ans = max(ans, sum-dec);
    }
  }
  cout << ans << endl;
}