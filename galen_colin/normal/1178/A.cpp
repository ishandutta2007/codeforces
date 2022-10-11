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
const ll mod = 1000000007;

ll n, q, Q, T, m, k, r, x, y, z, g;
pll a[700001];
vi ans;

int main() {
  io;
  cin >> n;
  f0r(i, n) {cin >> a[i].f; a[i].s = i;}
  ll sum = 0;
  f0r(i, n) sum += a[i].f;
  ll alice = a[0].f, tot = a[0].f;
  ans.pb(1);
  sort(a, a+n);
  int i = 0;
  while (tot < (sum+2)/2 && i < n) {
    if (a[i].f <= alice/2) {
      tot += a[i].f;
      ans.pb(++a[i].s);
    }
    i++;
  }
  if (tot < (sum+2)/2) {
    cout << 0 << endl;
    exit(0);
  }
  cout << ans.size() << endl;
  for (int i: ans) cout << i << " ";
}