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
pii a[101];

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i].f >> a[i].s;
  cin >> q;
  f0r(i, n) {
    if (a[i].f <= q && q <= a[i].s) break;
  }
  cout << n - i << endl;
}