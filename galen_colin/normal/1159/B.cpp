#include <bits/stdc++.h>

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
ll i, j;

ll n, q, Q, T, m, k, r, x;
ld a[300002];
pair<ll, ll> b[300002];

int main() {
  io;
  cin >> n;
  f0r(i, n) {
    cin >> a[i];
    b[i] = {a[i], i};
  }
  sort(b, b+n);
  ll ans = 1e12;
  f0r(i, n) {
    ans = min(ans, b[i].f/max(n-1-b[i].s, b[i].s));
  }
  cout << ans << endl;
}