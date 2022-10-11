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
ll a[200001], sum = 0;
vector<int> s;
 
/* comment */
int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> n >> k;
    f0r(i, n) cin >> a[i];
    sum = 0;
    s.clear();
    f0r(i, n) {
      sum += a[i];
      if (sum % 2 == 1) {
        s.pb(i);
        sum = 0;
      }
    }
    if ((s.size() - k) % 2 == 1 || s.size() < k) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      f1r(i, s.size() - k, s.size() - 1) {
        if (i != s.size() - k) cout << " ";
        cout << s[i] + 1;
      }
      cout << " " << n << endl;
    }
  }
}