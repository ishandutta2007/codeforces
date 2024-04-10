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
 
ll n, q, Q, T, m, k, r, y, z, g;
ll b, w;
vector<pii> bl, wh;
set<pii> s;
const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

//0 - white, 1 - black
bool col(int r, int c) {
  return (r + c) % 2;
}

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> b >> w;
    bl.clear();
    wh.clear();
    s.clear();
    bool f = 1;
    int c = 500000000, r = 999999999;
    if (b > w) {
      if (col(r, c)) r--;
      while (wh.size() < w) {
        wh.pb(mp(r, c));
        f0r(i, 2) {
          pii p = mp(r + dr[i], c + dc[i]);
          s.insert(p);
        }
        if (wh.size() == 1) s.insert(mp(r + 1, c));
        bl.pb(mp(r - 1, c));
        r -= 2;
      }
      while (s.size() != 0 && bl.size() < b) {
        bl.pb(*s.begin());
        s.erase(s.begin());
      }
      if (wh.size() < w || bl.size() < b) f = 0;
      else f = 1;
    } else {
      if (!col(r, c)) r--;
      while (bl.size() < b) {
        bl.pb(mp(r, c));
        f0r(i, 2) {
          pii p = mp(r + dr[i], c + dc[i]);
          s.insert(p);
        }
        if (bl.size() == 1) s.insert(mp(r + 1, c));
        wh.pb(mp(r - 1, c));
        r -= 2;
      }
      while (s.size() != 0 && wh.size() < w) {
        wh.pb(*s.begin());
        s.erase(s.begin());
      }
      if (wh.size() < w || bl.size() < b) f = 0;
      else f = 1;
    }

    cout << (f ? "YES" : "NO") << endl;
    if (f) {
      for (pii x: bl) cout << x.f << " " << x.s << endl;
      for (pii x: wh) cout << x.f << " " << x.s << endl;
    }
  }
}