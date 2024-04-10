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
string s;
ll a[3];
string x = "RGBRGB";

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> n >> k >> s;
    ll ans = 2002;
    int disp = 0;
    f0r(i, n-k+1) { 
      ms(a, 0);     
      disp = 0;
      f1r(j, i, i+k) {
        f0r(y, 3) {
          if (s[j] != x[(y + disp) % 3]) a[y]++;
        }
        disp++;
      }
      ans = min(min(ans, a[0]), min(a[1], a[2]));
      // cout << ans << " ";
    }
    cout << ans << endl;
  }
}