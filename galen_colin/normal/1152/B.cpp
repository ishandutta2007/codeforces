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
#define prefix(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
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
int x; int ops = 0;
vi ans;

bool check(int x) {
  x++;
  int c = 1;
  while (c < 1e7) {
    if (x == c) return true;
    c *= 2;
  }
  return false;
}

void end() {
  cout << ops << endl;
  for (int i: ans) cout << i << " ";
  exit(0);
}

int main() {
  io;
  cin >> x;
  while(ans.size() < 20) {
    if (check(x)) end();
    int c = 1, op = 0;
    while (c < x) {
      c *= 2; op++;
    }
    ans.pb(op);
    x = x ^ (c - 1);
    ops++;
    if (check(x)) end();
    x++;
    ops++;
  }
  if (check(x)) end();
  assert(0);
}