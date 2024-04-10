#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;
#define f0r(a, b) for (int a = 0; a < b; a++)
#define f1r(a, b, c) for (int a = b; a < c; a++)
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
const int sent = 1e8 + 3;
 
ll n, q, Q, T, m, k, r, y, z, g;
struct rect {
  int x[2], y[2];
  rect() {rect(0, 0, 0, 0);};
  rect(int a, int b, int c, int d) {
    x[0] = a;
    x[1] = b;
    y[0] = c;
    y[1] = d;
  };
};

rect rint(rect r1, rect r2) {
  rect x;
  x.x[0] = max(r1.x[0], r2.x[0]);
  x.x[1] = min(r1.x[1], r2.x[1]);
  x.y[0] = max(r1.y[0], r2.y[0]);
  x.y[1] = min(r1.y[1], r2.y[1]);
  if (x.x[0] > x.x[1] || x.y[0] > x.y[1]) return rect(sent, sent, sent, sent);
  else return x;
}

int main() {
  io;
  // freopen("a", "r", stdin);
  cin >> Q;
  f0r(q, Q) {
    cin >> n;
    // cout << "Q " << q << " " << n << endl;
    rect ans(-1e6, 1e6, -1e6, 1e6);
    bool f = 1;
    f0r(i, n) {
      int a, b; bool c[4];
      cin >> a >> b;
      f0r(j, 4) cin >> c[j];
      rect r(-100000, 100000, -100000, 100000);
      if (!c[0]) r.x[0] = a;
      if (!c[1]) r.y[1] = b;
      if (!c[2]) r.x[1] = a;
      if (!c[3]) r.y[0] = b;
      // cout << q << " " << i << " " << n << endl;
      // cout << r.x[0] << " " << r.x[1] << " " << r.y[0] << " " << r.y[1] << endl;
      ans = rint(ans, r);
      if (ans.x[0] == sent) {
        f = 0;
      }
    }
    if (f) {
      cout << 1 << " " << max(-100000, ans.x[0]) << " " << max(-100000, ans.y[0]) << endl;
    } else cout << 0 << endl;
  }
}