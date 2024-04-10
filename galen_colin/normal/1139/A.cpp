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
string s;
ll ans = 0;

int main() {
  io;
  cin >> n >> s;
  f0r(i, n) {
    if ((s[i] - '0') % 2 == 0) ans += (i + 1);
  }
  cout << ans << endl;
}