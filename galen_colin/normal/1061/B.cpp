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
ll i, j;
const ll mod = 998244353;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
ll a[100003];
string s;
 
int main() {
  io;
  cin >> n >> m;
  f0r(i, n) cin >> a[i];
  sort(a, a+n);
  ll ans = 0;
  if (n == 1) {
    cout << 0<< endl;
    exit(0);
  }
  reverse(a, a+n);
  ll highest = a[0];
  a[n+1] = 0;
  // f0r(i, n) cout << a[i] << " "; cout << endl;
  f1r(i, 1, n+1) {
    if (a[i] >= highest - 1) {
      highest--;
      ans += (a[i-1] - 1);
    } else {
      ans += (a[i-1] - highest);
      highest = a[i];
      ans += highest;
    }
    // cout << ans << " " << highest << endl;
  }
  cout << ans << endl;
}